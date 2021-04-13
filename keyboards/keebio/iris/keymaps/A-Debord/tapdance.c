#include "keymap.h"
#include "tapdance.h"
#include "quantum.h"

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_UNKNOWN
} td_state_t;



td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if(!state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }
    else return TD_UNKNOWN;
}

void rbrace_finished(qk_tap_dance_state_t *state,void *user_data){
    int Rbrace = cur_dance(state);

    switch(Rbrace){
        case TD_SINGLE_TAP: tap_code16(KC_RPRN); break;
        case TD_SINGLE_HOLD: tap_code(KC_RBRACKET); break;
        case TD_DOUBLE_TAP: tap_code16(KC_RCBR); break;
    }
}

void lbrace_finished(qk_tap_dance_state_t *state,void *user_data){
    int Lbrace = cur_dance(state);

    switch(Lbrace){
        case TD_SINGLE_TAP: tap_code16(KC_LPRN); break;
        case TD_SINGLE_HOLD: tap_code(KC_LBRACKET); break;
        case TD_DOUBLE_TAP: tap_code16(KC_LCBR); break;
    }
}

// raise
static int Raise = TD_NONE;

// avoid missing key down
void upper_each(qk_tap_dance_state_t *state, void *user_data) {
    if(state->pressed){
        layer_on(_RAISE);
    } else {
        layer_off(_RAISE);
    }
}

void upper_finished(qk_tap_dance_state_t *state, void *user_data) {
    Raise = cur_dance(state);
    
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
    [TD_RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(upper_each, upper_finished, upper_reset),
    [TD_RBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rbrace_finished, NULL),
    [TD_LBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lbrace_finished, NULL)
};
