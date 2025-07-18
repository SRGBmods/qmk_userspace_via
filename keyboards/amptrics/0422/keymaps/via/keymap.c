/* Copyright 2024 Vinod Chowl (@vchowl)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2.0 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    LAYER_ROTATE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │Tog│
     * ├───┼───┬───┐
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 1 │ 2 │ 3 │
     * └───┴───┴───┘
     */
    [0] = LAYOUT(
        LAYER_ROTATE,
        KC_7,   KC_8,   KC_9,
        KC_4,   KC_5,   KC_6,
        KC_1,   KC_2,   KC_3
    ),

    [1] = LAYOUT(
        LAYER_ROTATE,
        KC_A,   KC_B,   KC_C,
        KC_D,   KC_E,   KC_F,
        KC_G,   KC_H,   KC_I
    ),

    [2] = LAYOUT(
        LAYER_ROTATE,
        KC_J,   KC_K,   KC_L,
        KC_M,   KC_N,   KC_O,
        KC_P,   KC_Q,   KC_R
    ),

    [3] = LAYOUT(
        LAYER_ROTATE,
        KC_S,   KC_T,   KC_U,
        KC_V,   KC_W,   KC_X,
        KC_Y,   KC_Z,   KC_ENT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER_ROTATE:
            if (record->event.pressed) {
                // Move to next layer on tap
                uint8_t current_layer = get_highest_layer(layer_state);
                uint8_t next_layer    = layer >= 3 ? 0 : layer + 1;
                layer_move(next_layer);
                return false; // Prevent further processing of this key
            }
            break;
        default:
            return true;
    }
    return true; // Allow other keycodes to be processed normally
}
