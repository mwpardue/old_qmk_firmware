#include QMK_KEYBOARD_H
#include "features/caps_word.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _NUMPAD 1
#define _SYMBOL 2
#define _MOUSE 3
#define _FUNCTION 4

enum custom_keycodes {
    DDS = SAFE_RANGE,
    TIPS,
    BAS,
    NUM,
    SYM,
    MSE,
    FUN,
    LOWER,
    RAISE,
    SYMBOL,
    MOUSE,
    NUMSPAC,
    SYMENT,
    FUNC,
    TOBAS,
    TONUM,
    TOSYM,
    TOMSE,
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
    PASTE,
    PRVTAB,
    NXTTAB
};

// Macro name shortcuts
#define BAS _BASE
#define NUM _NUMPAD
#define SYM _SYMBOL
#define NAV _NAVIGATION
#define MSE _MOUSE
#define FUN _FUNCTION
#define LOWER TG(_BASE)
#define RAISE TG(MOUSE)
#define NUMSPAC LT(_NUMPAD, KC_SPC)
#define SYMENT LT(_SYMBOL, KC_ENT)
#define MOMSE MO(_MOUSE)
#define MOSYM MO(_SYMBOL)
#define MOFUNC MO(_FUNCTION)
#define TOBAS TO(_BASE)
#define TONUM TO(_NUMPAD)
#define TOSYM TO(_SYMBOL)
#define TONAV TO(_NAVIGATION)
#define TOMSE TO(_MOUSE)
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
#define PRVTAB LCTL(LSFT(KC_TAB))
#define NXTTAB LCTL(KC_TAB)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
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
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BSPC |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |  OPT | Lowr |  CMD | Mouse| Space/Numpad|Symbol| Menu | Raise| Func | CTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_preonic_1x2uC(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  KC_LCTL, KC_LOPT, LOWER,   KC_LCMD, MOMSE,       NUMSPAC,      SYMENT,   KC_LEAD, RAISE,   MOFUNC,  KC_RCTL
),


/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      | SS3  |  SS4 |      |      |  NUM |  \   |  *   |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |PrvTab|  Up  |NxtTab|TabSw |      |   7  |   8  |  9   |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down |Right |AppSw |      |   4  |   5  |  6   |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  ^C  |      |WndwSW|      |   1  |   2  |  3   | Enter|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Shift |*************|   0  |      |  .   | Enter|      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_1x2uC(
  TOBAS,   _______, _______, SS3,     SS4,     _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, _______, PRVTAB,  KC_UP,   NXTTAB,  _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, _______,
  _______, _______, _______, LCTLC,   _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
  _______, _______, _______, _______, KC_LSFT,      _______,     KC_P0,   _______, KC_PDOT, KC_PENT, _______
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   .  |  "   |   {  |   }  |   /  |   \  |   &  |   *  |   (  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   @  |  $   |   (  |   )  | TIPS |   |  |   $  |   %  |   ^  |   -  |  :   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   <  |  +   |   [  |   ]  |  ../ |   _  |   !  |   @  |   #  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |******|   )  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_preonic_1x2uC(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_DOT,  KC_DQUO, KC_LCBR, KC_RCBR, KC_SLSH, KC_BSLS, KC_AMPR, KC_ASTR, KC_LPRN, KC_PLUS, _______,
  _______, KC_AT,   KC_DLR,  KC_LPRN, KC_RPRN, TIPS,    KC_PIPE, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS, KC_COLN,
  _______, KC_LT,   KC_PLUS, KC_LBRC, KC_RBRC, DDS,     KC_QUES, KC_EXLM, KC_AT,   KC_HASH, KC_EQL,  _______,
  _______, _______, _______, _______, _______,       _______,    _______, KC_RPRN, _______, _______, _______
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |PrvTab|  Up  |NxtTab|TabSw |      |MBtn1 |ScrUp |MBtn2 |      | BSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down |Right |AppSw |      |ScrLft|ScrDwn|ScrRt |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  ^C  |      |WndwSW|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Shift |******|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* Add Tab, App, and Window switcher macros */

/* [_NAVIGATION] = LAYOUT_preonic_1x2uC(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, PRVTAB,  KC_UP,   NXTTAB,  _______, _______, KC_BTN1, KC_WH_U, KC_BTN2, _______, KC_BSPC,
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
  _______, _______, _______, LCTLC,   _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______
), */
/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * | BASE |      |      |SS3CB |SS4CB |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | QUIT |CL TAB|CMDSFT|CM^SHF|      |      |MBtn1 |ScrUp |MBtn2 |      | BSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |SELALL| SAVE |      | FIND |      |      |ScrLft|ScrDwn|ScrRt |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | UNDO | CUT  | COPY | PASTE|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |******|             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_MOUSE] = LAYOUT_preonic_1x2uC(
  TOBAS,   _______, _______, SS3CB,   SS4CB,   _______, _______, _______, _______, _______, _______, _______,
  _______, QUIT,    CLTAB,   PRVTAB,  NXTTAB,  _______, _______, KC_BTN1, KC_WH_U, KC_BTN2, _______, KC_BSPC,
  KC_CAPS, SELALL,  SAVE,    _______, FIND,    _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
  _______, UNDO,    CUT,     COPY,    PASTE,   _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|EEPROM|      |      |      |TrmOff|TermOn|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |AudCyc|AudOff|Aud On|AGNorm|AGSwap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Vol Up|      |      |MusOff|Mus On|MIDOff|MIDIOn|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |VolDwn|Trk Bk|PlyPau|Trk FW|TO MAC|    TO NUM   |TO SYM|TOBASE|******|      | Sleep|
 * `-----------------------------------------------------------------------------------'
 */

[_FUNCTION] = LAYOUT_preonic_1x2uC( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, RESET,   DEBUG,   EEP_RST, _______, _______, _______, TERM_OFF, TERM_ON, _______, _______, _______,  \
  _______, _______, MU_MOD,  AU_OFF,  AU_ON,   AG_NORM, AG_SWAP, _______,  _______, _______, _______, _______, \
  KC_VOLU, _______, _______, MU_OFF,  MU_ON,   MI_OFF,  MI_ON,   _______,  _______, _______, _______, _______, \
  KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, TOMSE,       TONUM,        TOSYM,    TOBAS,   _______, _______, KC_SLEP  \
)


};

enum combo_events {
  DBL_PAREN,
  DBL_BRACK,
  DBL_CBRAC,
  CAPS_COMBO,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM paren_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM cbrac_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM brack_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_F, KC_J, COMBO_END};

combo_t key_combos[] = {
  [DBL_PAREN] = COMBO_ACTION(paren_combo),
  [DBL_BRACK] = COMBO_ACTION(cbrac_combo),
  [DBL_CBRAC] = COMBO_ACTION(brack_combo),
  [CAPS_COMBO] = COMBO_ACTION(caps_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case DBL_PAREN:
      if (pressed) {
        SEND_STRING("()");
        tap_code16(KC_LEFT);
      }
      break;
    case DBL_BRACK:
      if (pressed) {
        SEND_STRING("[]");
        tap_code16(KC_LEFT);
      }
      break;
    case DBL_CBRAC:
      if (pressed) {
        SEND_STRING("{}");
        tap_code16(KC_LEFT);
      }
      break;
    case CAPS_COMBO:
      if (pressed) {
        caps_word_set(true);  // Activate Caps Word!
      }
      break;
  }
}

/* LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_LPRN) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
//        SEND_STRING("()");
        tap_code(KC_LEFT);
    }
  }
} */

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
