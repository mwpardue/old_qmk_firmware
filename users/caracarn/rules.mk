SRC += caracarn.c
SRC += definitions/keycodes.c

ifneq ($(PLATFORM),CHIBIOS)
    ifneq ($(strip $(LTO_SUPPORTED)), no)
        LTO_ENABLE        = yes
    endif
endif

SECRETS_ENABLE ?= no
ifeq ($(strip $(SECRETS_ENABLE)), yes)
    SRC += $(USER_PATH)/features/secrets.c
    OPT_DEFS += -DSECRETS_ENABLE
endif

ACHORDION_ENABLE ?= no
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
    SRC += $(USER_PATH)/features/achordion.c
    OPT_DEFS += -DACHORDION_ENABLE
endif

SMART_CASE_ENABLE ?= no
ifeq ($(strip $(SMART_CASE_ENABLE)), yes)
    SRC += $(USER_PATH)/features/smart_case.c
    OPT_DEFS += -DSMART_CASE_ENABLE
endif

CUSTOM_ONESHOT_MODS_ENABLE ?= no
ifeq ($(strip $(CUSTOM_ONESHOT_MODS_ENABLE)), yes)
    SRC += $(USER_PATH)/features/custom_oneshot_mods.c
    OPT_DEFS += -DCUSTOM_ONESHOT_MODS_ENABLE
endif

SMART_THUMB_KEYS_ENABLE ?= no
ifeq ($(strip $(SMART_THUMB_KEYS_ENABLE)), yes)
    SRC += $(USER_PATH)/features/smart_thumb_keys.c
    OPT_DEFS += -DSMART_THUMB_KEYS_ENABLE
endif

CAPSWORD_ENABLE ?= no
ifeq ($(strip $(CAPSWORD_ENABLE)), yes)
    SRC += $(USER_PATH)/features/caps_word.c
    OPT_DEFS += -DCAPSWORD_ENABLE
endif

TAPHOLD_ENABLE ?= no
ifeq ($(strip $(TAPHOLD_ENABLE)), yes)
    SRC += $(USER_PATH)/features/taphold.c
    OPT_DEFS += -DTAPHOLD_ENABLE
endif

DEFAULT_MOD_KEY_ENABLE ?= no
ifeq ($(strip $(DEFAULT_MOD_KEY_ENABLE)), yes)
    SRC += $(USER_PATH)/features/default_mod_key.c
    OPT_DEFS += -DDEFAULT_MOD_KEY_ENABLE
endif

CAPITALIZE_KEY_ENABLE ?= no
ifeq ($(strip $(CAPITALIZE_KEY_ENABLE)), yes)
    SRC += $(USER_PATH)/features/capitalize_key.c
    OPT_DEFS += -DCAPITALIZE_KEY_ENABLE
endif

TAP_DANCE_ENABLE ?= no
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += $(USER_PATH)/features/tapdance.c
    OPT_DEFS += -DTAP_DANCE_ENABLE
endif

CAPSLOCK_TIMER_ENABLE ?= no
ifeq ($(strip $(CAPSLOCK_TIMER_ENABLE)), yes)
    SRC += $(USER_PATH)/features/capslock_timer.c
    OPT_DEFS += -DCAPSLOCK_TIMER_ENABLE
endif

OS_TOGGLE_ENABLE ?= no
ifeq ($(strip $(OS_TOGGLE_ENABLE)), yes)
    SRC += $(USER_PATH)/features/os_toggle.c
    OPT_DEFS += -DOS_TOGGLE_ENABLE
endif

MACRO_ENABLE ?= no
ifeq ($(strip $(MACRO_ENABLE)), yes)
    SRC += $(USER_PATH)/features/macros.c
    OPT_DEFS += -DMACRO_ENABLE
endif

COMBO_ENABLE ?= no
ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += $(USER_PATH)/features/combos.c
    OPT_DEFS += -DCOMBO_ENABLE
endif

LEADER_ENABLE ?= no
ifeq ($(strip $(LEADER_ENABLE)), yes)
    SRC += $(USER_PATH)/features/leader.c
    OPT_DEFS += -DLEADER_ENABLE
endif

SELECT_WORD_ENABLE ?= no
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
    SRC += $(USER_PATH)/features/select_word.c
    OPT_DEFS += -DSELECT_WORD_ENABLE
endif

WINDOW_SWAPPER_ENABLE ?= no
ifeq ($(strip $(WINDOW_SWAPPER_ENABLE)), yes)
    SRC += $(USER_PATH)/features/window_swapper.c
    OPT_DEFS += -DWINDOW_SWAPPER_ENABLE
endif

SHORTCUTS_ENABLE ?= no
ifeq ($(strip $(SHORTCUTS_ENABLE)), yes)
    SRC += $(USER_PATH)/features/custom_shortcuts.c
    OPT_DEFS += -DSHORTCUTS_ENABLE
endif

CUSTOM_SHIFT_ENABLE ?= no
ifeq ($(strip $(CUSTOM_SHIFT_ENABLE)), yes)
    SRC += $(USER_PATH)/features/custom_shift.c
    OPT_DEFS += -DCUSTOM_SHIFT_ENABLE
endif
