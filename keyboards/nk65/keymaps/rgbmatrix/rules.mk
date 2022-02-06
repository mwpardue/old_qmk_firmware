RGBLIGHT_ENABLE = no               # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes            # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE
RGB_MATRIX_DRIVER = IS31FL3733     # RGB matrix driver
BOOTMAGIC_ENABLE = yes            # Virtual DIP switch configuration

# Remove unneeded SRC files
SRC := $(filter-out keyboards/wilba_tech/wt_main.c keyboards/wilba_tech/wt_rgb_backlight.c drivers/led/issi/is31fl3733.c quantum/color.c i2c_master.c,$(SRC))
