/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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


keyevent_t x_hi = {
    .key = (keypos_t){.row = 5, .col = 1},
    .pressed = false
};

keyevent_t x_low = {
    .key = (keypos_t){.row = 5, .col = 2},
    .pressed = false
};

keyevent_t y_hi = {
    .key = (keypos_t){.row = 5, .col = 0},
    .pressed = false
};

keyevent_t y_low = {
    .key = (keypos_t){.row = 5, .col = 3},
    .pressed = false
};

void matrix_scan_user(void) {

    if (IS_PRESSED(x_hi)) {
        x_hi.pressed = false;
        x_hi.time = (timer_read() | 1);
        action_exec(x_hi);
    }
    if (IS_PRESSED(x_low)) {
        x_low.pressed = false;
        x_low.time = (timer_read() | 1);
        action_exec(x_low);
    }
    if (IS_PRESSED(y_hi)) {
        y_hi.pressed = false;
       y_hi.time = (timer_read() | 1);
        action_exec(y_hi);
    }
    if (IS_PRESSED(y_low)) {
        y_low.pressed = false;
        y_low.time = (timer_read() | 1);
        action_exec(y_low);
    }

    int16_t x = analogReadPin(GP27);
    int16_t y = analogReadPin(GP28);
    if(x > 920){
        x_hi.pressed = true;
        x_hi.time = (timer_read() | 1);
        action_exec(x_hi);
        wait_ms(5);
    }else if(x< 550){
        x_low.pressed = true;
        x_low.time = (timer_read() | 1);
        action_exec(x_low);
        wait_ms(5);
    }
    if(y > 920){
        y_hi.pressed = true;
        y_hi.time = (timer_read() | 1);
        action_exec(y_hi);
        wait_ms(5);
    }else if(y < 550){
        y_low.pressed = true;
        y_low.time = (timer_read() | 1);
        action_exec(y_low);
        wait_ms(5);
     }
}
