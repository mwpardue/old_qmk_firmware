/* Copyright 2022 customMK
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


#include "crkbd.h"
#include "eeprom_driver.h"
#include <stdbool.h>
#include <print.h>
#include "flash/flash_spi.h"
#include "flash/flash_spi.c"
#include "ws2812.h"


void keyboard_post_init_kb(void) {
    #ifdef EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN
	    setPinOutput(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
		writePinHigh(EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN);
	#endif
}

/*
void housekeeping_task_kb(void) {
    #ifdef EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN
    static bool spiflash_tested = false;
    if(!spiflash_tested && timer_read32() > 3000) {
        spiflash_tested = true;
        flash_init();

        if(spi_flash_start()) {
            spi_write(0x9F);
            uint8_t jedec_id[3];
            spi_receive(jedec_id, sizeof(jedec_id));
            spi_stop();
            uprintf("Flash chip JEDEC ID: %02X %02X %02X\n", (int)jedec_id[0], (int)jedec_id[1], (int)jedec_id[2]);
        }
const uint8_t test_data[] = {0x01, 0x02, 0x03, 0x04};
        uint8_t recv_data[sizeof(test_data)] = {0};
        uprint("reading initial state of flash memory...\n");
        flash_read_block(0, recv_data, sizeof(recv_data));
        uprintf("initial state: %02X %02X %02X %02X\n", recv_data[0], recv_data[1], recv_data[2], recv_data[3]);


        uprintf("Erasing flash chip, please wait up to 200 seconds (typically 40 seconds)\n\n");

        if(flash_erase_chip() == FLASH_STATUS_SUCCESS) {

            uprint("Reading initial state of flash memory...\n");
            flash_read_block(0, recv_data, sizeof(recv_data));
            uprintf("Initial state: %02X %02X %02X %02X\n", recv_data[0], recv_data[1], recv_data[2], recv_data[3]);
            uprint("Writing test data...\n");
            uprintf("Test being written: %02X %02X %02X %02X\n", test_data[0], test_data[1], test_data[2], test_data[3]);
            flash_write_block(0, test_data, sizeof(test_data));
            uprint("Reading test data...\n");
            flash_read_block(0, recv_data, sizeof(recv_data));
            uprintf("Test data read from flash memory: %02X %02X %02X %02X\n", recv_data[0], recv_data[1], recv_data[2], recv_data[3]);

        }
    }

    #endif
}
*/

void board_init(void) {
    // B9 is configured as I2C1_SDA in the board file; that function must be
    // disabled before using B9 as I2C1_SDA
    setPinInputHigh(B9);
}

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
	// Left
	{{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
	{{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
	{{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
	{{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
	// Right
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
	{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
	{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
	{{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}}
};
#endif
