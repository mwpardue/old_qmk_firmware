#include QMK_KEYBOARD_H

#include "custom_shift.h"

//extern os_t os;
static bool custom_shifting = false;

#ifndef DEFAULT_MOD_KEY_ENABLE
    #ifndef CUSTOM_ONESHOT_MODS_ENABLE
        void clear_locked_and_oneshot_mods(void) {
            uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
            uint8_t oneshot_mods = get_oneshot_mods();
            if (oneshot_locked_mods || oneshot_mods) {
                clear_oneshot_mods();
                clear_oneshot_locked_mods();
                unregister_mods(MOD_LSFT);
                unregister_mods(MOD_LCTL);
                unregister_mods(MOD_LALT);
                unregister_mods(MOD_RALT);
                unregister_mods(MOD_LGUI);
            }
        //    dyn_macro_reset();
        }
    #endif
#endif

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted = custom_shifting || isOneShotShift || get_mods() & MOD_MASK_SHIFT;
    uint16_t key = extract_base_tapping_keycode(keycode);

    // Numpad Custom Shifts (make it work even on MacOS)

    switch (key) {

        // Ignore space for one-shot shift

        case KC_SPC:
            if (record->event.pressed) {
                if (isOneShotShift) {
                    tap_code(KC_SPC);
                    add_oneshot_mods(MOD_LSFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_CONTINUE;

        // Shift+Backspace for Delete (when not one-shot)

        case KC_BSPC:
            if (record->event.pressed) {
                if (isShifted && !isOneShotShift) {
                    tap_code(KC_DEL);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_RETURN_TRUE;

    }

    return PROCESS_RECORD_CONTINUE;
}
