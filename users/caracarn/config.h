#pragma once

// Optimization to save memory
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Make it easier to work with tap hold
#ifdef CAPSWORD_ENABLE
    #define CAPS_WORD_IDLE_TIMEOUT 2000
#endif

#ifdef TAPHOLD_ENABLE
    #define IGNORE_MOD_TAP_INTERRUPT
    #define TAPPING_TERM_PER_KEY
    #define TAPPING_FORCE_HOLD_PER_KEY
    #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
    #define PERMISSIVE_HOLD_PER_KEY
#endif
//#define BILATERAL_COMBINATIONS

    #define ONESHOT_TAP_TOGGLE 2
    #define ONESHOT_TIMEOUT 2000
    #define TAPPING_TOGGLE 1
    #define TAPPING_TERM 175

#ifdef CUSTOM_ONESHOT_MODS_ENABLE
    #define CUSTOM_ONESHOT_TIMEOUT 2000
#endif

// Configure leader key
#ifdef LEADER_ENABLE
    #define LEADER_TIMEOUT 1000
    #define LEADER_PER_KEY_TIMING
    #define LEADER_NO_TIMEOUT
#endif

// Configure combos
#ifdef COMBO_ENABLE
    #define COMBO_COUNT 8
    #define COMBO_TERM 60
    #define EXTRA_SHORT_COMBOS
    #define COMBO_STRICT_TIMER
    #define COMBO_HOLD_TERM 175
    #define COMBO_MUST_TAP_PER_COMBO
#endif

    #define MACRO_TIMER 5

// Mouse key speed and acceleration.
#ifdef MOUSEKEY_ENABLE
    #define MOUSEKEY_DELAY 100
    #define MOUSEKEY_INTERVAL 10
    #define MOUSEKEY_MOVE_DELTA 5
    #define MOUSEKEY_MAX_SPEED 10
    #define MOUSEKEY_TIME_TO_MAX 25
    #define MOUSEKEY_WHEEL_DELAY 100
    #define MOUSEKEY_WHEEL_INTERVAL 100
    #define MOUSEKEY_WHEEL_MAX_SPEED 20
    #define MOUSEKEY_WHEEL_TIME_TO_MAX 10
#endif

#ifdef LAYER_LOCK_ENABLE
    #define LAYER_LOCK_IDLE_TIMEOUT 30000
#endif
