#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "definitions/layers.h"
#include "features/secrets.h"
#include "definitions/keycodes.h"
#include "features/caps_word.h"
#include "features/taphold.h"
#include "features/tapdance.h"
#include "features/capslock_timer.h"
#include "features/os_toggle.h"
#include "features/macros.h"
#include "features/combos.h"
#include "features/leader.h"
#include "features/default_mod_key.h"
#include "features/capitalize_key.h"
#include "features/select_word.h"
#include "features/window_swapper.h"
#include "features/custom_shortcuts.h"
#include "features/custom_shift.h"

void matrix_scan_keymap(void);
