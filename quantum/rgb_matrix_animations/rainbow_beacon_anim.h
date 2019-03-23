#pragma once
#ifndef DISABLE_RGB_MATRIX_RAINBOW_BEACON

extern rgb_counters_t g_rgb_counters;
extern const rgb_led g_rgb_leds[DRIVER_LED_TOTAL];
extern rgb_config_t rgb_matrix_config;

bool rgb_matrix_rainbow_beacon(bool init, uint8_t iter) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  HSV hsv = { 0, rgb_matrix_config.sat, rgb_matrix_config.val };
  uint16_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 4);
  int16_t cos_value = 2 * (cos8(time) - 128);
  int16_t sin_value = 2 * (sin8(time) - 128);
  for (uint8_t i = led_min; i < led_max; i++) {
    point_t point = g_rgb_leds[i].point;
    hsv.h = ((point.y - 32) * cos_value + (point.x - 112) * sin_value) / 128 + rgb_matrix_config.hue;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // DISABLE_RGB_MATRIX_RAINBOW_BEACON
