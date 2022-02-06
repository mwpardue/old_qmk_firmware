/* Copyright 2019 Yiancar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
//#ifndef RGB_BACKLIGHT_NK65
//#error RGB_BACKLIGHT_NK65 not defined, recheck config.h
//#endif

#include "nk65.h"
#include "drivers/led/issi/is31fl3733.h"

/* Indicator LEDS are part of the LED driver
 * Top LED is blue only. LED driver 2 RGB 7 Green channel
 * Middle LED is blue and red. LED driver 2 RGB 6 Red and Blue channel
 * Bottom LED is red only LED driver 2 RGB 6 Green channel.
 */
#ifdef RGB_BACKLIGHT_NK65
    bool led_update_kb(led_t led_state) {
        bool res = led_update_user(led_state);
        if(res) {
            if (led_state.caps_lock) {
                IS31FL3733_set_color( 7+64-1, 0, 255, 0 );
            } else {
                IS31FL3733_set_color( 7+64-1, 0, 0, 0 );
            }
        }
        return res;
    }

    __attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t state) {
        uint8_t R = 0;
        uint8_t G = 0;
        uint8_t B = 0;
        if (state & (1UL << 1)) {
            R = 255;
            B = 255;
        }
        if (state & (1UL << 2)) {
            G = 255;
        }

        IS31FL3733_set_color( 6+64-1, R, G, B );
    return state;
    }
#endif

#ifdef RGB_MATRIX_ENABLE
    const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    /* Refer to IS31 manual for these locations
    *   driver
    *   |  R location
    *   |  |      G location
    *   |  |      |      B location
    *   |  |      |      | */
        {0, B_1,   A_1,   C_1}, //LA1
        {0, E_1,   D_1,   F_1}, //LA2
        {0, H_1,   G_1,   I_1}, //LA3
        {0, K_1,   J_1,   L_1}, //LA4
        {0, B_2,   A_2,   C_2}, //LA5
        {0, E_2,   D_2,   F_2}, //LA6
        {0, H_2,   G_2,   I_2}, //LA7
        {0, K_2,   J_2,   L_2}, //LA8
        {0, B_3,   A_3,   C_3}, //LA9
        {0, E_3,   D_3,   F_3}, //LA10
        {0, H_3,   G_3,   I_3}, //LA11
        {0, K_3,   J_3,   L_3}, //LA12
        {0, B_4,   A_4,   C_4}, //LA13
        {0, E_4,   D_4,   F_4}, //LA14
        {0, H_4,   G_4,   I_4}, //LA15
        {0, K_4,   J_4,   L_4}, //LA16
        {0, B_5,   A_5,   C_5}, //LA17
        {0, E_5,   D_5,   F_5}, //LA18
        {0, H_5,   G_5,   I_5}, //LA19
        {0, K_5,   J_5,   L_5}, //LA20
        {0, B_6,   A_6,   C_6}, //LA21
        {0, E_6,   D_6,   F_6}, //LA22
        {0, H_6,   G_6,   I_6}, //LA23
        {0, K_6,   J_6,   L_6}, //LA24
        {0, B_7,   A_7,   C_7}, //LA25
        {0, E_7,   D_7,   F_7}, //LA26
        {0, H_7,   G_7,   I_7}, //LA27
        {0, K_7,   J_7,   L_7}, //LA28
        {0, B_8,   A_8,   C_8}, //LA29
        {0, E_8,   D_8,   F_8}, //LA30
        {0, H_8,   G_8,   I_8}, //LA31
        {0, K_8,   J_8,   L_8}, //LA32
        {0, B_9,   A_9,   C_9}, //LA33
        {0, E_9,   D_9,   F_9}, //LA34
        {0, H_9,   G_9,   I_9}, //LA35
        {0, K_9,   J_9,   L_9}, //LA36
        {0, B_10,  A_10,  C_10}, //LA37
        {0, E_10,  D_10,  F_10}, //LA38
        {0, H_10,  G_10,  I_10}, //LA39
        {0, K_10,  J_10,  L_10}, //LA40
        {0, B_11,  A_11,  C_11}, //LA41
        {0, E_11,  D_11,  F_11}, //LA42
        {0, H_11,  G_11,  I_11}, //LA43
        {0, K_11,  J_11,  L_11}, //LA44
        {0, B_12,  A_12,  C_12}, //LA45
        {0, E_12,  D_12,  F_12}, //LA46
        {0, H_12,  G_12,  I_12}, //LA47
        {0, K_12,  J_12,  L_12}, //LA48
        {0, B_13,  A_13,  C_13}, //LA49
        {0, E_13,  D_13,  F_13}, //LA50
        {0, H_13,  G_13,  I_13}, //LA51
        {0, K_13,  J_13,  L_13}, //LA52
        {0, B_14,  A_14,  C_14}, //LA53
        {0, E_14,  D_14,  F_14}, //LA54
        {0, H_14,  G_14,  I_14}, //LA55
        {0, K_14,  J_14,  L_14}, //LA56
        {0, B_15,  A_15,  C_15}, //LA57
        {0, E_15,  D_15,  F_15}, //LA58
        {0, H_15,  G_15,  I_15}, //LA59
        {0, K_15,  J_15,  L_15}, //LA60
        {0, B_16,  A_16,  C_16}, //LA61
        {0, E_16,  D_16,  F_16}, //LA62
        {0, H_16,  G_16,  I_16}, //LA63
        {0, K_16,  J_16,  L_16}, //LA64

        {1, B_1,   A_1,   C_1}, //LB1
        {1, E_1,   D_1,   F_1}, //LB2
        {1, H_1,   G_1,   I_1}, //LB3
        {1, K_1,   J_1,   L_1}, //LB4
        {1, B_2,   A_2,   C_2}, //LB5
    };

    led_config_t g_led_config = { {

    // LA1,  LA5,  LA9,  LA13, LA17, LA21, LA25, LA29, LA33, LA37, LA41, LA45, LA49, LA53, LB1,
    // LA2,  LA6,  LA10, LA14, LA18, LA22, LA26, LA30, LA34, LA38, LA42, LA46, LA50,  ---, LB2,
    // LA3,  LA7,  LA11, LA15, LA19, LA23, LA27, LA31, LA35, LA39, LA43, LA47, LA54, LA55, LB5,
    // LA4,  ---,   LA8, LA12, LA16, LA20, LA24, LA28, LA32, LA36, LA40, LA44, LA51, LA52, LB3,
    // LA57, LA58, LA59,  ---,  ---,  ---, LA60,  ---,  ---, LA48, LA62, LA63, LA64, LA56, LB4
        {  1-1,  5-1,  9-1, 13-1, 17-1, 21-1, 25-1, 29-1, 33-1, 37-1, 41-1, 45-1, 49-1, 53-1, 1+64-1 },
        {  2-1,  6-1, 10-1, 14-1, 18-1, 22-1, 26-1, 30-1, 34-1, 38-1, 42-1, 46-1, 50-1,  255, 2+64-1 },
        {  3-1,  7-1, 11-1, 15-1, 19-1, 23-1, 27-1, 31-1, 35-1, 39-1, 43-1, 47-1, 54-1, 55-1, 5+64-1 },
        {  4-1,  255,  8-1, 12-1, 16-1, 20-1, 24-1, 28-1, 32-1, 36-1, 40-1, 44-1, 51-1, 52-1, 3+64-1 },
        { 57-1, 58-1, 59-1,  255,  255,  255, 60-1,  255,  255, 48-1, 62-1, 63-1, 64-1, 56-1, 4+64-1 }
    }, {

    // LA1..LA60
        {0,0}, {4,16}, {6,32}, {10,48}, {16,0}, {24,16}, {28,32}, {36,48}, {32,0}, {40,16}, {44,32}, {52,48},
        {48,0}, {56,16}, {60,32}, {68,48}, {64,0}, {72,16}, {76,32}, {84,48}, {80,0}, {88,16}, {92,32}, {100,48},
        {96,0}, {104,16}, {108,32}, {116,48}, {112,0}, {120,16}, {124,32}, {132,48}, {128,0}, {136,16}, {140,32},
        {148,48}, {144,0}, {152,16}, {156,32}, {164,48}, {160,0}, {168,16}, {172,32}, {180,48}, {176,0}, {184, 16}, {188,32},
        {160,64}, {192,0}, {200,16}, {210,48}, {224,48}, {216,0}, {220,16}, {214,32}, {224,64}, {2,64}, {22,64}, {42,64}, {102,64},
        {255,255},// LA61 does not exit, dummy
        //LA62..LB5
        {176,64}, {192,64}, {208,64}, {240,0}, {240,16}, {240,48}, {240,64}, {240,32}
    }, {

        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    } };
#endif
