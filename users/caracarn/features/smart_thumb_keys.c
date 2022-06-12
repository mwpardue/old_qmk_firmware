#include QMK_KEYBOARD_H

#include "smart_thumb_keys.h"


process_record_result_t process_smart_thumb_keys(uint16_t keycode, keyrecord_t *record) {
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT || isOneShotLockedShift;
    bool isOneShotCtrl        = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt         = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui         = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;


    switch (keycode) {
        case CAP_KEY:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (has_any_smart_case()) {
                        disable_smart_case();
                        clear_shift();
                    } else {
                        if (isAnyOneShotButShift || isOneShotLockedShift) {
                            clear_locked_and_oneshot_mods();
                        } else if (!isOneShotShift && get_mods() == 0) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            set_smart_case_for_mods(record);
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}
