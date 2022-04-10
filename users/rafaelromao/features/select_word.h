#pragma once

#include QMK_KEYBOARD_H

#include "os_toggle.h"
#include "default_mod_key.h"
#include "process_record_result.h"

typedef enum { 
    STATE_NONE, 
    STATE_LINE_SELECTED, 
    STATE_WORD_SELECTED, 
    STATE_WORD, 
    STATE_FIRST_LINE, 
    STATE_LINE 
} select_word_state_t;

typedef struct {
    select_word_state_t state;
} select_word_t;

process_record_result_t process_select_word(uint16_t keycode, keyrecord_t* record);
