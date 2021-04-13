#include "quantum.h"

enum combos {
  QS_DEL,
  LM_BSPC
};

const uint16_t PROGMEM del_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QS_DEL] = COMBO(del_combo, KC_DEL),
  [LM_BSPC] = COMBO(bspc_combo, KC_BSPC)
};