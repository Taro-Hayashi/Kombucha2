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
        JS_0, JS_1,
        JS_2, JS_3, JS_4,
        JS_5, JS_6, JS_7,
        JS_8, JS_9, MO(LIGHT),

            XXXXXXX,
        XXXXXXX, XXXXXXX,
            XXXXXXX
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
        RGB_MOD, RGB_RMOD, MO(LIGHT),

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

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(GP27, 512, 767, 1023),
    JOYSTICK_AXIS_IN(GP28, 512, 767, 1023),
};
