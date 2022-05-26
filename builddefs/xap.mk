# Copyright 2022 Nick Brassel (@tzarc)
# SPDX-License-Identifier: GPL-2.0-or-later

XAP_FILES := $(shell ls -1 data/xap/* | sort | xargs echo)
ifneq ("$(wildcard $(KEYBOARD_PATH_1)/xap.hjson)","")
	XAP_FILES += $(KEYBOARD_PATH_1)/xap.hjson
endif
ifneq ("$(wildcard $(KEYBOARD_PATH_2)/xap.hjson)","")
	XAP_FILES += $(KEYBOARD_PATH_2)/xap.hjson
endif
ifneq ("$(wildcard $(KEYBOARD_PATH_3)/xap.hjson)","")
	XAP_FILES += $(KEYBOARD_PATH_3)/xap.hjson
endif
ifneq ("$(wildcard $(KEYBOARD_PATH_4)/xap.hjson)","")
	XAP_FILES += $(KEYBOARD_PATH_4)/xap.hjson
endif
ifneq ("$(wildcard $(KEYBOARD_PATH_5)/xap.hjson)","")
	XAP_FILES += $(KEYBOARD_PATH_5)/xap.hjson
endif
ifneq ("$(wildcard $(KEYMAP_PATH)/xap.hjson)","")
	XAP_FILES += $(KEYMAP_PATH)/xap.hjson
endif

$(KEYMAP_OUTPUT)/src/info_json_gz.h: $(INFO_JSON_FILES)
	@$(SILENT) || printf "$(MSG_GENERATING) $@" | $(AWK_CMD)
	$(eval CMD=$(QMK_BIN) xap-generate-info-h -o "$(KEYMAP_OUTPUT)/src/info_json_gz.h" -kb $(KEYBOARD) -km $(KEYMAP))
	@$(BUILD_CMD)

$(KEYMAP_OUTPUT)/src/xap_generated.inl: $(XAP_FILES)
	@$(SILENT) || printf "$(MSG_GENERATING) $@" | $(AWK_CMD)
	$(eval CMD=$(QMK_BIN) xap-generate-qmk-inc -o "$(KEYMAP_OUTPUT)/src/xap_generated.inl" -kb $(KEYBOARD) -km $(KEYMAP))
	@$(BUILD_CMD)

$(KEYMAP_OUTPUT)/src/xap_generated.h: $(XAP_FILES)
	@$(SILENT) || printf "$(MSG_GENERATING) $@" | $(AWK_CMD)
	$(eval CMD=$(QMK_BIN) xap-generate-qmk-h -o "$(KEYMAP_OUTPUT)/src/xap_generated.h" -kb $(KEYBOARD) -km $(KEYMAP))
	@$(BUILD_CMD)

generated-files: $(KEYMAP_OUTPUT)/src/info_json_gz.h $(KEYMAP_OUTPUT)/src/xap_generated.inl $(KEYMAP_OUTPUT)/src/xap_generated.h

VPATH += $(KEYMAP_OUTPUT)/src
