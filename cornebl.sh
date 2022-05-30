#!/bin/sh

#bootloader=$(awk 'NR==1 {print; exit}' </Users/mpardue/git/qmk_firmware/keyboards/crkbd/keymaps/caracarn/rules.mk)
bootloader=$(sed '1!d;q' </Users/mpardue/git/qmk_firmware/keyboards/crkbd/keymaps/caracarn/rules.mk)

#echo "$bootloader"

if [[ ${bootloader::1} == "#" ]]
then
    gsed -i '1s/^.//' /Users/mpardue/git/qmk_firmware/keyboards/crkbd/keymaps/caracarn/rules.mk
    echo "Corne keymap now configured for DFU"
    newbootloader=$(sed '1!d;q' </Users/mpardue/git/qmk_firmware/keyboards/crkbd/keymaps/caracarn/rules.mk)
    echo "$newbootloader";
elif [[ ${bootloader::1} == "B" ]]
then
    gsed -i '1s/^/#/' /Users/mpardue/git/qmk_firmware/keyboards/crkbd/keymaps/caracarn/rules.mk
    echo "Corne keymap now configured for Caterina"
    newbootloader=$(sed '1!d;q' </Users/mpardue/git/qmk_firmware/keyboards/crkbd/keymaps/caracarn/rules.mk)
    echo "$newbootloader";
else
    echo "Corne rules.mk file has errors, aborting."; fi
