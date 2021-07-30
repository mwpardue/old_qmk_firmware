# MCU name
MCU = STM32F303
BOARD = QMK_PROTON_C

# Bootloader selection
BOOTLOADER = stm32-dfu

# Do not put the microcontroller into power saving mode
# when we get USB suspend event. We want it to keep updating
# backlight effects.
OPT_DEFS += -DNO_SUSPEND_POWER_DOWN

# Build Options
#   comment out to disable the options.
#
BACKLIGHT_ENABLE = no              # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no               # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes            # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE
RGB_MATRIX_DRIVER = IS31FL3733     # RGB matrix driver
BOOTMAGIC_ENABLE = lite            # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes              # Mouse keys
EXTRAKEY_ENABLE = yes              # Audio control and System control
CONSOLE_ENABLE = no                # Console for debug
COMMAND_ENABLE = no                # Commands for debug and configuration
SLEEP_LED_ENABLE = no              # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes                  # USB Nkey Rollover
AUDIO_ENABLE = no                  # Audio output on port C6
NO_USB_STARTUP_CHECK = no          # Disable initialization only when usb is plugged in

CIE1931_CURVE = yes

LAYOUTS = 65_ansi