"""This script handles the XAP protocol data files.
"""
import os
import hjson
import jsonschema
from pathlib import Path
from typing import OrderedDict
from jinja2 import Environment, FileSystemLoader, select_autoescape

from qmk.constants import QMK_FIRMWARE
from qmk.json_schema import json_load, validate
from qmk.decorators import lru_cache
from qmk.keymap import locate_keymap
from qmk.path import keyboard

XAP_SPEC = 'xap.hjson'


def _get_jinja2_env(data_templates_xap_subdir: str):
    templates_dir = os.path.join(QMK_FIRMWARE, 'data', 'templates', 'xap', data_templates_xap_subdir)
    j2 = Environment(loader=FileSystemLoader(templates_dir), autoescape=select_autoescape())
    return j2


def render_xap_output(data_templates_xap_subdir, file_to_render, defs):
    j2 = _get_jinja2_env(data_templates_xap_subdir)
    return j2.get_template(file_to_render).render(xap=defs, xap_str=hjson.dumps(defs))


def _find_kb_spec(kb):
    base_path = Path('keyboards')
    keyboard_parent = keyboard(kb)

    for _ in range(5):
        if keyboard_parent == base_path:
            break

        spec = keyboard_parent / XAP_SPEC
        if spec.exists():
            return spec

        keyboard_parent = keyboard_parent.parent

    # Just return something we know doesn't exist
    return keyboard(kb) / XAP_SPEC


def _find_km_spec(kb, km):
    return locate_keymap(kb, km).parent / XAP_SPEC


def _merge_ordered_dicts(dicts):
    """Merges nested OrderedDict objects resulting from reading a hjson file.

    Later input dicts overrides earlier dicts for plain values.
    Arrays will be appended. If the first entry of an array is "!reset!", the contents of the array will be cleared and replaced with RHS.
    Dictionaries will be recursively merged. If any entry is "!reset!", the contents of the dictionary will be cleared and replaced with RHS.
    """

    result = OrderedDict()

    def add_entry(target, k, v):
        if k in target and isinstance(v, (OrderedDict, dict)):
            if "!reset!" in v:
                target[k] = v
            else:
                target[k] = _merge_ordered_dicts([target[k], v])
            if "!reset!" in target[k]:
                del target[k]["!reset!"]
        elif k in target and isinstance(v, list):
            if v[0] == '!reset!':
                target[k] = v[1:]
            else:
                target[k] = target[k] + v
        else:
            target[k] = v

    for d in dicts:
        for (k, v) in d.items():
            add_entry(result, k, v)

    return result


def get_xap_definition_files():
    """Get the sorted list of XAP definition files, from <QMK>/data/xap.
    """
    xap_defs = QMK_FIRMWARE / "data" / "xap"
    return list(sorted(xap_defs.glob('**/xap_*.hjson')))


def update_xap_definitions(original, new):
    """Creates a new XAP definition object based on an original and the new supplied object.

    Both inputs must be of type OrderedDict.
    Later input dicts overrides earlier dicts for plain values.
    Arrays will be appended. If the first entry of an array is "!reset!", the contents of the array will be cleared and replaced with RHS.
    Dictionaries will be recursively merged. If any entry is "!reset!", the contents of the dictionary will be cleared and replaced with RHS.
    """
    if original is None:
        original = OrderedDict()
    return _merge_ordered_dicts([original, new])


@lru_cache(timeout=5)
def get_xap_defs(version):
    """Gets the required version of the XAP definitions.
    """
    files = get_xap_definition_files()

    # Slice off anything newer than specified version
    if version != 'latest':
        index = [idx for idx, s in enumerate(files) if version in str(s)][0]
        files = files[:(index + 1)]

    definitions = [hjson.load(file.open(encoding='utf-8')) for file in files]
    return _merge_ordered_dicts(definitions)


def latest_xap_defs():
    """Gets the latest version of the XAP definitions.
    """
    return get_xap_defs('latest')


def merge_xap_defs(kb, km):
    """Gets the latest version of the XAP definitions and merges in optional keyboard/keymap specs
    """
    definitions = [get_xap_defs('latest')]

    kb_xap = _find_kb_spec(kb)
    if kb_xap.exists():
        definitions.append({'routes': {'0x02': hjson.load(kb_xap.open(encoding='utf-8'))}})

    km_xap = _find_km_spec(kb, km)
    if km_xap.exists():
        definitions.append({'routes': {'0x03': hjson.load(km_xap.open(encoding='utf-8'))}})

    defs = _merge_ordered_dicts(definitions)

    try:
        validate(defs, 'qmk.xap.v1')

    except jsonschema.ValidationError as e:
        print(f'Invalid XAP spec: {e.message}')
        exit(1)

    return defs


@lru_cache(timeout=5)
def get_xap_keycodes(xap_version):
    """Gets keycode data for the required version of the XAP definitions.
    """
    defs = get_xap_defs(xap_version)

    # Load DD keycodes for the dependency
    keycode_version = defs['uses']['keycodes']
    spec = json_load(Path(f'data/constants/keycodes_{keycode_version}.json'))

    # Transform into something more usable - { raw_value : first alias || keycode }
    return {int(k, 16): v.get('aliases', [v.get('key')])[0] for k, v in spec['keycodes'].items()}


def route_conditions(route_stack):
    """Handles building the C preprocessor conditional based on the current route.
    """
    conditions = []
    for route in route_stack:
        if 'enable_if_preprocessor' in route:
            conditions.append(route['enable_if_preprocessor'])

    if len(conditions) == 0:
        return None

    return "(" + ' && '.join([f'({c})' for c in conditions]) + ")"
