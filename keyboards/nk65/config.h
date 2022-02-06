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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x8968
#define PRODUCT_ID      0x4E4B
#define DEVICE_VER      0x0001
#define MANUFACTURER    Yiancar-Designs
#define PRODUCT         NK65

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define MATRIX_ROW_PINS { B3, B4, B5, A8, A4 }
#define MATRIX_COL_PINS { A13, A10, A9, A14, A15, B8, B9, C13, C14, C15, A0, A1, A2, A3, A5 }
// To enable debugger set A13 A14 -> A5 A7

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
#define MATRIX_HAS_GHOST

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
 #define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
#define FORCE_NKRO

/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Backlight options */
//#ifdef RGB_BACKLIGHT_ENABLE
//#define RGB_BACKLIGHT_ENABLED 1

//#define RGB_BACKLIGHT_NK65

// they aren't really used if RGB_BACKLIGHT_HS60 defined
//#define RGB_BACKLIGHT_USE_SPLIT_BACKSPACE 0
//#define RGB_BACKLIGHT_USE_SPLIT_LEFT_SHIFT 0
//#define RGB_BACKLIGHT_USE_SPLIT_RIGHT_SHIFT 0
//#define RGB_BACKLIGHT_USE_7U_SPACEBAR 0
//#define RGB_BACKLIGHT_USE_ISO_ENTER 0
//#define RGB_BACKLIGHT_DISABLE_HHKB_BLOCKER_LEDS 0

// disable backlight when USB suspended (PC sleep/hibernate/shutdown)
//#define RGB_BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED 0

// disable backlight after timeout in minutes, 0 = no timeout
//#define RGB_BACKLIGHT_DISABLE_AFTER_TIMEOUT 0

// the default brightness
//#define RGB_BACKLIGHT_BRIGHTNESS 255

// the default effect (RGB test)
//#define RGB_BACKLIGHT_EFFECT 6

// the default effect speed (0-3)
//#define RGB_BACKLIGHT_EFFECT_SPEED 0

// the default color1 and color2
//#define RGB_BACKLIGHT_COLOR_1 { .h = 0, .s = 255 }
//#define RGB_BACKLIGHT_COLOR_2 { .h = 127, .s = 255 }

//#define DRIVER_COUNT 2
//#define DRIVER_LED_TOTAL 128

// These define which keys in the matrix are alphas/mods
// Used for backlight effects so colors are different for
// alphas vs. mods
// Each value is for a row, bit 0 is column 0
// Alpha=0 Mod=1
//#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_0 0b0110000000000001
//#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_1 0b0100000000000001
//#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_2 0b0110000000000001
//#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_3 0b0111000000000001
//#define RGB_BACKLIGHT_ALPHAS_MODS_ROW_4 0b0111111000000111

//#define RGB_BACKLIGHT_CAPS_LOCK_INDICATOR { .color = { .h = 0, .s = 0 }, .index = 255 }
//#define RGB_BACKLIGHT_LAYER_1_INDICATOR { .color = { .h = 0, .s = 0 }, .index = 255 }
//#define RGB_BACKLIGHT_LAYER_2_INDICATOR { .color = { .h = 0, .s = 0 }, .index = 255 }
//#define RGB_BACKLIGHT_LAYER_3_INDICATOR { .color = { .h = 0, .s = 0 }, .index = 255 }

//#endif


// RGB Matrix Support

#ifdef RGB_MATRIX_ENABLE
#   define DRIVER_ADDR_1 0x50
#   define DRIVER_ADDR_2 0x52
#   define DRIVER_COUNT 2
#   define DRIVER_1_LED_TOTAL 64
#   define DRIVER_2_LED_TOTAL 5
#   define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#   define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#   define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 25
//#   ifndef RGB_DISABLE_WHEN_USB_SUSPENDED
//#       define RGB_DISABLE_WHEN_USB_SUSPENDED true
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_KEYPRESSES         // reacts to keypresses
// #define RGB_MATRIX_KEYRELEASES        // reacts to keyreleases (instead of keypresses)
#   define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP // Sets the default mode, if none has been set
// #define RGBLIGHT_HUE_STEP 12        // Units to step when in/decreasing hue
// #define RGBLIGHT_SAT_STEP 25        // Units to step when in/decreasing saturation
// #define RGBLIGHT_VAL_STEP 12        // Units to step when in/decreasing value (brightness)
// #define RGB_DISABLE_AFTER_TIMEOUT 0   // number of ticks to wait until disabling effects
// #define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
//#   define RGB_MATRIX_LED_PROCESS_LIMIT 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
//#   define RGB_MATRIX_LED_FLUSH_LIMIT 1
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
// #define DISABLE_RGB_MATRIX_SOLID_COLOR                   // Static single hue, no speed support
// #define DISABLE_RGB_MATRIX_ALPHAS_MODS                   // Static dual hue, speed is hue for secondary hue
// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN              // Static gradient top to bottom, speed controls how much gradient changes
// #define DISABLE_RGB_MATRIX_BREATHING                     // Single hue brightness cycling animation
#   define DISABLE_RGB_MATRIX_BAND_SAT                      // Single hue band fading saturation scrolling left to right
#   define DISABLE_RGB_MATRIX_BAND_VAL                      // Single hue band fading brightness scrolling left to right
//#   define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT             // Single hue 3 blade spinning pinwheel fades saturation
//#   define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL             // Single hue 3 blade spinning pinwheel fades brightness
//#   define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT               // Single hue spinning spiral fades saturation
//#   define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL               // Single hue spinning spiral fades brightness
//#   define DISABLE_RGB_MATRIX_CYCLE_ALL                     // Full keyboard solid hue cycling through full gradient
#   define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT              // Full gradient scrolling left to right
#   define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN                 // Full gradient scrolling top to bottom
//#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN                  // Full gradient scrolling out to in
#   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL             // Full dual gradients scrolling out to in
//#   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON        // Full gradent Chevron shapped scrolling left to right
#   define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL                // Full gradient spinning pinwheel around center of keyboard
//#   define DISABLE_RGB_MATRIX_CYCLE_SPIRAL                  // Full gradient spinning spiral around center of keyboard
#   define DISABLE_RGB_MATRIX_DUAL_BEACON                   // Full gradient spinning around center of keyboard
#   define DISABLE_RGB_MATRIX_RAINBOW_BEACON                // Full tighter gradient spinning around center of keyboard
//#   define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS             // Full dual gradients spinning two halfs of keyboard
// #define DISABLE_RGB_MATRIX_RAINDROPS                     // Randomly changes a single key's hue
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS           // Randomly changes a single key's hue and saturation
// =================================================== Requires RGB_MATRIX_FRAMEBUFFER_EFFECTS =============================================================
// #define DISABLE_RGB_MATRIX_TYPING_HEATMAP                // How hot is your WPM!
#   define DISABLE_RGB_MATRIX_DIGITAL_RAIN                  // That famous computer simulation
// =================================================== RGB_MATRIX_KEYPRESSES OR RGB_MATRIX_KEYRELEASES =====================================================
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE                // Static single hue, pulses keys hit to shifted hue then fades to current hue
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE         // Pulses keys hit to hue & value then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE           // Hue & value pulse near a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE      // Hue & value pulse near multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS          // Hue & value pulse the same column and row of a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS     // Hue & value pulse the same column and row of multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS          // Hue & value pulse away on the same column and row of a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS     // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SPLASH                        // Full gradient & value pulse away from a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_MULTISPLASH                   // Full gradient & value pulse away from multiple key hits then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_SPLASH                  // Hue & value pulse away from a single key hit then fades value out
#   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH             // Hue & value pulse away from multiple key hits then fades value out
#endif

// Backlight config starts after VIA's EEPROM usage,
// dynamic keymaps start after this.
#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 32

// VIA lighting is handled by the keyboard-level code
//#define VIA_CUSTOM_LIGHTING_ENABLE

/* Custom EEPROM start addressing. This is to support
 * both 128kb and 256kb versions of F303.
 * Register 0x1FFFF7CC holds the size of the flash memory.
 */
#ifndef FLASHSIZE_BASE
#  define FLASHSIZE_BASE ((uint32_t)0x1FFFF7CCU) /*!< FLASH Size register base address */
#endif
#define FEE_MCU_FLASH_SIZE_IGNORE_CHECK
#define FEE_MCU_FLASH_SIZE                              \
({                                                      \
    uint16_t (*flash_size) = (uint16_t*)FLASHSIZE_BASE;  \
    *flash_size;                                        \
})
