#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _NUMPAD 1
#define _SYMBOL 2
#define _NAVIGATION 3
#define _MACRO 4
#define _FUNCTION 5

enum custom_keycodes {
    DDS = SAFE_RANGE,
    TIPS,
    BAS,
    NUM,
    SYM,
    NAV,
    MAC,
    FUN,
    LOWER,
    RAISE,
    NUMENT,
    SYMBKS,
    NAVSPC,
    MACTAB,
    FUNC,
    TOBAS,
    TONUM,
    TONAV,
    TOSYM,
    TOMAC,
    SS3,
    SS4,
    SS3CB,
    SS4CB,
    LCTLC,
    QUIT,
    CLTAB,
    SELALL,
    FIND,
    UNDO,
    CUT,
    COPY,
    PASTE
};

// Macro name shortcuts
#define BAS _BASE
#define NUM _NUMPAD
#define SYM _SYMBOL
#define NAV _NAVIGATION
#define MAC _MACRO
#define FUN _FUNCTION
#define LOWER TG(_BASE)
#define RAISE TG(_MACRO)
#define NUMENT LT(_NUMPAD, KC_ENTER)
#define SYMBKS LT(_SYMBOL, KC_BSPC)
#define NAVSPC LT(_NAVIGATION, KC_SPC)
#define MACTAB LT(_MACRO, KC_TAB)
#define FUNC MO(_FUNCTION)
#define TOBAS TO(_BASE)
#define TONUM TO(_NUMPAD)
#define TOSYM TO(_SYMBOL)
#define TONAV TO(_NAVIGATION)
#define TOMAC TO(_MACRO)
#define SS3 LSG(KC_3)
#define SS4 LSG(KC_4)
#define SS3CB LGUI(LCTL(LSFT(KC_3)))
#define SS4CB LGUI(LCTL(LSFT(KC_4)))
#define LCTLC LCTL(KC_C)
#define QUIT LGUI(KC_Q)
#define CLTAB LGUI(KC_W)
#define SELALL LGUI(KC_A)
#define SAVE LGUI(KC_S)
#define FIND LGUI(KC_F)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TIPS:
        if (record->event.pressed) {
            // when keycode TIPS is pressed
            SEND_STRING("trueipsolutions.com");
        } else {
            // when keycode TIPS is released
        }
        break;

    case DDS:
        if (record->event.pressed) {
            // when keycode DDS is pressed
            SEND_STRING("../");
        } else {
            // when keycode DDS is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |  OPT |  CMD | Lowr | Enter| BSPC | Space|  Tab | Raise|  FN  |  OPT | CTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x12(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_LCTL, KC_LOPT, KC_LCMD, LOWER,   NUMENT,  SYMBKS,  NAVSPC,  MACTAB,  RAISE,   FUNC,    KC_ROPT, KC_RCTL
),


/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | Base |      |      |      |      |      |      | NUM  |  \   |  *   |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | CMSH3| CMSH4|      |      |   7  |   8  |  9   |   +  |  DEL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | CTRL | OPT  | CMD  |SHIFT |      |      |   4  |   5  |  6   |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |CM^SH3|CM^SH4|      |      |   1  |   2  |  3   | Enter|  DEL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |******| BSPC |      |   0  |      |  .   | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, _______, _______, SS3,     SS4,     _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_DEL,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, _______,
  KC_CAPS, _______, KC_X,    SS3CB,   SS4CB,   _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_DEL,
  _______, _______, KC_LCMD, LOWER,   _______, KC_BSPC, _______, KC_P0,   _______, KC_PDOT, KC_PENT, _______
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   .  |  "   |   {  |   }  |   /  |   \  |   &  |   *  |   (  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   @  |  $   |   (  |   )  | TIPS |   :  |   $  |   %  |   ^  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   <  |  +   |   [  |   ]  |  ../ |   ?  |   !  |   @  |   #  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |******|      |   )  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_DOT,  KC_DQUO, KC_LCBR, KC_RCBR, KC_SLSH, KC_BSLS, KC_AMPR, KC_ASTR, KC_LPRN, KC_PLUS, _______,
  _______, KC_AT,   KC_DLR,  KC_LPRN, KC_RPRN, TIPS,    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS, _______,
  _______, KC_LT,   KC_PLUS, KC_LBRC, KC_RBRC, DDS,     KC_QUES, KC_EXLM, KC_AT,   KC_HASH, KC_EQL,  _______,
  _______, _______, _______, _______, _______, _______, _______, KC_RPRN, _______, _______, _______, _______
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |TabSW | MBtn1|ScrDwn|ScrUp | MBtn2| BSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | CTRL | OPT  | CMD  | SHIFT|      |AppSW | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  ^C  |      |      |WndwSW|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  DEL |******|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* Add Tab, App, and Window switcher macros */

[_NAVIGATION] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_WH_D, KC_WH_U, KC_BTN2, KC_BSPC,
  _______, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, _______, _______, LCTLC,   _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______
),
/* Macro
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | QUIT |CL TAB|CMDSFT|CM^SHF|      |      |  F7  |  F8  |  F9  | F10  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |SELALL| SAVE |      | FIND |      |      |  F4  |  F5  |  F6  | F11  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|      |      |  F1  |  F2  |  F3  | F12  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | BSPC |      |******|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_MACRO] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, QUIT,    CLTAB,   _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  _______, SELALL,  SAVE,    _______, FIND,    _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
  _______, UNDO,    CUT,     COPY,    PASTE,   _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
  _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      | Sleep|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|EEPROM|      |      |      |TrmOff|TermOn|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |AudCyc|AudOff|Aud On|AGNorm|AGSwap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Vol Up|      |      |MusOff|Mus On|MIDOff|MIDIOn|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |VolDwn|Trk Bk|PlyPau|Trk FW|TO NUM|TO SYM|TO NAV|TO MAC|      |******|      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_FUNCTION] = LAYOUT_ortho_5x12( \
  TOBAS,   _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_SLEP, \
  _______, RESET,   DEBUG,   EEP_RST, _______, _______, _______, TERM_OFF, TERM_ON, _______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_OFF,  AU_ON,   AG_NORM, AG_SWAP, _______,  _______, _______, _______, _______, \
  KC_VOLU, _______, _______, MU_OFF,  MU_ON,   MI_OFF,  MI_ON,   _______,  _______, _______, _______, _______, \
  KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, TONUM,   TOSYM,   TONAV,   TOMAC,    _______, _______, _______, _______  \
)


};

/* Check https://github.com/rafaelromao/keyboards/blob/main/src/qmk/users/rafaelromao/features/tapdance.h
   for inspiration on double braces/brackets/parentheses.
    case DBLPRN:
        if (record->event.pressed) {
            // when keycode DBLPRN is pressed
            SEND_STRING("()");
            tap_code(KC_LEFT);
        } else {
            // when keycode DBLPRN is released
        }
        break;

case DBLBRK:
        if (record->event.pressed) {
            // when keycode DBLBRK is pressed
            SEND_STRING("[]");
            tap_code(KC_LEFT);
        } else {
            // when keycode DBLBRK is released
        }
        break;

case DBLBRC:
        if (record->event.pressed) {
            // when keycode DBLBRC is pressed
            SEND_STRING("{}");
            tap_code(KC_LEFT);
        } else {
            // when keycode DBLBRC is released
        }
        break;
    }
    return true;
}; */

/* void matrix_init_user(void) {
  #ifdef AUDIO_ENABLE
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(start_up);
  #endif
}

#ifdef AUDIO_ENABLE

void play_goodbye_tone(void)
{
  PLAY_SONG(goodbye);
  _delay_ms(150);
}

#endif */
