#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "os_toggle.h"
#include "default_mod_key.h"

#ifndef DEFAULT_MOD_ENABLE
        bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift);
#endif

process_record_result_t process_custom_shortcuts(uint16_t keycode, keyrecord_t *record);
