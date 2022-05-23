#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "tapdance.h"
#include "process_record_result.h"
#include "default_mod_key.h"
//#include "secrets.h"

#ifndef DEFAULT_MOD_ENABLE
    #ifndef SHORTCUTS_ENABLE
        bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift);
    #endif
#endif


process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record);
