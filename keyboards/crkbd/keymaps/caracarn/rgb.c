// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "caracarn.h"
#include "rgb.h"
#include "features/caps_word.h"
extern led_config_t g_led_config;


void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }

            RGB rgb = hsv_to_rgb(hsv);
            for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
			  rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
                #ifdef CAPS_WORD_ENABLE
                    bool isCapsWord = caps_word_get();
                        if (isCapsWord) {
                            rgb_matrix_set_color(6, 255, 0, 0);
                        }
                #endif
                #ifdef SMART_CASE_ENABLE
                    bool smartCase = has_any_smart_case();
                        if (smartCase) {
                            rgb_matrix_set_color(6, 255, 0, 0);
                        }
                #endif
                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
                }
            }
        }

__attribute__((weak)) void rgb_matrix_indicator_keymap(void) {}

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) { return true; }
void                       rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keymap(led_min, led_max)) { return; }
    {
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case _BASE:
                rgb_matrix_layer_helper(HSV_CYAN, led_min, led_max);
                break;
            case _NUMPAD:
                rgb_matrix_layer_helper(HSV_GREEN, led_min, led_max);
                break;
            case _MACROS:
                rgb_matrix_layer_helper(HSV_CORAL, led_min, led_max);
                break;
            case _SYMBOL:
                rgb_matrix_layer_helper(HSV_YELLOW, led_min, led_max);
                break;
            case _FUNCTION:
                rgb_matrix_layer_helper(HSV_RED, led_min, led_max);
                break;
            case _HEX:
                rgb_matrix_layer_helper(HSV_PURPLE, led_min, led_max);
                break;
        }
    }
}

__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) { return true; }
void                       rgb_matrix_indicators_user(void) { rgb_matrix_indicators_keymap(); }
