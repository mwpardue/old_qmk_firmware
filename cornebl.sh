#!/bin/sh

bootloader=$(awk 'NR==1 {print; exit}' <(/Users/mpardue/git/qmk_firmware/keyboards/crkbd/keymaps/caracarn/rules.mk))

echo "$bootloader"
