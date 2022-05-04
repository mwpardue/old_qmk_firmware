#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "caps_word.h"
//#include "os_toggle.h"
//#include "default_mod_key.h"
//#include "dynamic_macro.h"

enum {
    COM_HYP,
    SCL_END,
    BRT_CUR,
    BRT_SQR,
    BRT_PAR,
    BRT_ANG,
    // DOT_DOT,
    // CAP_KEY,
    SDB_QUO,
    MIN_CLN
};

#define TD_COMH TD(COM_HYP)
#define TD_SCLE TD(SCL_END)
#define TD_CURB TD(BRT_CUR)
#define TD_SQRB TD(BRT_SQR)
#define TD_PARB TD(BRT_PAR)
#define TD_ANGB TD(BRT_ANG)
// #define TD_DOTD TD(DOT_DOT)
// #define TD_CAPK TD(CAP_KEY)
#define TD_QUOT TD(SDB_QUO)
#define TD_MCLN TD(MIN_CLN)

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
    bool recording;
} td_tap_t;

td_state_t dance_state(qk_tap_dance_state_t *state);
