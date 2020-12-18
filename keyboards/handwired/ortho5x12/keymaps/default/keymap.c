/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#include "custom_midi.c"

enum layer_keycodes {
  QWERTY = MID_VR + 1,
  DVORAK,  LOWER,  RAISE,  GAME,
  LED_ON,  LEDOFF, LOGO,
  ENC_SLD, ENC_TB
};

enum ortho_layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MIDI,
  _GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |PrintS|Lower |Space |Space |Raise | End  | Home |PgDwn | PgUp |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_grid( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC__MUTE, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, ENC_SLD,  \
  KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  ENC_TB,   \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           \
  KC_LCTRL,KC_LGUI, KC_LALT, KC_PSCR, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_END,  KC_HOME, KC_PGDN, KC_PGUP            \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtrlLr| GUI  | Alt  |PrintS|Lower |Space |Space |Raise | End  | Home |PgDwn | PgUp |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC__MUTE, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, ENC_SLD,  \
  KC_DEL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,  ENC_TB,   \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,           \
  KC_LCTRL,KC_LGUI, KC_LALT, KC_PSCR, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_END,  KC_HOME, KC_PGDN, KC_PGUP            \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F13 | F14  |  F15 |  F16 |   [  |   {  |   }  |   ]  |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F17 | F18  |  F19 |  F20 |   (  |   <  |   >  |   )  |   4  |   5  |   6  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F21 | F22  |  F23 |  F24 |   "  |   '  |   `  |   ~  |   1  |   2  |   3  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   .  |   +  |  /   |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_grid( \
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC__MUTE, \
		KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_7,    KC_8,     KC_9,     KC_BSPC,  ENC_SLD,  \
		KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_LPRN, KC_LABK, KC_RABK, KC_RPRN, KC_4,    KC_5,     KC_6,     KC_MINS,  ENC_TB,   \
		KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_DQUO, KC_QUOT, KC_GRV,  KC_TILD, KC_1,    KC_2,     KC_3,     KC_ASTR,            \
		_______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,   KC_PLUS,  KC_SLSH             \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumLk |L-Clk |Mouse |R-Clk |ScrlU |      |RMAC1 |RMAC2 |  F13 | F14  |  F15 |  F16 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CapsLk|Mouse |Mouse |Mouse |ScrlD |      |PMAC1 |PMAC2 |  F17 | F18  |  F19 |  F20 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |ScrlLk|      |CountE|CountR|Count |      |SRMAC |SRMAC |  F21 | F22  |  F23 |  F24 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  |Butn3 |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_grid( \
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC__MUTE,  \
		KC_NLCK, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, DM_REC1, DM_REC2, KC_F13,  KC_F14,  KC_F15,  KC_F16,  ENC_SLD,   \
		KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, DM_PLY1, DM_PLY2, KC_F17,  KC_F18,  KC_F19,  KC_F20,  ENC_TB,    \
		KC_SLCK, _______, _______, _______, _______, _______, DM_RSTP, DM_RSTP, KC_F21,  KC_F22,  KC_F23,  KC_F24,           \
		_______, _______, KC_LALT, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______             \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Reset |Debug |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |MIDILR|GAMELR|Qwerty|Dvorak|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC__MUTE, \
  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  ENC_SLD,  \
  RESET,   DEBUG,   NK_TOGG, _______, _______, _______, _______, LEDOFF,  LED_ON,  LOGO,    _______, _______, ENC_TB,   \
  MID_EN,  GAME,    QWERTY,  DVORAK,  _______, _______, _______, _______, _______, _______, _______, _______,           \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______            \
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ^  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Bksp | Alt  |   .  |Lower |Space |Space |Raise | End  |  <-  |   v  |  ->  |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC__MUTE, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, ENC_SLD,  \
  KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  ENC_TB,   \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,           \
  KC_LCTRL,KC_BSPC, KC_LALT, KC_DOT,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT           \
),

/* Midi
 * ,-----------------------------------------------------------------------------------.
 * |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  | Enter| Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  C#  |  D#  |      |  F#  |  G#  |  A#  |      |  C#  |  D#  |      |  F#  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  C   |  D   |  E   |  F   |  G   |  A   |  B   |  C   |  D   |  E   |  F   |  G   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | OctDn| OctUp|ChanUp|ChanDn|      |      |      |      |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space |Space |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_grid( \
  KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_ENT,  KC_BSPC, MID_VR,   \
  _______, MID_5,   MID_7,   _______, MID_10,  MID_12,  MID_2,   _______, MID_15,  MID_17,  _______, MID_20,  KC_VOLU,  \
  MID_4,   MID_6,   MID_8,   MID_9,   MID_11,  MID_1,   MID_3,   MID_14,  MID_16,  MID_18,  MID_19,  MID_21,  KC_VOLD,  \
  MID_OD,  MID_OU,  MID_CD,  MID_CU,  _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           \
  KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, _______, _______, _______            \
)
};

bool logo = true;
bool encoder_scroll = false;
bool encoder_tabbing = false;
bool encoder_window_tabbing = false;
uint16_t tabbing_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    #ifdef CONSOLE_ENABLE
        uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    #endif
    /*
    if (!(get_highest_layer(layer_state) == _MIDI) && midi_layer == true){
        midi_layer = false;
        tap_code16(MI_OFF);
    }
    */
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
            case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
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
        case MID_EN:
            layer_on(_MIDI);
            tap_code16(MI_ON);
            midi_layer = true;
            return false;
            break;
        case MID_1:
            if (record->event.pressed){
                handle_midi_layer(1, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(1, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_2:
            if (record->event.pressed){
                handle_midi_layer(2, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(2, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_3:
            if (record->event.pressed){
                handle_midi_layer(3, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(3, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_4:
            if (record->event.pressed){
                handle_midi_layer(4, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(4, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_5:
            if (record->event.pressed){
                handle_midi_layer(5, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(5, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_6:
            if (record->event.pressed){
                handle_midi_layer(6, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(6, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_7:
            if (record->event.pressed){
                handle_midi_layer(7, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(7, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_8:
            if (record->event.pressed){
                handle_midi_layer(8, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(8, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_9:
            if (record->event.pressed){
                handle_midi_layer(9, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(9, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_10:
            if (record->event.pressed){
                handle_midi_layer(10, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(10, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_11:
            if (record->event.pressed){
                handle_midi_layer(11, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(11, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_12:
            if (record->event.pressed){
                handle_midi_layer(12, midi_vel, midi_channel, midi_octave, 0);
            } else {
                handle_midi_layer(12, midi_vel, midi_channel, midi_octave, 1);
            }
        return false;
        break;
        case MID_13:
            if (record->event.pressed){
                handle_midi_layer(1, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(1, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_14:
            if (record->event.pressed){
                handle_midi_layer(2, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9 , 0);
            } else {
                handle_midi_layer(2, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_15:
            if (record->event.pressed){
                handle_midi_layer(3, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(3, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_16:
            if (record->event.pressed){
                handle_midi_layer(4, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(4, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_17:
            if (record->event.pressed){
                handle_midi_layer(5, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(5, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_18:
            if (record->event.pressed){
                handle_midi_layer(6, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(6, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_19:
            if (record->event.pressed){
                handle_midi_layer(7, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(7, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_20:
            if (record->event.pressed){
                handle_midi_layer(8, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(8, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_21:
            if (record->event.pressed){
                handle_midi_layer(9, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 0);
            } else {
                handle_midi_layer(9, midi_vel, midi_channel, ((midi_octave + 1) < 10)?(midi_octave + 1):9, 1);
            }
        return false;
        break;
        case MID_OU:
            midi_octave += 1;
            if (midi_octave > 9){
              midi_octave = 9;
            }
        return false;
        break;
        case MID_OD:
            midi_octave -= 1;
            if (midi_octave < 0){
              midi_octave = 0;
            }
        return false;
        break;
        case MID_CD:
            midi_channel -= 1;
            if (midi_channel < 0){
              midi_channel = 0;
            }
        return false;
        break;
        case MID_CU:
            midi_channel += 1;
            if (midi_channel > 16){
              midi_channel = 16;
            }
        return false;
        break;
        case GAME:
            if (record->event.pressed){
              layer_on(_GAME);
            }
        return false;
        break;
        case MID_VR:
            midi_vel = 64;
        return false;
        break;///*
        case LEDOFF:
            oled_off();
        return false;
        break;
        case LED_ON:
            oled_on();
        return false;
        break;
        case LOGO:
            if(!(record->event.pressed)){
                logo = !logo;
            }
        return false;
        break;//*/
        case ENC_SLD:
            if(!(record->event.pressed)){
                encoder_scroll = !encoder_scroll;
            }
        return false;
        break;
        case ENC_TB:
            if(!(record->event.pressed)){
                encoder_window_tabbing = true;
            } else {
                encoder_window_tabbing = false;
            }
        return false;
        break;
      }
    return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (index){
    case 0:
      if (midi_layer){
        if (clockwise) {
            midi_vel += 5;
            if (midi_vel > 127){
                midi_vel = 127;
            }
        } else {
            midi_vel -= 5;
            if (midi_vel < 0){
                midi_vel = 0;
            }
        }
      } else {
        if (clockwise) {
            tap_code16(KC_VOLU);
        } else {
            tap_code16(KC_VOLD);
        }
      }
      break;
    case 1:
      if (midi_layer){
        if (clockwise) {
            midi_enc_1 += 5;
            if (midi_enc_1 > 127){
                midi_enc_1 = 127;
            }
            handle_midi_layer(0, midi_enc_1, midi_channel, midi_octave, 2);
        } else {
            midi_enc_1 -= 5;
            if (midi_enc_1 < 0){
                midi_enc_1 = 0;
            }
            handle_midi_layer(0, midi_enc_1, midi_channel, midi_octave, 2);
        }
      } else {
        if (clockwise) {
            if (encoder_scroll){
                tap_code16(KC_RIGHT);
            }else{
                tap_code16(KC_UP);
            }
        } else {
            if (encoder_scroll){
                tap_code16(KC_LEFT);
            }else{
                tap_code16(KC_DOWN);
            }
        }
      }
      break;
    case 2:
      if (midi_layer){
        if (clockwise) {
            midi_enc_2 += 5;
            if (midi_enc_2 > 127){
                midi_enc_2 = 127;
            }
            handle_midi_layer(0, midi_enc_2, midi_channel, midi_octave, 3);
        } else {
            midi_enc_2 -= 5;
            if (midi_enc_2 < 0){
                midi_enc_2 = 0;
            }
            handle_midi_layer(0, midi_enc_2, midi_channel, midi_octave, 3);
        }
      } else {
        if (clockwise) {
            if (!encoder_tabbing) {
                encoder_tabbing = true;
                register_code(KC_LALT);
            }
            tabbing_timer = timer_read();
            tap_code16(((encoder_window_tabbing)?KC_DQUO:KC_TAB));
        } else {
            tabbing_timer = timer_read();
            tap_code16(S((((encoder_window_tabbing)?KC_DQUO:KC_TAB))));
        }
      }
      break;
    default:
      break;
    }
}
///*
void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x9c, 0x9c, 0x1c, 0x1c, 0x1c,
        0x3c, 0x7c, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x99, 0x99, 0x80, 0x80, 0x80,
        0xc0, 0xe0, 0xff, 0xff, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0x70, 0x38, 0x1c, 0x0c,
        0x0c, 0x1c, 0x38, 0x30, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0x78, 0x3c, 0x1c, 0x1c, 0x1c, 0x1c,
        0x1c, 0x3c, 0x78, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0x78,
        0x38, 0x18, 0x1c, 0x1c, 0x1c, 0x18, 0x38, 0x78, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xfc, 0xfc, 0xe0, 0x70, 0x38, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3c, 0xf8, 0xf0, 0xe0,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0,
        0xf8, 0x78, 0x38, 0x1c, 0x1c, 0x1c, 0x1c, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
        0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc3, 0x00, 0x00,
        0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0xc3, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
        0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x38, 0xff, 0xff, 0xc7,
        0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x81, 0x81, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1c, 0x38, 0x38, 0x38, 0x38,
        0x38, 0x38, 0x1c, 0x0e, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1e,
        0x1c, 0x18, 0x38, 0x38, 0x38, 0x18, 0x1c, 0x1e, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f,
        0x1e, 0x1c, 0x18, 0x38, 0x38, 0x38, 0x38, 0x18, 0x1c, 0x1e, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_P(logo, false);
}

void oled_task_user(void) {
    if(logo){
        render_logo();
    } else {
        oled_write(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write(PSTR("Qwerty\n"), false);
                break;
            case _DVORAK:
                oled_write(PSTR("Dvorak\n"), false);
                break;
            case _LOWER:
                oled_write(PSTR("Lower Layer\n"), false);
                break;
            case _RAISE:
                oled_write(PSTR("Upper Layer\n"), false);
                break;
            case _ADJUST:
                oled_write(PSTR("Settings\n"), false);
                break;
            case _MIDI:
                oled_write(PSTR("Midi mode\n"), false);
                break;
            case _GAME:
                oled_write(PSTR("Game mode\n"), false);
                break;
            default:
                oled_write(PSTR("Undefined\n"), false);
                break;
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write(led_state.num_lock  ? PSTR("  NUM  ") : PSTR("       "), false);
        oled_write(led_state.caps_lock ? PSTR("  CAP  ") : PSTR("       "), false);
        oled_write(PSTR("\nAlex O'Connor\n"), false);
        if (midi_layer){
            char uint8_t_to_char [4];

            sprintf (uint8_t_to_char, "%d", midi_vel);
            oled_write(PSTR("VEL:  "), false);
            oled_write(PSTR(uint8_t_to_char), false);

            sprintf (uint8_t_to_char, "%d", midi_channel);
            oled_write(PSTR("CHAN: "), false);
            oled_write(PSTR(uint8_t_to_char), false);

            sprintf (uint8_t_to_char, "%d", midi_octave);
            oled_write(PSTR("OCT:  "), false);
            oled_write(PSTR(uint8_t_to_char), false);
        }
    }
}
//*/
void matrix_scan_user(void) {
  if (encoder_tabbing) {
    if (timer_elapsed(tabbing_timer) > 1000) {
      unregister_code(KC_LALT);
      encoder_tabbing = false;
    }
  }
}
