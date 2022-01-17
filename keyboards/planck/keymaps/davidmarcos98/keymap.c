#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum layers {
    _QWERTY,
    _COLEMAKDH,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _NUM,
    _SHORTCUTS,
    _ADJUST
};

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAKDH,
    COLEMAK,
    SHORTCUTS,
    ACC_A,
    ACC_E,
    ACC_I,
    ACC_O,
    ACC_U,
    SCALE_KC
};

#define IMPERIAL_MARCH_CUSTOM HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)

#define MEGALOVANIA_custom  Q__NOTE(_D4), Q__NOTE(_D4), H__NOTE(_D5), HD_NOTE(_A4), H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4),  Q__NOTE(_D4), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_C4), Q__NOTE(_C4), H__NOTE(_D5), HD_NOTE(_A4),  H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4), Q__NOTE(_D4), Q__NOTE(_F4), Q__NOTE(_G4),  Q__NOTE(_B3), Q__NOTE(_B3), H__NOTE(_D5), HD_NOTE(_A4), H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4),  Q__NOTE(_D4), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF3), Q__NOTE(_BF3), H__NOTE(_D5),  HD_NOTE(_A4), H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4), Q__NOTE(_D4), Q__NOTE(_F4),  Q__NOTE(_G4),

// Tap Dance declarations
enum {
    TD_ESC_CMD,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CMD] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_LGUI),
};

#define TABNUM LT(_NUM, KC_TAB)
#define NUM MO(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,----------------------------------------------------------------------------------.
     * | Tab* |   Q  |  W   |  F   |  P   |   B  |  J   |  L   |  U   |   Y  |  ;:  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | ESC  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '"  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   X  |   C  |   D  |   V  |   Z  |   K  |   H  |  ,<  |  .>  |  /?  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | HYPR | Shift| GUI  | Alt  |Lower*|    Space*   |Raise*| RAlt | RGui | RCtrl| MEH  |
     * `-----------------------------------------------------------------------------------'
     *
     * - Tap dance Ctrl/Esc
     * - Tap dance MOV/Space
     * - Tap dance NUM/Tab
     * - Tap dance Raise/Enter
     * - Tap dance Lower/Backspace
     */
    [_COLEMAKDH] = LAYOUT_planck_grid(
            KC_ESC        , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B  , KC_J   , KC_L   , KC_U  , KC_Y    , KC_SCLN    , KC_BSPC,
            TABNUM        , KC_A    , KC_R    , KC_S    , KC_T  , KC_G   , KC_M   , KC_N  , KC_E    , KC_I    , KC_O , KC_QUOT,
            KC_LSFT       , KC_X    , KC_C    , KC_D    , KC_V  , KC_Z   , KC_K   , KC_H  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENTER,
            KC_MINUS       , KC_LCTL , KC_LALT , KC_LGUI , LT(_LOWER, KC_SPC) ,     KC_SPC, KC_SPC      , LT(_RAISE, KC_SPC) , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT
            ),
    [_COLEMAK] = LAYOUT_planck_grid(
            TABNUM        , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G  , KC_J   , KC_L   , KC_U  , KC_Y    , KC_SCLN    , KC_BSPC,
            KC_ESC        , KC_A    , KC_R    , KC_S    , KC_T  , KC_D   , KC_H   , KC_N  , KC_E    , KC_I    , KC_O , KC_QUOT,
            KC_LSFT       , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_K   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENTER,
            KC_MINUS       , KC_LCTL , KC_LALT , KC_LGUI , LT(_LOWER, KC_SPC) ,     KC_SPC, KC_SPC      , LT(_RAISE, KC_SPC) , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT
            ),
    [_QWERTY] = LAYOUT_planck_grid(
            TABNUM        , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  , KC_Y   , KC_U   , KC_I  , KC_O    , KC_P    , KC_BSPC,
            KC_ESC        , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
            KC_LSFT       , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENTER,
            KC_MINUS       , KC_LCTL , KC_LALT , KC_LGUI , LT(_LOWER, KC_SPC) ,     KC_SPC, KC_SPC      , LT(_RAISE, KC_SPC) , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT
            ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |   \  |   -  |   =  |   [  |   ]  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      | **** |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(
            KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC ,
            _______ , KC_LPRN , KC_LBRACKET,KC_LCBR,KC_COLN ,KC_MINUS , KC_UNDS ,KC_EQUAL , KC_RCBR ,KC_RBRACKET,KC_RPRN, _______ ,
            _______ , _______ , _______ , _______ , KC_PIPE ,KC_GRAVE , KC_TILD ,KC_BSLASH, _______ , _______ , _______ , _______ ,
            _______ , _______ , _______ , _______ , _______ ,      _______,_______      , _______ , _______ , _______ , _______ , _______
            ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |   |  |   _  |   +  |   {  |   }  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             | **** |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
            KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , ACC_U , KC_AMPR   , KC_ASTR    , KC_LPRN , KC_RPRN , KC_BSPC ,
            _______ , ACC_A   , _______ , _______   , _______ , _______ , _______ , ACC_E     , ACC_I      , ACC_O   , _______ , _______ ,
            _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______   , _______    , _______ , _______ , _______ ,
            _______ , _______ , _______ , _______ , _______ ,      _______,_______      , _______   , _______    , _______ , _______ , _______
            ),


    /* NUM
     * ,-----------------------------------------------------------------------------------.
     * | **** |  F1  |  F2  |  F3  |  F4  |  F5  |      |   7  |   8  |   9  |   *  | Del  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |   4  |   5  |   6  |   +  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |  F11 |  F12 | Enter|   1  |   2  |   3  |   -  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |   0  |   ,  |   .  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUM] = LAYOUT_planck_grid(
            _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , XXXXXXX , KC_7 , KC_8    , KC_9    , KC_PAST , KC_DEL  ,
            XXXXXXX , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_BSPC , KC_4 , KC_5    , KC_6    , KC_PPLS , XXXXXXX ,
            XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F11  , KC_F12  , KC_ENT  , KC_1 , KC_2    , KC_3    , KC_PMNS , XXXXXXX ,
            XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX ,      XXXXXXX,XXXXXXX      , KC_0 , KC_COMM ,KC_DOT   , XXXXXXX , XXXXXXX
            ),

    /* SHORTCUTS
     * ,-----------------------------------------------------------------------------------.
     * | Tab  | F24  | F23  | F22  |      |      |      | KP7  | KP8  | KP9  |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Ctrl | F19  | F20  | F19  |      |      |      | KP4  | KP5  | KP6  |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift| F18  | F17  | F16  |      |      |      | KP1  | KP2  | KP3  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | HYPR |  GUI |  Alt |Lower*|    Space    |Raise*| RAlt | RGui | RCtrl| MEH  |
     * `-----------------------------------------------------------------------------------'
     *
     * This layer is for Macro and bind purpouses, such as complicated binds for OBS.
     * - Tap dance Raise/Enter
     * - Tap dance Lower/Backspace
     *
     * */
    [_SHORTCUTS] = LAYOUT_planck_grid(
            KC_TAB  , KC_F24  , KC_F23  , KC_F22 , XXXXXXX , XXXXXXX , XXXXXXX , KC_KP_7 , KC_KP_8 , KC_KP_9 , KC_NUMLOCK , XXXXXXX ,
            KC_LCTL , KC_F21  , KC_F20  , KC_F19 , XXXXXXX , XXXXXXX , XXXXXXX , KC_KP_4 , KC_KP_5 , KC_KP_6 , XXXXXXX    , XXXXXXX ,
            KC_LSFT , KC_F18  , KC_F17  , KC_F16 , XXXXXXX , XXXXXXX , XXXXXXX , KC_KP_1 , KC_KP_2 , KC_KP_3 , XXXXXXX    , XXXXXXX ,
            KC_LCTL , KC_HYPR , KC_LGUI , KC_LALT , MO(_LOWER)   ,       KC_SPC,KC_SPC      , MO(_RAISE)   , KC_ALGR , KC_RGUI , KC_RCTL   , KC_MEH
            ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * | Reset|Qwerty| RGB+ | Bri+ |      |      |      | Vol- | Play | Vol+ | Mute |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      | RGB- | Bri- | MOUS1| MOUS2| MOUSL| MOUSD| MOUSU| MOUSR|      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |BLtogg|BLstep|      |      |      |      | ACC0 | ACC1 | ACC2 |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      | **** |             | **** |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
            RESET   , SCALE_KC, RGB_HUI , RGB_VAI , XXXXXXX , XXXXXXX, XXXXXXX , KC_VOLD, KC_MPLY, KC_VOLU, KC_MUTE, _______   ,
            COLEMAKDH  , XXXXXXX , RGB_HUD , RGB_VAD , KC_BTN1 , KC_BTN2, KC_MS_L , KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, SHORTCUTS ,
            COLEMAK , RGB_TOG , RGB_MOD , _______ , _______ , _______, _______ , KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
            QWERTY , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,     XXXXXXX,XXXXXXX      , _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
            )
};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
            break;
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
        case SCALE_KC:
            if (record->event.pressed) {
                float my_song[][2] = SONG(MEGALOVANIA_custom);
                PLAY_SONG(my_song);
            }
            return false;
            break;
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_F24:
            if (record->event.pressed){
                break;
            }
            break;
    }
}

void keyboard_post_init_user(void) {
    set_single_persistent_default_layer(_COLEMAKDH);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
   switch(get_highest_layer(layer_state)){
        case _RAISE:
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
            break;
        case _QWERTY:
            if (clockwise) {
                #ifdef MOUSEKEY_ENABLE
                    tap_code(KC_MS_WH_UP);
                #else
                    tap_code(KC_PGDN);
                #endif
            }
            else {
                #ifdef MOUSEKEY_ENABLE
                    tap_code(KC_MS_WH_DOWN);
                #else
                    tap_code(KC_PGUP);
                #endif
            }
    }
    return true;
}