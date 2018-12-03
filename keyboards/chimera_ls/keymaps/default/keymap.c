// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_lets_split_layers
{
	_QWERTY,
	_CAPS,
	_NUMPAD,
	_SYMBOLS,
	_MACROS,
	_NAV
};

#define KC_NMPD TG(_NUMPAD)
#define KC_SYMB TG(_SYMBOLS)
#define KC_SPFN LT(_NAV,KC_EQL)
#define KC_SCTL MT(MOD_LCTL, KC_BSLS)
#define KC_SCTR MT(MOD_LCTL, KC_RBRC)
#define KC_SPLT MT(MOD_LALT, KC_MINS)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_CAD LALT(LCTL(KC_DEL))

enum custom_keycodes {
  KC_INCL = SAFE_RANGE,
  KC_PULL,
  KC_PUSH,
  KC_SCAP,
  KC_SCOF
};

#define LONGPRESS_DELAY 150
//#define LAYER_TOGGLE_DELAY 300

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     KC_MESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_SCTL, KC_SPFN, KC_SPLT, KC_AMPR, KC_NMPD, KC_SPC,       KC_SPC,  KC_SYMB, KC_ASTR, KC_EXLM, KC_LBRC, KC_SCTR
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),

  [_CAPS] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, KC_COLN, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, KC_UNDS, _______, _______, _______,      _______, _______, _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),


  [_NUMPAD] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     _______, _______, _______, _______, _______, _______,      _______, KC_7,    KC_8,    KC_9,    KC_MINS, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      _______, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, _______, _______, _______, _______, _______,      _______, KC_1,    KC_2,    KC_3,    KC_ASTR, KC_EQL,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, KC_BSPC,      KC_SPC,  KC_0,    KC_0,    KC_DOT,  KC_SLSH, _______
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),

  [_SYMBOLS] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_TILD, KC_EQL,  KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_GRV,  KC_PLUS, KC_MINS, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, XXXXXXX, KC_BSPC,      KC_SPC,  _______, _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),

  [_NAV] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     _______, _______, _______, _______, KC_DEL,  KC_BSPC,      _______, KC_HOME, KC_UP,   KC_END,  KC_INS,  KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, KC_LSFT, KC_LCTL, KC_ENT,       _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      _______, KC_PGUP, KC_PGDN, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, KC_DEL,       _______, _______, _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),

  [_MACROS] = LAYOUT_ortho_4x12(
  //,--------+--------+--------+--------+--------+--------.    ,--------+--------+--------+--------+--------+--------.
     _______, _______, _______, _______, _______, _______,      _______, _______, KC_INCL, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, KC_CAD,  _______, _______,      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     KC_SCAP, _______, _______, _______, _______, _______,      _______, _______, KC_PULL, KC_PUSH, _______, KC_SCAP,
  //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------'    `--------+--------+--------+--------+--------+--------'
  ),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    /* include some kind of library or header */
    case KC_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>" SS_TAP(X_LEFT) );
        return false;
      }
      break;
    case KC_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull" SS_TAP(X_ENTER) );
        return false;
      }
      break;
    case KC_PUSH:
      if (record->event.pressed){
        SEND_STRING("git push" SS_TAP(X_ENTER) );
        return false;
      }
      break;
    case KC_SCAP:
      if (record->event.pressed){
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
        return false;
      }
      break;
    case KC_SCOF:
      if (record->event.pressed){
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
        return false;
      }
      break;
  }
  return true;
};


void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  switch (layer) {
    case _QWERTY:
      set_led_green;
      break;
    case _CAPS:
      set_led_white;
      break;
    case _NUMPAD:
      set_led_blue;
      break;
    case _SYMBOLS:
      set_led_red;
      break;
    case _NAV:
      set_led_magenta;
      break;
    case _MACROS:
      set_led_cyan;
      break;
    default:
      set_led_green;
      break;
  }
};
