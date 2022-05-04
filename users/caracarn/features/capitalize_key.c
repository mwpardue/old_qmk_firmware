#include QMK_KEYBOARD_H

#include "capitalize_key.h"
#include "caps_word.h"

//extern os_t os;

process_record_result_t process_capitalize_key(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case CAP_KEY:
                if (record->tap.count > 0) {
                // if (record->tap.count == 1 && record->event.pressed) {
                //     register_mods(MOD_BIT(KC_LSFT));
                // } else if (record->tap.count >= 1 && !record->event.pressed) {
                    if (record->event.pressed) {
                    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
                    //bool isCapsLocked = host_keyboard_led_state().caps_lock;
                    bool isCapsWord = caps_word_get();
                    if (isCapsWord) {
                        caps_word_set(false); //Disables capsword
                    //if (isCapsLocked) {
                        //tap_code(KC_CAPS); // Disable capslock
                    } else {
                        if (!isOneShotShift) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            del_oneshot_mods(MOD_BIT(KC_LSFT));
                            unregister_mods(MOD_BIT(KC_LSFT));
                            //tap_code(KC_CAPS); // Enable capslock
                            caps_word_set(true); //Enables capsword
                        }
                    }
                }
                // else {
                //     unregister_mods(MOD_BIT(KC_LSFT));
                // }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}
