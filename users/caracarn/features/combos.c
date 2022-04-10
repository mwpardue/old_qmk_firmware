#include QMK_KEYBOARD_H

#include "combos.h"

//Shortcuts
const uint16_t PROGMEM new_tab_combo[] = {SPC_MAC, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM open_incognito_combo[] = {SPC_MAC, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM reopen_tab_combo[] = {SPC_MAC, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM hex_layer_combo[] = {TAB_NUM, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM sleep_combo[] = {SPC_MAC, KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM function_layer_combo[] = {SPC_MAC, TAB_NUM, KC_Q, KC_P, COMBO_END};

//Keycodes
const uint16_t PROGMEM esc_combo[] = {TAB_NUM, KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {SPC_MAC, LALT_T(KC_K), LCTL_T(KC_L), COMBO_END};

//Modifiers
const uint16_t PROGMEM l_lctl_combo[] = {TAB_NUM, GUI_A, CTL_S, COMBO_END};
const uint16_t PROGMEM l_lalt_combo[] = {TAB_NUM, CTL_S, ALT_D, COMBO_END};
const uint16_t PROGMEM l_lsft_combo[] = {TAB_NUM, ALT_D, GUI_F, COMBO_END};
const uint16_t PROGMEM l_lgui_combo[] = {TAB_NUM, ALT_D, KC_V, COMBO_END};

const uint16_t PROGMEM r_lctl_combo[] = {SPC_MAC, CTL_L, TD_QUOT, COMBO_END};
const uint16_t PROGMEM r_ralt_combo[] = {SPC_MAC, ALT_K, CTL_L, COMBO_END};
const uint16_t PROGMEM r_lsft_combo[] = {SPC_MAC, GUI_J, ALT_K, COMBO_END};
const uint16_t PROGMEM r_lgui_combo[] = {SPC_MAC, ALT_K, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  COMBO(l_lctl_combo, CB_OSMLCTL),
  COMBO(l_lalt_combo, CB_OSMLALT),
  COMBO(l_lsft_combo, CB_OSMLSFT),
  COMBO(l_lgui_combo, CB_OSMLGUI),
  COMBO(r_ralt_combo, CB_OSMRALT),
  COMBO(r_lctl_combo, CB_OSMLCTL),
  COMBO(r_lsft_combo, CB_OSMLSFT),
  COMBO(r_lgui_combo, CB_OSMLGUI),



  COMBO(esc_combo, KC_ESC),
  COMBO(enter_combo, KC_ENTER),


  COMBO(new_tab_combo, CB_NWTB),
  COMBO(reopen_tab_combo, CB_OPTB),
  COMBO(open_incognito_combo, CB_NCGN),
  COMBO(hex_layer_combo, TOHEX),
  COMBO(function_layer_combo, TOFUN),
  COMBO(sleep_combo, MACSLEP)

};

extern os_t os;

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
