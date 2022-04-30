#pragma once

#include "layers.h"

// Custom keycodes

enum {
    DDS = SAFE_RANGE,
    TIPS,
    FOPEN,
    ALT_TAB,

    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    KC_SECRET_4,

    SS_BTIC, SS_DQUO, SS_SQUO,
    SS_CIRC, SS_TILD, SS_DEG,

    TG_MAC, TG_WIN, TG_LIN,

    MOU_TG, MOU_ON, MOU_OFF,

    SP_CAP, SP_MOD, DEF_MOD, CAP_KEY,

    SS_MODP, SS_MODM,

    SS_SELW, SS_SWIN, SS_CAPS
};

// Mod-taps

// One-shot mods

//#define OSMLSFT OSM(MOD_LSFT)
//#define OSMLCTL OSM(MOD_LCTL)
//#define OSMLALT OSM(MOD_LALT)
//#define OSMRALT OSM(MOD_RALT)
//#define OSMLGUI OSM(MOD_LGUI)
//#define OSMRSFT OSM(MOD_RSFT)
//#define OSMRCTL OSM(MOD_RCTL)
//#define OSMRGUI OSM(MOD_RGUI)
//#define OSMHYPR OSM(MOD_HYPR)

// Left-hand home row mods
#define GUI_Z LGUI_T(KC_Z)
#define CTL_S LCTL_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

// // Right-hand home row mods
#define GUI_J RGUI_T(KC_J)
#define ALT_K RALT_T(KC_K)
#define CTL_L RCTL_T(KC_L)
#define GUI_4 RGUI_T(KC_4)
#define ALT_5 RALT_T(KC_5)
#define CTL_6 RCTL_T(KC_6)

// Layer-taps

#define MOD_MAC LT(_MACROS, SP_MOD)
#define MOD_CTL LCTL_T(SP_MOD)
#define TAB_HYP HYPR_T(KC_TAB)
#define SPC_MAC LT(_MACROS, KC_SPC)
#define BSP_SYM LT(_SYMBOL, KC_BSPC)
#define SYMENT LT(_SYMBOL, KC_ENT)
#define TAB_NUM LT(_NUMPAD, KC_TAB)
#define CAP_KEY LSFT_T(SP_CAP)

// Layer transitions

#define RAISE TG(_MACROS)
#define MONUM MO(_NUMPAD)
#define MOSYM MO(_SYMBOL)
#define MOFUN MO(_FUNCTION)
#define TOBAS TO(_BASE)
#define TONUM TO(_NUMPAD)
#define TOSYM TO(_SYMBOL)
#define TOMAC TO(_MACROS)
#define TOHEX TO(_HEX)
#define TOFUN TO(_FUNCTION)

// Custom Shortcuts

#define SS3 LGUI(LSFT(KC_3))
#define SS4 LGUI(LSFT(KC_4))
#define SS3CB LGUI(LCTL(LSFT(KC_3)))
#define SS4CB LGUI(LCTL(LSFT(KC_4)))
#define LCTLC LCTL(KC_C)
#define SHFTTAB LSFT(KC_TAB)
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
#define ESCSHFT LSFT_T(KC_ESC)
#define ESC_CTL LCTL_T(KC_ESC)
#define GUI_ENT LGUI_T(KC_ENT)
#define TABCTRL LCTL_T(KC_TAB)
#define SPCSFT LSFT_T(KC_SPC)
#define MACSLEP LSFT(LCTL(KC_POWER))

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)
#define HYPR_Y HYPR(KC_Y)
#define HYPR_U HYPR(KC_U)
#define HYPR_I HYPR(KC_I)
#define HYPR_O HYPR(KC_O)
#define HYPR_P HYPR(KC_P)

#define CB_SELC LGUI(KC_A)
#define CB_SAVE LGUI(KC_S)
#define CB_UNDO LGUI(KC_Z)
#define CB_COPY LGUI(KC_C)
#define CB_PAST LGUI(KC_V)
#define CB_OPTB LGUI(LSFT(KC_T))
#define CB_NWTB LGUI(KC_T)
#define CB_NCGN LGUI(LSFT(KC_N))

uint16_t extract_base_tapping_keycode(uint16_t keycode);
