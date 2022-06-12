#include QMK_KEYBOARD_H

#include "keycodes.h"

uint16_t extract_base_tapping_keycode(uint16_t keycode) {
    // Get the base tapping keycode of a mod- or layer-tap key.
    return keycode &= 0xff;
}

#ifdef SMART_CASE_ENABLE
bool is_key_on_tap(uint16_t keycode) {
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return true;
    }
    if ((keycode > CUSTOM_KEYCODE_START && keycode < CUSTOM_KEYCODE_END)) {
        return true;
    }
    keycode = extract_base_tapping_keycode(keycode);
    if (IS_KEY(keycode)) {
        return true;
    }
    return false;
}

#endif
