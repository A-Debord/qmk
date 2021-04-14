#include "defs.h"
#include "quantum.h"

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_UNKNOWN
} td_state_t;

typedef struct {
    uint16_t kc_single,kc_double,kc_hold;
} tap_dance_triple_t;

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

void tap_dance_triple_finished(qk_tap_dance_state_t *state,void *user_data){
    int dance = cur_dance(state);
    tap_dance_triple_t* keys = (tap_dance_triple_t*)user_data;

    switch(dance){
        case TD_SINGLE_TAP: tap_code16(keys->kc_single); break;
        case TD_SINGLE_HOLD: tap_code16(keys->kc_hold); break;
        case TD_DOUBLE_TAP: tap_code16(keys->kc_double); break;
    }
}

#define ACTION_TAP_DANCE_TRIPLE(KC_SINGLE,KC_DOUBLE,KC_HOLD) \
    { \
        .fn = {NULL, tap_dance_triple_finished, NULL}, \
        .user_data = (void *)&((tap_dance_triple_t){KC_SINGLE, KC_DOUBLE, KC_HOLD}), \
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
    // [ESC_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_ESC),
    [LSFT_CPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT,KC_CAPS),
    [RAISE_WIN] = ACTION_TAP_DANCE_FN_ADVANCED(upper_each, upper_finished, upper_reset),
    [RBRACES] = ACTION_TAP_DANCE_TRIPLE(KC_RPRN, KC_RCBR, KC_RBRACKET),
    [LBRACES] = ACTION_TAP_DANCE_TRIPLE(KC_LPRN, KC_LCBR, KC_LBRACKET)
};
