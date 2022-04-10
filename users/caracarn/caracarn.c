#include "caracarn.h"

extern os_t os;

void matrix_init_user(void) {
    // Enable or disable debugging
    debug_enable=false;
}

// Led update

/* bool led_update_user(led_t led_state) {
    check_start_capslock_timer(led_state.caps_lock);
    return true;
}
 */
// Matrix scan

__attribute__ ((weak)) void matrix_scan_keymap(void) {
}

void matrix_scan_user(void) {
    //achordion_task();
    check_disable_capslock();
    caps_word_task();
    process_leader_dictionary();
    matrix_scan_keymap();
}

// bool achordion_chord(uint16_t tap_hold_keycode,
//                      keyrecord_t* tap_hold_record,
//                      uint16_t other_keycode,
//                      keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Dvorak.
  /* switch (tap_hold_keycode) {
    case HOME_A:  // A + U.
      if (other_keycode == HOME_U) { return true; }
      break;

    case HOME_S:  // S + H and S + G.
      if (other_keycode == HOME_H || other_keycode == KC_G) { return true; }
      break;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  //if (tap_hold_keycode->event.key.row % (MATRIX_ROWS / 2) >= 8) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
} */

//  uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
//   switch (tap_hold_keycode) {
//     case CAP_KEY:
//     case TAB_NUM:
//     case SPC_MAC:
//     case BSP_SYM:
//     case TAB_HYP:
//       return 0;  // Bypass Achordion for these keys.
//   }

//   return 800;  // Otherwise use a timeout of 800 ms.
// }


// Process record

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //if (!process_achordion(keycode, record)) { return false; }
    if (!process_caps_word(keycode, record)) { return false; }

    // Extend capslock timer
     switch (process_capslock_timer_extension(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process secrets
     switch (process_secrets(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process window swapper
    switch (process_window_swapper(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process custom_shift
   switch (process_custom_shift(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process custom_shortcuts
    switch (process_custom_shortcuts(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process combos
    switch (process_combos(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process macros
    switch (process_macros(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process select word
    switch (process_select_word(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process taphold
/*     switch (process_taphold(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };
 */
    /* // Process accentuation
    switch (process_accentuated_characters(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    }; */

    // Process default modifier key
    switch (process_default_mod_key(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

     // Process capitalize key
    switch (process_capitalize_key(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    /* // Process mouse layer
    switch (process_mouselayer(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    }; */

    // Process OS toggle
    switch (process_os_toggle(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    if (debug_enable) {
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    };
#endif
    return true;
}

// Tap-hold configuration

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return get_hold_on_other_key_press_result(keycode);
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_force_hold_result(keycode);
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return get_permissive_hold_result(keycode);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_term_result(keycode);
}

/* // Dynamic macros

void dynamic_macro_record_start_user(void) {
}

void dynamic_macro_play_user(int8_t direction) {
}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
}

void dynamic_macro_record_end_user(int8_t direction) {
} */
