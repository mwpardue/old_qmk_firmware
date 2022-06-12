#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "smart_case.h"
#include "custom_oneshot_mods.h"

process_record_result_t process_smart_thumb_keys(uint16_t keycode, keyrecord_t *record);
