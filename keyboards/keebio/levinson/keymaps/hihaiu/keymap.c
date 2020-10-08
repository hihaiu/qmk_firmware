#include QMK_KEYBOARD_H
#include "keymap_finnish.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMPAD 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _FN 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  DVORAK,
  LOWER,
  RAISE,
  FN,
  ADJUST,
  COMM,                   // , | <
  DOT,                   // . | >
  SLSH,                  // / | ?
  SCLN,                  // ; | :
  QUOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Adjust|Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  FI_Q,    FI_W,    FI_E,    FI_R,    FI_T,    FI_Y,    FI_U,    KC_I,    FI_O,    FI_P,    KC_BSPC, \
  KC_ESC,  FI_A,    FI_S,    FI_D,    FI_F,    FI_G,    FI_H,    FI_J,    FI_K,    FI_L,    SCLN,    QUOT, \
  KC_LSFT, FI_Z,    FI_X,    FI_C,    FI_V,    FI_B,    FI_N,    FI_M,    COMM,    DOT,     SLSH,    KC_ENT , \
  KC_LCTL, KC_LGUI, KC_LALT, ADJUST,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      |      |      |   /  |   *  |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |   -  |   +  |   4  |   5  |   6  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower |Space |Space |Raise |   0  |   ,  |  .   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( \
  _______, _______, KC_UP, _______, _______, _______, FI_SLSH, FI_ASTR,   FI_7, FI_8   , FI_9  , KC_BSPC, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, FI_MINS, FI_PLUS, FI_4, FI_5   , FI_6  , FI_EQL, \
  _______, _______, _______, _______, _______, _______, _______, _______, FI_1, FI_2   , FI_3  , KC_ENT , \
  _______, _______, _______, _______, LOWER,   KC_SPC,  KC_SPC,  RAISE  , FI_0, KC_COMM, KC_DOT, _______ \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  FI_TILD, FI_EXLM, FI_AT,   FI_HASH, FI_DLR,  FI_PERC, FI_CIRC, FI_AMPR, FI_ASTR, FI_LPRN, FI_RPRN, KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   FI_UNDS, FI_PLUS, FI_LCBR, FI_RCBR, FI_PIPE, \
  BL_STEP, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,_______,_______,FI_LBRC, FI_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   €  |   £  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  FI_GRV,  FI_1,    FI_2,    FI_3,    FI_4,    FI_5,    FI_6,    FI_7,    FI_8,    FI_9,    FI_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   FI_MINS, FI_EQL,  FI_EURO, FI_PND, FI_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  Ö   |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, FI_ARNG, \
  _______, _______, KC_INS, KC_HOME, KC_PGUP, _______, _______, _______, _______, _______, FI_ODIA, FI_ADIA, \
  KC_LSFT, _______, KC_DEL, KC_END, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Numpad|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  NUMPAD, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_NUMPAD);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;

    case COMM:    // , | <
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          unregister_code16(KC_LSFT);  // Remove shift before sending the keycode
          register_code16(FI_LABK);
          register_code16(KC_LSFT);
        } else {
          register_code16(KC_COMM);
        }
      } else {
        unregister_code16(FI_LABK);
        unregister_code16(KC_COMM);
      }
      return false;
      break;

    case DOT:    // . | >
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(FI_RABK);
        } else {
          register_code16(KC_DOT);
        }
      } else {
        unregister_code16(FI_RABK);
        unregister_code16(KC_DOT);
      }
      return false;
      break;

    case SLSH:    // / | ?
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(FI_QUES);
        } else {
          register_code16(FI_SLSH);
        }
      } else {
        unregister_code16(FI_QUES);
        unregister_code16(FI_SLSH);
      }
      return false;
      break;

    case SCLN:    // ; | :
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(FI_COLN);
        } else {
          register_code16(FI_SCLN);
        }
      } else {
        unregister_code16(FI_COLN);
        unregister_code16(FI_SCLN);
      }
      return false;
      break;

    case QUOT:    // ' | "
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(FI_DQUO);
        } else {
          register_code16(FI_QUOT);
        }
      } else {
        unregister_code16(FI_DQUO);
        unregister_code16(FI_QUOT);
      }
      return false;
      break;
  }
  return true;
}
