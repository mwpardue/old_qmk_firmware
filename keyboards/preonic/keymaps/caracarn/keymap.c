#include QMK_KEYBOARD_H
#include "caracarn.h"
//#include "features/caps_word.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |  OPT | Lowr |  CMD |  NUM |Shift | SPACE|Symbol| Menu | Raise| Func | CTRL |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  ESC_CTL, KC_A,    CTL_S,   ALT_D,   GUI_F,   KC_G,    KC_H,    GUI_J,   ALT_K,   CTL_L,   TD_QUOT, KC_SCLN,
  KC_LGUI, GUI_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    TD_COMH, KC_DOT,  KC_SLSH, GUI_ENT,
  _______, _______, _______, _______, TAB_NUM, CAP_KEY, BSP_SYM, SPC_MAC, _______, MOFUN,   _______, _______
),

[_NUMPAD] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_TAB,  PRVTAB,  KC_UP,   NXTTAB,  KC_WH_U, KC_AT,   KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, TD_MCLN, GUI_4,   ALT_5,   CTL_6,   KC_PDOT, _______,
  _______, SS_SWIN, KC_BTN1, LCTLC,   KC_BTN2, KC_ENT,  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
  _______, _______, _______, _______, TOBAS,   _______, SPCSFT,  KC_0,    _______, KC_PDOT, KC_PENT, _______
),

[_HEX] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_TAB,  _______, _______, _______, KC_MINS, KC_AT,   KC_7,    KC_8,    KC_9,    KC_BSPC, _______,
  _______, _______, KC_SLSH, _______, _______, KC_COLN, TD_MCLN, KC_4,    KC_5,    KC_6,    KC_PDOT, _______,
  _______, _______, KC_UNDS, _______, KC_DOT,  _______, KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
  _______, _______, _______, _______, TOBAS,   SPCSFT,  KC_BSPC, KC_0,    _______, KC_PDOT, KC_PENT, _______
),

[_SYMBOL] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_GESC, KC_GRV,  KC_TILDE,KC_BSLS, KC_TAB,  KC_AT,   KC_AMPR, KC_ASTR, KC_LPRN, KC_PSLS, _______,
  _______, KC_AT,   TIPS,    KC_UNDS, KC_PIPE, TD_SCLE, TD_MCLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PDOT, _______,
  _______, TD_ANGB, TD_CURB, TD_PARB, TD_SQRB, KC_MINS, KC_EQL,  KC_EXLM, KC_AT,   KC_HASH, KC_ENT,  _______,
  _______, _______, _______, _______, _______, SPCSFT,  _______, KC_RPRN, _______, _______, _______, _______
),

[_MACROS] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_ESC,  _______, _______, _______, _______, _______, SS_SWIN, SS_SELW, SS_MODM, SS_MODP, _______,
  _______, _______, _______, _______, FOPEN,   _______, KC_COLN, KC_S1,   KC_S2,   KC_S3,   KC_S4,   _______,
  _______, _______, _______, _______, _______, _______, _______, SS3,     SS4,     _______, KC_ENT,  _______,
  _______, _______, _______, _______, SPCSFT,  KC_LSFT, TOBAS,   TOMAC,   _______, _______, _______, _______
),

[_FUNCTION] = LAYOUT_ortho_5x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,\
  _______, RESET,   _______, DEBUG,   EEP_RST, TERM_OFF, TERM_ON, DT_PRNT, _______, _______, _______, _______,  \
  _______, KC_VOLU, MACSLEP, _______, TOFUN,   AG_NORM,  AG_SWAP, DT_UP,   TG_LIN,  TG_MAC,  TG_WIN,  _______,\
  _______, KC_VOLD, KC_MPLY, _______, _______, _______,  _______, DT_DOWN, _______, _______, _______, _______,\
  _______, KC_MPRV, KC_MNXT, TOHEX,   TONUM,   TOFUN,    TOSYM,   TOMAC,   TOBAS,   _______, MACSLEP, _______  \
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
