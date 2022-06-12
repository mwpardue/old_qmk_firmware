#include QMK_KEYBOARD_H

#include "combos.h"

//Shortcuts
const uint16_t PROGMEM new_tab_combo[] = {SPC_MAC, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM open_incognito_combo[] = {SPC_MAC, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM reopen_tab_combo[] = {SPC_MAC, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM hex_layer_combo[] = {TAB_NUM, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM sleep_combo[] = {SPC_MAC, KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM function_layer_combo[] = {BSP_SYM, KC_N, KC_M, COMBO_END};

//Keycodes
const uint16_t PROGMEM esc_combo[] = {TAB_NUM, KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {SPC_MAC, RALT_T(KC_K), RCTL_T(KC_L), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  COMBO(esc_combo, KC_ESC),
  COMBO(enter_combo, KC_ENTER),
  COMBO(new_tab_combo, CB_NWTB),
  COMBO(reopen_tab_combo, CB_OPTB),
  COMBO(open_incognito_combo, CB_NCGN),
  COMBO(hex_layer_combo, TOHEX),
  COMBO(function_layer_combo, MOFUN),
  COMBO(sleep_combo, MACSLEP)

};

extern os_t os;

#ifndef DEFAULT_MOD_ENABLE
    #ifndef SHORTCUTS_ENABLE
        bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift) {
            return (isWindowsOrLinux && !isOneShotShift) || (!isWindowsOrLinux && isOneShotShift);
        }
    #endif
#endif

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    uint16_t key;
    uint8_t idx = 0;
    bool combo_must_tap = false;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                combo_must_tap = true;
                break;
            default:
                combo_must_tap = false;
                break;
        }
        if (!combo_must_tap) {
            return false;
        }
        idx += 1;
    }
    return combo_must_tap;
}

 process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        case CB_NWTB:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("t"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_OPTB:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL(SS_LSFT("t")));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_NCGN:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL(SS_LSFT("n")));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        }

    return PROCESS_RECORD_CONTINUE;
}
