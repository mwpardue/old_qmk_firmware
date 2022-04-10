#include QMK_KEYBOARD_H

#include "tapdance.h"

extern os_t os;

static td_tap_t tap_state = {
    .state = TD_NONE
};

/* static tap td_caps_key_tap_state = {
    .is_press_action = true,
    .state = 0
} */

__attribute__ ((weak)) td_state_t dance_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Dancing brackets

void td_curly_braces(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LCBR);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RCBR);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_SPC);
            tap_code16(KC_LCBR);
            break;
        default: break;
    }
}

void td_square_brackets(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LBRC);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RBRC);
            break;
        default: break;
    }
}

void td_parentesis(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LPRN);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RPRN);
            break;
        default: break;
    }
}

void td_angle_brackets(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LT);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_GT);
            break;
        default: break;
    }
}

void td_minus_colon(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_MINS);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_COLN);
            break;
        default: break;
    }
}

// Semicolon at the end

void td_semicolon(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SCLN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_SCLN);
            break;
        default: break;
    }
}

// Comma leader

void td_comma_hyper(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isShifted = get_mods() & MOD_MASK_SHIFT ||
            get_oneshot_mods() & MOD_MASK_SHIFT ||
            get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_COMM);
            break;
        case TD_DOUBLE_TAP:
            if (!isShifted) {
                set_oneshot_mods(MOD_HYPR);
            } else {
                tap_code(KC_COMM);
            }
            break;
        default: break;
    }
}

// Dot dot new sentence

/* void td_dot_dot(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DOT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_SPC);
            add_oneshot_mods(MOD_LSFT);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_DOT);
            break;
        default: break;
    }
} */


// Quotes

void td_quotes(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_QUOT);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_DQUO);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_COLN);
            break;
        default: break;
    }
}

/* void td_caps_key_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isCapsLocked = host_keyboard_led_state().caps_lock;
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
                    if (isCapsLocked) {
                        tap_code(KC_CAPS); // Disable capslock
                    } else if (!isOneShotShift) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            del_oneshot_mods(MOD_BIT(KC_LSFT));
                            unregister_mods(MOD_BIT(KC_LSFT));
					}
			break;
        case TD_DOUBLE_TAP:
                    if (isCapsLocked) {
                        tap_code(KC_CAPS); // Disable capslock
                    } else if (isOneShotShift) {
                            del_oneshot_mods(MOD_BIT(KC_LSFT));
                            unregister_mods(MOD_BIT(KC_LSFT));
                    } else {
                            caps_word_set(true);
					}
            break;
        case TD_TRIPLE_TAP:
                    if (isCapsLocked) {
                        tap_code(KC_CAPS); // Disable capslock
                    } else if (isOneShotShift) {
                            del_oneshot_mods(MOD_BIT(KC_LSFT));
                            unregister_mods(MOD_BIT(KC_LSFT));
                    } else {
                            tap_code(KC_CAPS); //Enable Capslock
					}
            break;
        case TD_SINGLE_HOLD:
                    register_code(KC_LSFT);
                    break;
        default: break;
    }
}

void td_caps_key_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break;
        case TD_DOUBLE_SINGLE_TAP: break;
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        case TD_NONE: break;
        case TD_UNKNOWN: break;
    }
    tap_state.state = TD_NONE;
} */

// Tap dance declarations

qk_tap_dance_action_t tap_dance_actions[] = {
    [COM_HYP] = ACTION_TAP_DANCE_FN(td_comma_hyper),
    [SCL_END] = ACTION_TAP_DANCE_FN(td_semicolon),
    [BRT_CUR] = ACTION_TAP_DANCE_FN(td_curly_braces),
    [BRT_SQR] = ACTION_TAP_DANCE_FN(td_square_brackets),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
    [BRT_ANG] = ACTION_TAP_DANCE_FN(td_angle_brackets),
    // [DOT_DOT] = ACTION_TAP_DANCE_FN(td_dot_dot),
    // [CAP_KEY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_caps_key_finished, td_caps_key_reset),
    [SDB_QUO] = ACTION_TAP_DANCE_FN(td_quotes),
    [MIN_CLN] = ACTION_TAP_DANCE_FN(td_minus_colon)
};
