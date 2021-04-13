#include "tapdance.h"
#include "quantum.h"

qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_ESC),
    [LSFT_LCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT,KC_NUMLOCK) 
};
