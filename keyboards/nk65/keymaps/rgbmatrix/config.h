/*
Copyright 2019 Yiancar
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* Remove RGB_Backlight options */

#undef RGB_BACKLIGHT_ENABLED
#define RGB_BACKLIGHT_ENABLED 0
#undef RGB_BACKLIGHT_NK65
#undef DRIVER_COUNT
#undef DRIVER_LED_TOTAL
#undef RGB_BACKLIGHT_USE_SPLIT_BACKSPACE
#undef RGB_BACKLIGHT_USE_SPLIT_LEFT_SHIFT
#undef RGB_BACKLIGHT_USE_SPLIT_RIGHT_SHIFT
#undef RGB_BACKLIGHT_USE_7U_SPACEBAR
#undef RGB_BACKLIGHT_USE_ISO_ENTER
#undef RGB_BACKLIGHT_DISABLE_HHKB_BLOCKER_LEDS
#undef RGB_BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED
#undef RGB_BACKLIGHT_DISABLE_AFTER_TIMEOUT
#undef RGB_BACKLIGHT_BRIGHTNESS
#undef RGB_BACKLIGHT_EFFECT
#undef RGB_BACKLIGHT_EFFECT_SPEED
#undef RGB_BACKLIGHT_COLOR_1
#undef RGB_BACKLIGHT_COLOR_2
#undef RGB_BACKLIGHT_ALPHAS_MODS_ROW_0
#undef RGB_BACKLIGHT_ALPHAS_MODS_ROW_1
#undef RGB_BACKLIGHT_ALPHAS_MODS_ROW_2
#undef RGB_BACKLIGHT_ALPHAS_MODS_ROW_3
#undef RGB_BACKLIGHT_ALPHAS_MODS_ROW_4
#undef RGB_BACKLIGHT_CAPS_LOCK_INDICATOR
#undef RGB_BACKLIGHT_LAYER_1_INDICATOR
#undef RGB_BACKLIGHT_LAYER_2_INDICATOR
#undef RGB_BACKLIGHT_LAYER_3_INDICATOR

/* Define RGB_MATRIX settings */

#define DRIVER_ADDR_1 0x50
#define DRIVER_ADDR_2 0x52
#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 64
#define DRIVER_2_LED_TOTAL 5
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 25
//#   ifndef RGB_DISABLE_WHEN_USB_SUSPENDED
//#       define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES         // reacts to keypresses
// #define RGB_MATRIX_KEYRELEASES        // reacts to keyreleases (instead of keypresses)
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP // Sets the default mode, if none has been set
// #define RGBLIGHT_HUE_STEP 12        // Units to step when in/decreasing hue
// #define RGBLIGHT_SAT_STEP 25        // Units to step when in/decreasing saturation
// #define RGBLIGHT_VAL_STEP 12        // Units to step when in/decreasing value (brightness)
// #define RGB_DISABLE_AFTER_TIMEOUT 0   // number of ticks to wait until disabling effects
// #define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
//#define RGB_MATRIX_LED_PROCESS_LIMIT 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
//#define RGB_MATRIX_LED_FLUSH_LIMIT 1
// #define RGBLIGHT_ANIMATIONS             // Run RGB animations
// #define RGBLIGHT_ANIMATIONS             // Enable all additional animation modes.
// #define RGBLIGHT_EFFECT_ALTERNATING     // Enable alternating animation mode.
// #define RGBLIGHT_EFFECT_BREATHING       // Enable breathing animation mode.
// #define RGBLIGHT_EFFECT_CHRISTMAS       // Enable christmas animation mode.
// #define RGBLIGHT_EFFECT_KNIGHT          // Enable knight animation mode.
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD    // Enable rainbow mood animation mode.
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL   // Enable rainbow swirl animation mode.
// #define RGBLIGHT_EFFECT_RGB_TEST        // Enable RGB test animation mode.
// #define RGBLIGHT_EFFECT_SNAKE           // Enable snake animation mode.
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT // Enable static gradient mode.

// #define RGBLIGHT_EFFECT_BREATHE_CENTER              // If defined, used to calculate the curve for the breathing animation. Valid values are 1.0 to 2.7
// #define RGBLIGHT_EFFECT_BREATHE_MAX 255             // The maximum brightness for the breathing mode. Valid values are 1 to 255
// #define RGBLIGHT_EFFECT_CHRISTMAS_INTERVAL 1000     // How long to wait between light changes for the "Christmas" animation, in milliseconds
// #define RGBLIGHT_EFFECT_CHRISTMAS_STEP 2            // The number of LEDs to group the red/green colors by for the "Christmas" animation
// #define RGBLIGHT_EFFECT_KNIGHT_LED_NUM RGBLED_NUM   // The number of LEDs to have the "Knight" animation travel
// #define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3             // The number of LEDs to light up for the "Knight" animation
// #define RGBLIGHT_EFFECT_KNIGHT_OFFSET 0             // The number of LEDs to start the "Knight" animation from the start of the strip by
// #define RGBLIGHT_RAINBOW_SWIRL_RANGE 255            // Range adjustment for the rainbow swirl effect to get different swirls
// #define RGBLIGHT_EFFECT_SNAKE_LENGTH 4              // The number of LEDs to light up for the "Snake" animation

// This list in in the correct mode order. Next mode is the following line, previous mode is previous line. Loops around.
#define ENABLE_RGB_MATRIX_SOLID_COLOR                   // Static single hue, no speed support
#define ENABLE_RGB_MATRIX_ALPHAS_MODS                   // Static dual hue, speed is hue for secondary hue
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN              // Static gradient top to bottom, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_BREATHING                     // Single hue brightness cycling animation
#undef ENABLE_RGB_MATRIX_BAND_SAT                      // Single hue band fading saturation scrolling left to right
#undef ENABLE_RGB_MATRIX_BAND_VAL                      // Single hue band fading brightness scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT             // Single hue 3 blade spinning pinwheel fades saturation
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL             // Single hue 3 blade spinning pinwheel fades brightness
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT               // Single hue spinning spiral fades saturation
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL               // Single hue spinning spiral fades brightness
#define ENABLE_RGB_MATRIX_CYCLE_ALL                     // Full keyboard solid hue cycling through full gradient
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT              // Full gradient scrolling left to right
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN                 // Full gradient scrolling top to bottom
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN                  // Full gradient scrolling out to in
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL             // Full dual gradients scrolling out to in
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON        // Full gradent Chevron shapped scrolling left to right
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL                // Full gradient spinning pinwheel around center of keyboard
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL                  // Full gradient spinning spiral around center of keyboard
#undef ENABLE_RGB_MATRIX_DUAL_BEACON                   // Full gradient spinning around center of keyboard
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON                // Full tighter gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS             // Full dual gradients spinning two halfs of keyboard
#define ENABLE_RGB_MATRIX_RAINDROPS                     // Randomly changes a single key's hue
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS           // Randomly changes a single key's hue and saturation
// =================================================== Requires RGB_MATRIX_FRAMEBUFFER_EFFECTS =============================================================
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP                // How hot is your WPM!
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN                  // That famous computer simulation
// =================================================== RGB_MATRIX_KEYPRESSES OR RGB_MATRIX_KEYRELEASES =====================================================
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE                // Static single hue, pulses keys hit to shifted hue then fades to current hue
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE         // Pulses keys hit to hue & value then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE           // Hue & value pulse near a single key hit then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE      // Hue & value pulse near multiple key hits then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS          // Hue & value pulse the same column and row of a single key hit then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS     // Hue & value pulse the same column and row of multiple key hits then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS          // Hue & value pulse away on the same column and row of a single key hit then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS     // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#undef ENABLE_RGB_MATRIX_SPLASH                        // Full gradient & value pulse away from a single key hit then fades value out
#undef ENABLE_RGB_MATRIX_MULTISPLASH                   // Full gradient & value pulse away from multiple key hits then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH                  // Hue & value pulse away from a single key hit then fades value out
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH             // Hue & value pulse away from multiple key hits then fades value out
