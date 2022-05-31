/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#define USE_SERIAL
#define SOFT_SERIAL_PIN A15
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7
#define SERIAL_USART_TIMEOUT 20

/* ws2812 RGB LED */
#define RGB_DI_PIN      D3

#ifdef RGBLIGHT_ENABLE
#    define RGBLED_NUM 54 // Number of LEDs
#    define RGBLED_SPLIT \
        { 27, 27 }
#    define RGBLIGHT_SPLIT
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGBLED_NUM       54 // Number of LEDs
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGB_MATRIX_SPLIT \
        { 27, 27 }
#    define SPLIT_TRANSPORT_MIRROR
#endif

#ifdef MATRIX_ROW_PINS
    #undef MATRIX_ROW_PINS
#endif
#define MATRIX_ROW_PINS \
    { A4, B8, A3, B10 }

#ifdef MATRIX_COL_PINS
    #undef MATRIX_COL_PINS
#endif
#define MATRIX_COL_PINS \
    { A7, A6, A5, A1, B13, B14 }

#define DIODE_DIRECTION COL2ROW

// FRAM configuration
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A0
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 4 // 48MHz / 4 = 12MHz; max supported by MB85R64 is 20MHz
#define EXTERNAL_EEPROM_BYTE_COUNT 8192
#define EXTERNAL_EEPROM_PAGE_SIZE 64 // does not matter for FRAM, just sets the RAM buffer size in STM32F chip
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 8191


// External flash configuration
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B12
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 1  // 48MHz; max supported by W25Q128JV is 133MHz
#define EXTERNAL_FLASH_BYTE_COUNT (16 * 1024 * 1024)  //128Mbit or 16MByte
#define EXTERNAL_FLASH_PAGE_SIZE 256
#define EXTERNAL_FLASH_SPI_TIMEOUT 200000 //datasheet max is 200 seconds for flash chip erase

// SPI Configuration (needed for FRAM and FLASH)
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B3
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN B5
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN B4
#define SPI_MISO_PAL_MODE 5

// I2C Configuration (optional example, can use for OLED, etc.)
#define I2C_DRIVER I2CD1
#define I2C_SCL_PIN B6
#define I2C_SDA_PIN B9
#define I2C_SCL_PAL_MODE 4
#define I2C_SDA_PAL_MODE 4

#define I2C1_CLOCK_SPEED 100000
#define I2C1_DUTY_CYCLE STD_DUTY_CYCLE
