/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Defines names for use in layer keycodes and the keymap
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
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_RP] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RCBR),
    [TD_LP] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LCBR),
    // [TD_LB]= ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LT),
    // [TD_RB]= ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_GT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |CAPS |    |NUMLK|  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[BASE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┐
	     KC_A,	  KC_Z,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_LCTL,KC_Q), KC_S,   KC_D,	KC_F,	KC_G,		   KC_H,	KC_J,	KC_K,	  KC_L,	  MT(MOD_RCTL, KC_M),
    //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_LSFT, KC_W), KC_X,	KC_C,	KC_V,	KC_B,		  KC_SLSH,	KC_N,	KC_SCLN, KC_COMM, MT(MOD_RSFT,KC_DOT ),
    //└─┬──────┴─┬──────┴┬────┴───┬────────────────┘    └────────┴────────┴───────┬┴───────┬┴───┬───┬┘
    //  |ESC/META|  ALT  |ENTER(SYM)|                                             |SPC(NUM)|DEL |TAB|
KC_1,	MT(MOD_LGUI, KC_ESC), MT(MOD_LALT,KC_QUOT), LT(SYMB, KC_ENT), 				
                                        KC_CAPS,		KC_NUM,	
                                                                        LT(NUMB, KC_SPC), KC_DEL, KC_TAB,		KC_4
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   %  |   @  |   [  |   ]  |   \  |                      |      |      |   ^  |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   #  |   !  |   (  |   )  |   |  |                      |   _  |   '  |   "  |   ~  |   `  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   $  |   £  |   {  |   }  |   &  |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[SYMB] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┐
           KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,      KC_CIRC,  KC_AMPR, KC_ASTR, KC_BSLS,KC_TILD,
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_LCTL,KC_HASH), KC_VOLU, KC_DQT,KC_LBRC ,TD(TD_LP),  TD(TD_RP), KC_RBRC ,KC_MINS, KC_UNDS, MT(MOD_RCTL,KC_PIPE),
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_RSFT,KC_PERC), KC_VOLD,DM_REC1,DM_PLY1, DM_RSTP,      KC_GRV,  KC_QUES, KC_COLN, XXXXXXX, KC_RSFT,
        //└─┬──────┴─┬──────┴┬───────┴┬───────┴────────┘    └────────┴───────┬┴───────┬┴───────┬┴───────┬┘
_______,     _______, _______, _______,        _______,_______,               KC_EQL,  _______, _______,   _______
        //  └────────┴───────┴────────┘                                      └────────┴────────┴────────┘
),

/* NAVNUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      | PgUp |  UP  | PgDn |      |                      |   /  |   7  |   8  |   9  |   -  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | Home | Left | Down | Right| End  |                      |   =  |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |  INS |      |      |  |CAPS |    |NUMLK|  |   0  |   1  |   2  |   3  |   *  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[NUMB] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┐
           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8, 	KC_9, 	 KC_0,
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_LCTL,KC_HOME),KC_PGUP, KC_PGDN, KC_END, KC_F11,       KC_F12,  KC_LEFT, KC_UP,   KC_DOWN, MT(MOD_RCTL,KC_RGHT),
        //├────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┤
MT(MOD_RSFT,KC_F1), KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   MT(MOD_RSFT,KC_F10),
        //└─┬──────┴─┬──────┴┬────┴───┬───────┴────────┘    └────────┴───────┬┴───────┬┴───────┬┴───────┬┘
_______,     _______, _______,C(KC_PIPE),  	   _______,_______,               _______, KC_MPLY, KC_MNXT,   _______
        //  └────────┴───────┴────────┘                                      └────────┴────────┴────────┘
),

};


#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false; 
    }
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
			tap_code(KC_MS_UP);
        } else {
            tap_code(KC_MS_DOWN);
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code16(S(KC_MS_WH_DOWN));
        } else {
            tap_code16(S(KC_MS_WH_UP));
        }
    } else if (index == 3) { // Right encoder
        if (clockwise) {
            tap_code(KC_MS_RIGHT);
        } else {
            tap_code(KC_MS_LEFT);
        }
    }

    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master() && is_keyboard_left()) {
        return OLED_ROTATION_90;
    } else {
        return OLED_ROTATION_270;
    }
}
bool oled_task_kb(void) {
   if (!oled_task_user()) {
       return false;
   }
   if (is_keyboard_master()) {
       // Host Keyboard Layer Status
       oled_write_P(PSTR("LAYER:\n"), false);
       oled_write_P(PSTR("\n"), false);
	   
       switch (get_highest_layer(layer_state)) {
           case BASE:
               oled_write_P(PSTR("DEFAULT\n\n\n\n"), false);
               break;
           case SYMB:
               oled_write_P(PSTR("SYMBOLS\n\n\n\n"), false);
               break;
           case NUMB:
               oled_write_P(PSTR("NUMNAV\n\n\n\n"), false);
               break;
           default:
               oled_write_ln_P(PSTR("Undefined"), false);
       }
    } else {
        static const char PROGMEM my_logo[] = {
		// Paste the code from the previous step below this line!
    	// 'waterfowl for OLED', 64x128px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0xc0, 0x40, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0xc0, 0x40, 0x20, 0x10, 0x10, 0x08, 0x0c, 0x04, 0x04, 0x02, 0x02, 0x02, 0x01, 
0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x1a, 0x26, 0x40, 
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 
0x1c, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1e, 0x16, 0x1c, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x03, 0x0c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfc, 0xff, 
0x78, 0xf8, 0xfc, 0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xfc, 
0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1e, 0x1c, 0x1c, 0x14, 0x10, 0x10, 0x08, 0x08, 0x10, 0x10, 
0x10, 0x10, 0x10, 0x30, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x38, 0x7c, 0x7e, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xc0, 0x38, 0x0e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 
0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3c, 0x03, 0x80, 
0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x7f, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x04, 0x0c, 0x0c, 0x0c, 0x04, 0x07, 0x02, 0x03, 0x01, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x02, 0x06, 0x06, 0x06, 
0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };

        oled_write_raw_P(my_logo, sizeof(my_logo));
    }    
    return true;
}
#endif
