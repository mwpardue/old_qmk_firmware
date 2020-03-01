/* Copyright 2019 funderburker
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
#include "tmo50.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

  DDRB |= (1 << PB0); //init B0
  PORTB &= ~(1 << PB0); //turn on B0
  DDRB |= (1 << PB1);
  PORTB |= (1<<PB1); //turn off B1
  DDRB |= (1 << PB2);
  PORTB |= (1<<PB2);
  DDRB |= (1 << PB3);
  PORTB |= (1<<PB3);
}

uint32_t layer_state_set_kb(uint32_t state)
{
  // if on layer 0, turn on B0 LED, otherwise off.
    if (biton32(state) == 0) {
        PORTB &= ~(1<<PB0);
    } else {
        PORTB |= (1<<PB0);
    }

  // if on layer 1, turn on B1 LED, otherwise off.
    if (biton32(state) == 1) {
        PORTB &= ~(1<<PB1);
    } else {
        PORTB |= (1<<PB1);
    }
  // if on layer 2, turn on B2 LED, otherwise off.
    if (biton32(state) == 2) {
        PORTB &= ~(1<<PB2);
    } else {
        PORTB |= (1<<PB2);
    }

  // if on layer 3, turn on B3 LED, otherwise off.
    if (biton32(state) == 3) {
        PORTB &= ~(1<<PB3);
    } else {
        PORTB |= (1<<PB3);
    }

    return layer_state_set_user(state);
}
