#pragma once

// enum layer_number {
//   _BASE = 0,
//   _FUNCTION,
//   _NUMPAD,
//   _MACROS
// };

#ifdef OLED_ENABLE
  #ifdef OLED_FONT_ENABLE
  void write_layer_state(void);
  void write_host_led_state(void);
  void write_mod_state(void);
  #endif // OLED_FONT_ENABLE
void render_layer_state( uint16_t index );
void render_host_led_state( uint16_t index );
void render_mod_state( uint16_t index );
#endif // OLED_ENABLE
