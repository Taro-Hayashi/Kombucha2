// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include <math.h>

// LAYERS
enum layer_number {
    BASE = 0,
    LOWER = 1,
    UPPER = 2,
    LIGHT = 3,
};

// KEYCODES
enum ball_keycodes{
    BALL_SAFE_RANGE = SAFE_RANGE,
    CPI_I,
    CPI_D,
    ANG_I,
    ANG_D,
};


#define CPI_OPTIONS { 250, 500, 750, 1000, 1250 }
#define CPI_DEFAULT 3
#define ANGLE_OPTIONS { 35, 45, 55, 125, 135, 145, 215, 225, 235, 305, 315, 325 }
#define ANGLE_DEFAULT 5

// UNION FOR EEPROM
typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t angle_idx;
    };
} ballconfig_t;

// BALL SETTINGS
ballconfig_t ballconfig;
uint8_t cpi;
uint8_t angle;
uint16_t cpi_array[] = CPI_OPTIONS;
uint16_t angle_array[] = ANGLE_OPTIONS;
#define CPI_OPTION_SIZE (sizeof(cpi_array) / sizeof(uint16_t))
#define ANGLE_OPTION_SIZE (sizeof(angle_array) / sizeof(uint16_t))


// LAYOUT SETTINGS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        KC_A, KC_B,
        KC_C, KC_D, KC_E,
        KC_F, KC_G, KC_H,
        KC_I, LT(UPPER, KC_J), LT(LIGHT, KC_K)
    ),
  [LOWER] = LAYOUT(
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX
    ),
  [UPPER] = LAYOUT(
        XXXXXXX, XXXXXXX,
        CPI_D, CPI_I, XXXXXXX,
        ANG_D, ANG_I, XXXXXXX,
        XXXXXXX, MO(UPPER), XXXXXXX
    ),
  [LIGHT] = LAYOUT(
        RGB_TOG, XXXXXXX,
        RGB_SAI, RGB_VAI, RGB_SPI,
        RGB_SAD, RGB_VAD, RGB_SPD,
        RGB_MOD, RGB_RMOD, LT(LIGHT, KC_K)
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [LOWER] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [UPPER] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [LIGHT] = { ENCODER_CCW_CW(RGB_HUI, RGB_HUD)},
};

// KEYHOOK
bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (!process_record_user(keycode, record)) return false;

    if (keycode == CPI_I && record->event.pressed) {
        ballconfig.cpi_idx = (ballconfig.cpi_idx + 1) % CPI_OPTION_SIZE;
        eeconfig_update_kb(ballconfig.raw);
        pointing_device_set_cpi(cpi_array[ballconfig.cpi_idx]);
    }
    if (keycode == CPI_D && record->event.pressed) {
        ballconfig.cpi_idx = (CPI_OPTION_SIZE + (ballconfig.cpi_idx - 1)) % CPI_OPTION_SIZE;
        eeconfig_update_kb(ballconfig.raw);
        pointing_device_set_cpi(cpi_array[ballconfig.cpi_idx]);
    }
    if (keycode == ANG_I && record->event.pressed) {
        ballconfig.angle_idx = (ballconfig.angle_idx + 1) % ANGLE_OPTION_SIZE;
        eeconfig_update_kb(ballconfig.raw);
    }
    if (keycode == ANG_D && record->event.pressed) {
        ballconfig.angle_idx = (ANGLE_OPTION_SIZE + (ballconfig.angle_idx - 1)) % ANGLE_OPTION_SIZE;
        eeconfig_update_kb(ballconfig.raw);
    }
    return true;
}

// CURSOR ANGLE
report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {

    double rad = angle_array[ballconfig.angle_idx] * (M_PI / 180) * -1;
    int8_t x_rev =  + mouse_report.x * cos(rad) - mouse_report.y * sin(rad);
    int8_t y_rev =  + mouse_report.x * sin(rad) + mouse_report.y * cos(rad);
    mouse_report.x = x_rev;
    mouse_report.y = y_rev;
    return pointing_device_task_user(mouse_report);
}

// INITIALIZE CPI
void pointing_device_init_kb(void) {
    pointing_device_set_cpi(cpi_array[ballconfig.cpi_idx]);
}

// READ EEPROM
void eeconfig_init_kb(void) {
    ballconfig.cpi_idx = CPI_DEFAULT;
    ballconfig.angle_idx = ANGLE_DEFAULT;
    eeconfig_update_kb(ballconfig.raw);
    eeconfig_init_user();
}

// INITIALIZE KEYBOARD
void matrix_init_kb(void) {
    ballconfig.raw = eeconfig_read_kb();
    if (ballconfig.cpi_idx > CPI_OPTION_SIZE || ballconfig.angle_idx > ANGLE_OPTION_SIZE)
    {
        eeconfig_init_kb();
    }
    matrix_init_user();
}
