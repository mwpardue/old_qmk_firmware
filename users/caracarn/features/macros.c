#include QMK_KEYBOARD_H

#include "macros.h"

//extern os_t os;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {
    //if (!process_caps_word(keycode, record)) { return false; }
    if (record->event.pressed) {
        switch (keycode) {

            // Standalone accent characters

            case TIPS:
                del_oneshot_mods(MOD_BIT(KC_LSFT));
                unregister_mods(MOD_BIT(KC_LSFT));
                SEND_STRING("trueipsolutions.com");
                return PROCESS_RECORD_RETURN_FALSE;

            case FOPEN:
                SEND_STRING("open ./");
                tap_code(KC_ENT);
                return PROCESS_RECORD_RETURN_FALSE;

            case VIMWQ:
                tap_code(KC_ESC);
                SEND_STRING(":wq");
                //tap_code(KC_ENT);
                return PROCESS_RECORD_RETURN_FALSE;

            case VIMQ:
                tap_code(KC_ESC);
                SEND_STRING(":q!");
                //tap_code(KC_ENT);
                return PROCESS_RECORD_RETURN_FALSE;

        }
    }

    return PROCESS_RECORD_CONTINUE;
}
