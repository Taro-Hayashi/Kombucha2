// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "analog.h"

// LAYERS
enum layer_number {
    BASE = 0,
    LOWER,
    UPPER,
    LIGHT,
};

// LAYOUT SETTINGS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        KC_A, KC_B,
        KC_C, KC_D, KC_E,
        KC_F, KC_G, KC_H,
        KC_I, KC_J, LT(LIGHT, KC_K),

            KC_W,
        KC_A,   KC_D,
            KC_S
    ),
  [LOWER] = LAYOUT(
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,

            XXXXXXX,
        XXXXXXX, XXXXXXX,
            XXXXXXX
    ),
  [UPPER] = LAYOUT(
        XXXXXXX, XXXXXXX,
        XXXXXXX,XXXXXXX, XXXXXXX,
        XXXXXXX,XXXXXXX, XXXXXXX,
        XXXXXXX, MO(UPPER), XXXXXXX,

            XXXXXXX,
        XXXXXXX, XXXXXXX,
            XXXXXXX
    ),
  [LIGHT] = LAYOUT(
        RGB_TOG, XXXXXXX,
        RGB_SAI, RGB_VAI, RGB_SPI,
        RGB_SAD, RGB_VAD, RGB_SPD,
        RGB_MOD, RGB_RMOD, LT(LIGHT, KC_K),

            XXXXXXX,
        XXXXXXX, XXXXXXX,
            XXXXXXX
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [LOWER] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [UPPER] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [LIGHT] = { ENCODER_CCW_CW(RGB_HUI, RGB_HUD)},
};


keypos_t key_up;
keypos_t key_left;
keypos_t key_right;
keypos_t key_down;
bool pressed_up;
bool pressed_down;
bool pressed_left;
bool pressed_right;

void matrix_init_user(void) {
    key_up.row = 5;
    key_up.col = 0;
    key_left.row = 5;
    key_left.col = 1;
    key_right.row = 5;
    key_right.col = 2;
    key_down.row = 5;
    key_down.col = 3;
}

void matrix_scan_user(void) {
    int16_t x = analogReadPin(GP27);
    int16_t y = analogReadPin(GP28);
    int8_t layer = layer_switch_get_layer(key_up);
    int16_t keycode_up = keymap_key_to_keycode(layer, key_up);
    int16_t keycode_left = keymap_key_to_keycode(layer, key_left);
    int16_t keycode_right = keymap_key_to_keycode(layer, key_right);
    int16_t keycode_down = keymap_key_to_keycode(layer, key_down);

    if(pressed_left == false && x > 920){
        register_code(keycode_left);
        pressed_left = true;
    }else if(pressed_left == true && x <920){
        unregister_code(keycode_left);
        pressed_left = false;
    }
    if(pressed_right == false && x < 550){
        register_code(keycode_right);
        pressed_right = true;
    }else if (pressed_right == true && x >550){
        unregister_code(keycode_right);
        pressed_right = false;
    }

    if(pressed_up == false && y > 920){
        register_code(keycode_up);
        pressed_up = true;
    }else if(pressed_up == true && y < 920){
        unregister_code(keycode_up);
        pressed_up = false;
    }

    if(pressed_down == false && y < 550){
        register_code(keycode_down);
        pressed_down = true;
    }else if(pressed_down == true && y > 550){
        unregister_code(keycode_down);
        pressed_down = false;
    }
}
