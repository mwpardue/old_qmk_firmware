MCU_FAMILY = STM32

RGB_MATRIX_ENABLE = yes            # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE
RGB_MATRIX_DRIVER = IS31FL3733     # RGB matrix driver

# Remove unneeded SRC files
SRC += platforms/chibios/eeprom_stm32.c \
	   platforms/chibios/flash_stm32.c
SRC := $(filter-out keyboards/wilba_tech/wt_main.c keyboards/wilba_tech/wt_rgb_backlight.c,$(SRC))
