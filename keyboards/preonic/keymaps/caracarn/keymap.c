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
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  GUI_A,   CTL_S,   ALT_D,   GUI_F,   KC_G,    KC_BSPC, KC_SCLN, KC_H,    GUI_J,   ALT_K,   CTL_L,   TD_QUOT,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT, KC_RSFT, KC_N,    KC_M,    TD_COMH, KC_DOT,  KC_SLSH,
  KC_LCTL, KC_LOPT, MOD_CTL, TAB_NUM, CAP_KEY, MOD_CTL, TAB_HYP, BSP_SYM, SPC_MAC, KC_ENT,  MOFUNC,  KC_RCTL
),

[_NUMPAD] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, KC_NUM,  _______, _______, _______,
  KC_TAB,  PRVTAB,  KC_UP,   NXTTAB,  KC_WH_U, _______, _______, KC_AT,   KC_7,    KC_8,    KC_9,    KC_PSLS,
  KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D, _______, _______, TD_MCLN, KC_4,    KC_5,    KC_6,    KC_PDOT,
  SS_SWIN, KC_BTN1, LCTLC,   KC_BTN2, KC_ENT,  _______, _______, KC_EQL,  KC_1,    KC_2,    KC_3,    KC_ENT,
  _______, _______, _______, TOBAS,   _______, _______, _______, SPCSFT,  KC_0,    _______, KC_PDOT, KC_PENT
),

[_HEX] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, KC_NUM,  _______, _______, _______,
  KC_TAB,  _______, _______, _______, KC_MINS, _______, _______, KC_AT,   KC_7,    KC_8,    KC_9,    KC_BSPC,
  _______, KC_SLSH, _______, _______, KC_COLN, _______, _______, TD_MCLN, KC_4,    KC_5,    KC_6,    KC_PDOT,
  _______, KC_UNDS, _______, KC_DOT,  _______, _______, _______, KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,
  _______, _______, _______, TOBAS,   SPCSFT,  _______, _______, KC_BSPC, KC_0,    _______, KC_PDOT, KC_PENT
),

[_SYMBOL] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, KC_NUM,  _______, _______, _______,
  KC_BSPC, KC_GRV,  KC_TILDE,KC_BSLS, KC_TAB,  _______, _______, KC_AT,   KC_AMPR, KC_ASTR, KC_LPRN, KC_PSLS,
  KC_AT,   TIPS,    KC_PIPE, KC_UNDS, TD_SCLE, _______, _______, TD_MCLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PDOT,
  TD_ANGB, TD_CURB, TD_PARB, TD_SQRB, _______, _______, _______, KC_EQL,  KC_EXLM, KC_AT,   KC_HASH, KC_ENT,
  _______, _______, _______, _______, SPCSFT,  _______, _______, _______, KC_RPRN, _______, _______, _______
),

 [_NAVIGATION] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_UP,   KC_BTN2, KC_BSPC,
  OSMLCTL, OSMLALT, OSMLGUI, OSMLSFT, _______, _______, _______, KC_WH_D, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, TOBAS,   TONAV,   _______, _______, SPCSFT,   _______, _______, _______, _______
),

[_MACROS] = LAYOUT_ortho_5x12(
  TOBAS,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  SS_SWIN, SS_SELW, SS_MODM, SS_MODP, _______, _______, _______, _______, SS_SWIN, SS_SELW, SS_MODM, SS_MODP,
  KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, _______, _______, _______, KC_S1,   KC_S2,   KC_S3,   KC_S4,
  _______, _______, SS3,     SS4,     _______, _______, _______, _______, SS3,     SS4,     _______, KC_ENT,
  _______, _______, _______, SPCSFT,  KC_LSFT, _______, _______, TOBAS,   TOMAC,   _______, _______, _______
),

[_FUNCTION] = LAYOUT_ortho_5x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  RESET,   _______, DEBUG,   EEP_RST, _______, TERM_OFF, TERM_ON, _______, DT_PRNT, _______, _______, _______,  \
  KC_VOLU, _______, MU_MOD,  AU_OFF,  AU_ON,   AG_NORM, AG_SWAP, _______,  DT_UP,   TG_LIN,  TG_MAC,  TG_WIN, \
  KC_VOLD, KC_MPLY, _______, MU_OFF,  MU_ON,   MI_OFF,  MI_ON,   _______,  DT_DOWN, _______, _______, _______, \
  KC_MPRV, KC_MNXT, TOHEX,   TONUM,   TOMAC,   _______, _______, TONAV,    TOSYM,   TOBAS,   _______, MACSLEP  \
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
