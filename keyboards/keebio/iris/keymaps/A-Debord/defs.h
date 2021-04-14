#ifndef DEFS_H
#define DEFS_H
#include "quantum.h"

// keymap

enum keyboard_keycodes {
  QWERTY = SAFE_RANGE,
   LOWER,
//   RAISE,
  NEW_SAFE_RANGE  // Important!
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// tapdance

enum {
    ESC_TAB,
    LSFT_CPS,
    RAISE_WIN,
    RBRACES,
    LBRACES
};


#endif /* DEFS_H */
