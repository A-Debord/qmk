#pragma once
#include "quantum.h"

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