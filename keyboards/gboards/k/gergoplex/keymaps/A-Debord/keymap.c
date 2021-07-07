/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Tap Dance declarations
enum {
    TD_RP,
    TD_LP,
    TD_RB,
    TD_LB,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_RP] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RCBR),
    [TD_LP] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LCBR),
    [TD_LB]= ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LT),
    [TD_RB]= ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_GT),
};

/* Combomap
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    ESC    |     |     |      |      |     |      |    |    BSPC      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |      |   BSPC   ENT    |     |      |    LES   COLN  GRT    |        | 
 * |-----+-----+-----+--RMB+-LMB--+		 |--------------------------------|
 * |      |   MINS    |     |     |      |    QUO   UNDR   |     |        |
 * `------+-----+-----+------+----'		 `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer */
[BASE] = LAYOUT_gergoplex(
    //┌────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┐
       KC_A,    KC_Z,    KC_E,    KC_R,    KC_T,  	     KC_Y,    KC_U,    KC_I,    KC_O, 	 KC_P, 
    //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_LCTL,KC_Q),KC_S,  KC_D,    KC_F,    KC_G,  	     KC_H,    KC_J,    KC_K,    KC_L, 	 MT(MOD_RCTL, KC_M),
    //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_RSFT, KC_W),KC_X, KC_C,    KC_V,    KC_B,  	     KC_SLSH, KC_N,    KC_SCLN, KC_COMM, MT(MOD_RSFT,KC_DOT ),
    //└─┬──────┴─┬──────┴┬────┴───┬────────────────┘    └────────┴────────┴───────┬┴───────┬┴───┬───┬┘
    //  |ESC/META|'/ALT|SPC(SYM)|                                               |SPC(NUM)|DEL |TAB|
MT(MOD_LGUI, KC_ESC), MT(MOD_LALT,KC_QUOT), LT(SYMB, KC_ENT),  
                                                        LT(NUMB, KC_SPC), KC_DEL, KC_TAB
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------.       ,--------------------------------.
 * |  !   |  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  |  \  |    ~   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |      |     |  "  |  `  | ({{ |      | }}) |  -  |  _  |     |    |   | 
 * |-----+-----+-----+-----+------+		 |--------------------------------|
 * |      |     |     |     | [<< |      | >>] |  ?  |     |     |   :    |
 * `------+-----+-----+------+----'		 `--------------------------------'
 *  				.-----------------.           .------------------.   
 *  				|    |     	|     | 		  |  =  |  ;  |      |
 *  				'-----------------'           '------------------' 
 */
[SYMB] = LAYOUT_gergoplex(

        //┌────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┐
           KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,      KC_CIRC,  KC_AMPR, KC_ASTR, KC_BSLS,KC_TILD,
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_LCTL,KC_HASH), XXXXXXX, KC_DQT, KC_GRV, TD(TD_LP),  TD(TD_RP), KC_MINS, KC_UNDS, XXXXXXX, MT(MOD_RCTL,KC_PIPE),
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_RSFT,KC_PERC), XXXXXXX, XXXXXXX, XXXXXXX,TD(TD_LB), TD(TD_RB), KC_QUES,  KC_COLN, XXXXXXX, KC_RSFT,
        //└─┬──────┴─┬──────┴┬────┴───┬───────┴────────┘    └────────┴───────┬┴───────┬┴───────┬┴───────┬┘
             _______, _______, _______,                                       KC_EQL,  _______, _______
        //  └────────┴───────┴────────┘                                      └────────┴────────┴────────┘
    ),
/* Keymap 2: Pad/Function layer*/
[NUMB] = LAYOUT_gergoplex(
        //┌────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┐
           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8, 	KC_9, 	 KC_0,
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_LCTL,KC_F11), KC_HOME, KC_PGUP, KC_PGDN, KC_END,      KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,MT(MOD_RCTL,KC_F12),
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_RSFT,KC_F1), KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   MT(MOD_RSFT,KC_F10),
        //└─┬──────┴─┬──────┴┬────┴───┬───────┴────────┘    └────────┴───────┬┴───────┬┴───────┬┴───────┬┘
             _______, _______,_______,  	                                  _______, KC_MPLY, KC_MNXT
        //  └────────┴───────┴────────┘                                      └────────┴────────┴────────┘
    )
};

  //     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  	 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
