#include QMK_KEYBOARD_H
#include "caracarn.h"
//#include "features/caps_word.h"

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  ESC_CTL, KC_A,    CTL_S,   ALT_D,   GUI_F,   KC_G,                         KC_H,    GUI_J,   ALT_K,   CTL_L,   TD_QUOT, KC_SCLN,
  KC_LGUI, GUI_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    TD_COMH, KC_DOT,  KC_SLSH, GUI_ENT,
                                      TOHEX,   TAB_NUM, CAP_KEY,    BSP_SYM, SPC_MAC, ENT_FUN
),

[_NUMPAD] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  PRVTAB,  KC_UP,   NXTTAB,  _______,                      KC_AT,   KC_7,    KC_8,    KC_9,    KC_PSLS, _______,
  _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______,                      TD_MCLN, GUI_4,   ALT_5,   CTL_6,   KC_PDOT, _______,
  _______, _______, _______, LCTLC,   _______, KC_ENT,                       KC_EQL,  KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      _______, TOBAS,   _______,    SPCSFT,  KC_0,    _______
),

[_HEX] = LAYOUT_split_3x6_3(
  _______, KC_TAB,  _______, _______, _______, KC_MINS,                      KC_AT,   KC_7,    KC_8,    KC_9,    KC_BSPC, _______,
  _______, _______, KC_SLSH, _______, _______, KC_COLN,                      TD_MCLN, KC_4,    KC_5,    KC_6,    KC_PDOT, _______,
  _______, _______, KC_UNDS, _______, KC_DOT,  _______,                      KC_UNDS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                      TOBAS,   TOBAS,   SPCSFT,     KC_BSPC, KC_0,    _______
),

[_SYMBOL] = LAYOUT_split_3x6_3(
  _______, KC_ESC,  KC_GRV,  KC_TILDE,KC_BSLS, KC_TAB,                       KC_AT,   KC_AMPR, KC_ASTR, KC_LPRN, KC_PSLS, _______,
  _______, KC_AT,   TIPS,    KC_UNDS, KC_PIPE, TD_SCLE,                      TD_MCLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PDOT, _______,
  _______, TD_ANGB, TD_CURB, TD_PARB, TD_SQRB, KC_MINS,                      KC_EQL,  KC_EXLM, KC_AT,   KC_HASH, KC_ENT,  _______,
                                      _______, TOBAS,   SPCSFT,     _______, KC_RPRN, _______
),

[_MACROS] = LAYOUT_split_3x6_3(
  _______, KC_ESC,  _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, FOPEN,   _______,                      KC_COLN, KC_S1,   KC_S2,   KC_S3,   KC_S4,   _______,
  _______, _______, _______, _______, _______, _______,                      _______, SS3,     SS4,     _______, KC_ENT,  _______,
                                      _______, SPCSFT,  KC_LSFT,    TOBAS,   TOMAC,   _______
),

[_FUNCTION] = LAYOUT_split_3x6_3( \
  _______, RESET,   _______, DEBUG,   EEP_RST, TERM_OFF,                     TERM_ON, _______, _______, _______, _______, _______,  \
  _______, KC_VOLU, MACSLEP, _______, TOFUN,   AG_NORM,                      AG_SWAP, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,\
  _______, KC_VOLD, KC_MPLY, KC_MPRV, KC_MNXT, _______,                      MACSLEP, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,\
                                      TOHEX,   TONUM,   TOFUN,      TOSYM,   TOMAC,   TOBAS \
)


};
