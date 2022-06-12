#include QMK_KEYBOARD_H

#include "capitalize_key.h"
#include "caps_word.h"

//extern os_t os;

process_record_result_t process_capitalize_key(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case CAP_KEY:
                if (record->tap.count > 0) {
                    if (record->event.pressed) {
                    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
                    bool isCapsWord = caps_word_get();
                    if (isOneShotShift && !isCapsWord) {
                        //SEND_STRING("CAPSWORD_ON");
                        caps_word_set(true);
                    } else if (isCapsWord) {
                        //SEND_STRING("CAPSWORD_OFF");
                        caps_word_set(false);
                    } else {
                        //SEND_STRING("OS_SHIFT");
                        add_oneshot_mods(MOD_BIT(KC_LSFT));
                    }


                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}
