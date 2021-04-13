#include "keymap.h"
#include "tapdance.h"
#include "quantum.h"

typedef enum {
    TD_NONE,
    TD_SINGLE_HOLD,
    TD_DOUBLE_HOLD,
} td_state_t;


// raise
static int Raise = TD_NONE;

void upper_finished(qk_tap_dance_state_t *state, void *user_data) {

    if(state->count==1 && state->pressed){
        Raise = TD_SINGLE_HOLD;
    }
    else if(state->count==2 && state->pressed){
        Raise = TD_DOUBLE_HOLD;
    }
    else{
        Raise=TD_NONE;
    }
    
    switch (Raise) {
        case TD_SINGLE_HOLD: layer_on(_RAISE); break;
        case TD_DOUBLE_HOLD: layer_on(_RAISE); register_mods(MOD_BIT(KC_RWIN)); break;
    }
}

void upper_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (Raise) {
        case TD_SINGLE_HOLD: layer_off(_RAISE); break;
        case TD_DOUBLE_HOLD: layer_off(_RAISE); unregister_mods(MOD_BIT(KC_RWIN)); break;
    }
    Raise = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_ESC),
    [LSFT_CPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT,KC_CAPS),
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, upper_finished, upper_reset)
};
