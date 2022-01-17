#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  ACC_A,
  ACC_E,
  ACC_I,
  ACC_O,
  ACC_U,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB        , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  , KC_Y   , KC_U   , KC_I  , KC_O    , KC_P    , KC_BSPC,
    KC_ESC        , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
    KC_LSFT       , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENTER,
    KC_MINUS       , KC_LCTL , KC_LALT , KC_LGUI , LT(_LOWER, KC_SPC) ,     KC_SPC, KC_SPC      , LT(_RAISE, KC_SPC) , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( 
  KC_ESC        , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B  , KC_J   , KC_L   , KC_U  , KC_Y    , KC_SCLN    , KC_BSPC,
  KC_TAB        , KC_A    , KC_R    , KC_S    , KC_T  , KC_G   , KC_M   , KC_N  , KC_E    , KC_I    , KC_O , KC_QUOT,
  KC_LSFT       , KC_X    , KC_C    , KC_D    , KC_V  , KC_Z   , KC_K   , KC_H  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENTER,
  KC_MINUS       , KC_LCTL , KC_LALT , KC_LGUI , LT(_LOWER, KC_SPC) ,     KC_SPC, KC_SPC      , LT(_RAISE, KC_SPC) , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
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
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
  _______ , KC_LPRN , KC_LBRACKET,KC_LCBR,KC_COLN ,KC_MINUS , KC_UNDS ,KC_EQUAL , KC_RCBR ,KC_RBRACKET,KC_RPRN, _______ ,
  _______ , _______ , _______ , _______ , KC_PIPE ,KC_GRAVE , KC_TILD ,KC_BSLASH, _______ , _______ , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ ,      _______,_______      , _______ , _______ , _______ , _______ , _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , ACC_U , KC_AMPR   , KC_ASTR    , KC_LPRN , KC_RPRN , KC_BSPC ,
_______ , ACC_A   , _______ , _______   , _______ , _______ , _______ , ACC_E     , ACC_I      , ACC_O   , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______   , _______    , _______ , _______ , _______ ,
_______ , _______ , _______ , _______ , _______ ,      _______,_______      , _______   , _______    , _______ , _______ , _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  COLEMAK, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  QWERTY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case ACC_A:
        if (record->event.pressed) {
            register_code(ES_ACUT);
            register_code(KC_A);
            unregister_code(KC_A);
        }
        return false;
        break;
    case ACC_E:
        if (record->event.pressed) {
            register_code(ES_ACUT);
            register_code(KC_E);
            unregister_code(KC_E);
        }
        return false;
        break;
    case ACC_I:
        if (record->event.pressed) {
            register_code(ES_ACUT);
            register_code(KC_I);
            unregister_code(KC_I);
        }
        return false;
        break;
    case ACC_O:
        if (record->event.pressed) {
            register_code(ES_ACUT);
            register_code(KC_O);
            unregister_code(KC_O);
        }
        return false;
        break;
    case ACC_U:
        if (record->event.pressed) {
            register_code(ES_ACUT);
            register_code(KC_U);
            unregister_code(KC_U);
        }
        return false;
        break;
  }
  return true;
}
