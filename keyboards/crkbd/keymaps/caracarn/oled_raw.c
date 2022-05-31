#include QMK_KEYBOARD_H

#include "oled.h"

#ifdef OLED_FONT_ENABLE
void write_layer_state(void) {
    //char layer_name[11];

    switch (biton32(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Cole   mak"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Func  tion"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nav    Sym"), false);
            break;
        case _MACROS:
            oled_write_P(PSTR("Mirr   Num"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            //snprintf(layer_name, sizeof(layer_name), "%5X", layer_state);	// l in %5lX should instead depend on sizeof(layer_state_t)?
            oled_write_ln(get_u8_str(layer_state, ' '), false);
    }
}

void write_host_led_state(void) {
    oled_write_char((IS_HOST_LED_ON(USB_LED_NUM_LOCK) ? 'N' : ' '), false);
    oled_write_char(' ', false);
    oled_write_char((IS_HOST_LED_ON(USB_LED_CAPS_LOCK) ? 'C' : ' '), false);
    oled_write_char(' ', false);
    oled_write_char((IS_HOST_LED_ON(USB_LED_SCROLL_LOCK) ? 'S' : ' '), false);
}

void write_mod_state(void) {
	uint8_t mods = get_mods();

    oled_write_char((mods & MOD_BIT(KC_LEFT_SHIFT) ? '<' : ' '), false);
	oled_write_P(PSTR(" S "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_SHIFT) ? '>' : ' '), false);
    oled_advance_page(true);

    oled_write_char((mods & MOD_BIT(KC_LEFT_CTRL) ? '<' : ' '), false);
	oled_write_P(PSTR(" C "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_CTRL) ? '>' : ' '), false);
    oled_advance_page(true);

    oled_write_char((mods & MOD_BIT(KC_LEFT_ALT) ? '<' : ' '), false);
	oled_write_P(PSTR(" A "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_ALT) ? '>' : ' '), false);
    oled_advance_page(true);

    oled_write_char((mods & MOD_BIT(KC_LEFT_GUI) ? '<' : ' '), false);
	oled_write_P(PSTR(" G "), false);
    oled_write_char((mods & MOD_BIT(KC_RIGHT_GUI) ? '>' : ' '), false);
    oled_advance_page(true);
}
#endif  // OLED_FONT_ENABLE

#ifdef OLED_ENABLE
const char crkbd_bmp[] PROGMEM = {
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,
    0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,
    0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,
    0x00, 0x7F, 0x41, 0x41, 0x41, 0x3E,
    0x00, 0x00
};

const char box_top_bmp[] PROGMEM = {
    0x00, 0x00, 0x00, 0x80, 0x40, 0x20,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x20, 0x40, 0x80, 0x00,
    0x00, 0x00
};

const char box_bottom_bmp[] PROGMEM = {
    0x00, 0x00, 0x00, 0x01, 0x02, 0x04,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x04, 0x02, 0x01, 0x00,
    0x00, 0x00
};

const char base_bmp[] PROGMEM = {
	// Base Layer
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,
    0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,
    0x00, 0x26, 0x49, 0x49, 0x49, 0x32,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x00
};

const char funct_bmp[] PROGMEM = {
	// Function Layer
	0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,
    0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,
    0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x00
};

const char numpad_bmp[] PROGMEM = {
	// Numpad Layer
	0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,
    0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,
    0x00, 0x7F, 0x02, 0x1C, 0x02, 0x7F,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x00
};

const char macros_bmp[] PROGMEM = {
	// Macros Layer
	0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0x7F, 0x02, 0x1C, 0x02, 0x7F,
    0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x00
};

const char symbol_bmp[] PROGMEM = {
	// Symbol Layer
	0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0x26, 0x49, 0x49, 0x49, 0x32,
    0x00, 0x03, 0x04, 0x78, 0x04, 0x03,
    0x00, 0x7F, 0x02, 0x1C, 0x02, 0x7F,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x00
};

const char hex_bmp[] PROGMEM = {
	// Hex Layer
	0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,
    0x00, 0x63, 0x14, 0x08, 0x14, 0x63,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x00
};

// const char led_num_bmp[] PROGMEM = {
// 	// Num
// 	0b00111111,
// 	0b00000100,
// 	0b00001000,
// 	0b00111111,
// 	0x00,
// 	0b00111100,
// 	0b00100000,
// 	0b00111100,
// 	0x00,
// 	0b00111100,
// 	0b00000100,
// 	0b00111100,
// 	0b00000100,
// 	0b00111100
// };

// const char led_caps_bmp[] PROGMEM = {
// 	// Cap
// 	0b00111111,
// 	0b00100001,
// 	0b00110011,
// 	0x00,
// 	0b00111100,
// 	0b00010100,
// 	0b00111100,
// 	0x00,
// 	0b00111100,
// 	0b00010100,
// 	0b00011100
// };

// const char led_scroll_bmp[] PROGMEM = {
// 	// Sc
// 	0b00100111,
// 	0b00111101,
// 	0x00,
// 	0b00111100,
// 	0b00100100
// };

const char mod_left_bmp[] PROGMEM = {
    0x00, 0x00, 0xFF, 0x00
};

const char shift_bmp[] PROGMEM = {
	// Shift
	0x26, 0x49, 0x49, 0x49, 0x32, 0x00
};

const char ctrl_bmp[] PROGMEM = {
	// Ctrl
	0x3E, 0x41, 0x41, 0x41, 0x22, 0x00
};

const char alt_bmp[] PROGMEM = {
	// Alt
	0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00
};

const char gui_bmp[] PROGMEM = {
	// Gui
	0x3E, 0x41, 0x41, 0x51, 0x73, 0x00
};

const char mod_right_bmp[] PROGMEM = {
    0x00, 0xFF, 0x00, 0x00
};

void clear_range(uint16_t index, uint16_t size) {
	for( uint16_t i = 0; i < size; i++) {
		oled_write_raw_byte( 0x00, index + i );
	}
}

void render_crkbd_logo( uint16_t index) {
    oled_write_data_P(crkbd_bmp, index, sizeof(crkbd_bmp));
}

void render_box_top( uint16_t index ) {
    oled_write_data_P(box_top_bmp, index, sizeof(box_top_bmp));
}

void render_box_bottom( uint16_t index ) {
    oled_write_data_P(box_bottom_bmp, index, sizeof(box_bottom_bmp));
}

void render_layer_state( uint16_t index ) {
	// Should check passed indices are line-aligned..?
    switch (biton32(layer_state)) {
        case _BASE:
			oled_write_data_P(base_bmp, index, sizeof(base_bmp));
            break;
        case _FUNCTION:
			oled_write_data_P(funct_bmp, index, sizeof(funct_bmp));
            break;
        case _NUMPAD:
			oled_write_data_P(numpad_bmp, index, sizeof(numpad_bmp));
            break;
        case _MACROS:
			oled_write_data_P(macros_bmp, index, sizeof(macros_bmp));
            break;
        case _HEX:
			oled_write_data_P(hex_bmp, index, sizeof(hex_bmp));
            break;
        case _SYMBOL:
			oled_write_data_P(symbol_bmp, index, sizeof(symbol_bmp));
            break;
        default:
			// Could display the layer number binary as a grid of 2x3 bits
			clear_range( index, 32 );
    }
}

void write_or_clear( bool write_not_clear, uint16_t index, const char *data, uint16_t size ) {
	if( write_not_clear ) {
		oled_write_data_P( data, index, size );
	} else {
		clear_range( index, size );
	}
}

// void render_host_led_state( uint16_t index ) {
// 	write_or_clear( IS_HOST_LED_ON(USB_LED_NUM_LOCK), index, led_num_bmp, sizeof(led_num_bmp) );
// 	index += sizeof(led_num_bmp) + 1;
// 	write_or_clear( IS_HOST_LED_ON(USB_LED_CAPS_LOCK), index, led_caps_bmp, sizeof(led_caps_bmp) );
// 	index += sizeof(led_caps_bmp) + 1;
// 	write_or_clear( IS_HOST_LED_ON(USB_LED_SCROLL_LOCK), index, led_scroll_bmp, sizeof(led_scroll_bmp) );
// }

void render_mod_state( uint16_t index ) {
	// Should check passed index has enough room left to fit all the lines..?

	uint8_t mods = get_mods() | get_oneshot_mods();
	//write_or_clear( mods & MOD_BIT(KC_LEFT_SHIFT), index, shift_bmp, sizeof(shift_bmp) );
	//write_or_clear( mods & MOD_BIT(KC_RIGHT_SHIFT), index+32-sizeof(shift_bmp), shift_bmp, sizeof(shift_bmp) );
	//write_or_clear( mods & MOD_BIT(KC_LEFT_CTRL), index+32, ctrl_bmp, sizeof(ctrl_bmp) );
	//write_or_clear( mods & MOD_BIT(KC_RIGHT_CTRL), index+64-sizeof(ctrl_bmp), ctrl_bmp, sizeof(ctrl_bmp) );
	//write_or_clear( mods & MOD_BIT(KC_LEFT_ALT), index+64, alt_bmp, sizeof(alt_bmp) );
	//write_or_clear( mods & MOD_BIT(KC_RIGHT_ALT), index+96-sizeof(alt_bmp), alt_bmp, sizeof(alt_bmp) );
    oled_write_data_P( mod_left_bmp, index, sizeof(mod_left_bmp) );
    write_or_clear( mods & MOD_MASK_SHIFT || IS_HOST_LED_ON(USB_LED_CAPS_LOCK), index+sizeof(mod_left_bmp), shift_bmp, sizeof(shift_bmp) );
	write_or_clear( mods & MOD_MASK_CTRL, index+sizeof(mod_left_bmp)+sizeof(shift_bmp), ctrl_bmp, sizeof(ctrl_bmp) );
	write_or_clear( mods & MOD_MASK_ALT, index+sizeof(mod_left_bmp)+sizeof(shift_bmp)+sizeof(ctrl_bmp), alt_bmp, sizeof(alt_bmp) );
	write_or_clear( mods & MOD_MASK_GUI, index+sizeof(mod_left_bmp)+sizeof(shift_bmp)+sizeof(ctrl_bmp)+sizeof(alt_bmp), gui_bmp, sizeof(gui_bmp) );
    oled_write_data_P( mod_right_bmp, index+sizeof(mod_left_bmp)+sizeof(shift_bmp)+sizeof(ctrl_bmp)+sizeof(alt_bmp)+sizeof(gui_bmp), sizeof(mod_right_bmp) );
}
#endif  // OLED_ENABLE
