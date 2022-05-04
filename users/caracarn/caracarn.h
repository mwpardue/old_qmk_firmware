#include QMK_KEYBOARD_H

#include "definitions/layers.h"
#include "definitions/keycodes.h"

#ifdef TAP_DANCE_ENABLE
    #include "features/tapdance.h"
#endif

#ifdef ACHORDION_ENABLE
    #include "features/achordion.h"
#endif

#ifdef SECRETS_ENABLE
    #include "features/secrets.h"
#endif

#ifdef CAPSWORD_ENABLE
    #include "features/caps_word.h"
#endif

#ifdef TAPHOLD_ENABLE
    #include "features/taphold.h"
#endif

#ifdef CAPSLOCK_TIMER_ENABLE
    #include "features/capslock_timer.h"
#endif

#ifdef OS_TOGGLE_ENABLE
    #include "features/os_toggle.h"
#endif

#ifdef MACRO_ENABLE
    #include "features/macros.h"
#endif

#ifdef COMBO_ENABLE
    #include "features/combos.h"
#endif

#ifdef LEADER_ENABLE
    #include "features/leader.h"
#endif

#ifdef DEFAULT_MOD_ENABLE
    #include "features/default_mod_key.h"
#endif

#ifdef CAPITALIZE_KEY_ENABLE
    #include "features/capitalize_key.h"
#endif

#ifdef SELECT_WORD_ENABLE
    #include "features/select_word.h"
#endif

#ifdef WINDOW_SWAPPER_ENABLE
    #include "features/window_swapper.h"
#endif

#ifdef SHORTCUTS_ENABLE
    #include "features/custom_shortcuts.h"
#endif

#ifdef CUSTOM_SHIFT_ENABLE
    #include "features/custom_shift.h"
#endif

void matrix_scan_keymap(void);
