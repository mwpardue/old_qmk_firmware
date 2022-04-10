#include QMK_KEYBOARD_H

#include "taphold.h"

/* process_record_result_t process_custom_taphold(uint16_t keycode, keyrecord_t *record) {
    // Fix layer-tap using Underscore
    switch (keycode) {
        case UND_MAI:
        case UND_FUN:
        case LA_UNDS:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    tap_code16(KC_UNDS);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
        case F15_MAI:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    tap_code16(KC_F15);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
    }
    return PROCESS_RECORD_CONTINUE;
} */

/* process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record) {
    switch (process_custom_taphold(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return PROCESS_RECORD_RETURN_TRUE;
        case PROCESS_RECORD_RETURN_FALSE:
            return PROCESS_RECORD_RETURN_FALSE;
        default:
            break;
    };

    return PROCESS_RECORD_CONTINUE;
} */

uint16_t get_tapping_term_result(uint16_t keycode) {
    switch (keycode) {
        case TAB_NUM:
        case SPC_MAC:
            return TAPPING_TERM + 40;
        case GUI_A:
        case CTL_S:
        case ALT_D:
        case GUI_F:
        case CTL_L:
        case ALT_K:
        case GUI_J:
            return TAPPING_TERM + 115;
        case TD_ANGB:
        case TD_PARB:
        case TD_CURB:
        case TD_SQRB:
            return TAPPING_TERM + 100;
        // case TD(CAP_KEY):
        //     return 250;
        case CB_OSMLALT:
        case CB_OSMRALT:
        case CB_OSMLSFT:
        case CB_OSMLGUI:
        case CB_OSMLCTL:
            return TAPPING_TERM + 2000;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold_result(uint16_t keycode) {
    switch (keycode) {
        case BSP_SYM:
        case SPC_MAC:
            return false;
    }
    switch (keycode) {
        case QK_MOD_TAP...QK_MOD_TAP_MAX:
        case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
        case QK_MOMENTARY...QK_MOMENTARY_MAX:
            return true;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press_result(uint16_t keycode) {
    switch (keycode) {
        case TAB_NUM:
        // case TD_CAPK:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold_result(uint16_t keycode) {
    switch (keycode) {
        case GUI_A:
        case CTL_S:
        case ALT_D:
        case GUI_F:
        case CTL_L:
        case ALT_K:
        case GUI_J:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
