/* Copyright 2015-2017 Jack Humbert
 *
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _NUMPAD,
  _BACKLIGHT
};

/* enum planck_keycodes { */
/*   QWERTY = SAFE_RANGE, */
/*   PLOVER, */
/*   LOWER, */
/*   RAISE, */
/*   FUNCTION, */
/*   NUMPAD, */
/*   BACKLIGHT */
/* }; */

// Key aliases for legibility
#define _______ KC_TRNS
#define ___x___ KC_NO
/* #define ___*___ KC_NO */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *             ,-----------------------------------------------------------------------------------.
 *             | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 *             |------+------+------+------+------+-------------+------+------+------+------+------|
 * LCTRL------ | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   | ---RCTL when held
 * when held   |------+------+------+------+------+------|------+------+------+------+------+------|
 *             | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter | ---RSHIFT when held
 *             |------+------+------+------+------+------+------+------+------+------+------+------|
 *             | BLITE| NPAD | HOLD | FUNC |Lower | Bksp |Space |Raise | Left | Down |  Up  |Right |
 *             `-----------------------------------------------------------------------------------'
 *                                           GUI____/       \____ALT
 *                                    when held                when held
 */
[_QWERTY] = {
  {KC_TAB,                  KC_Q,       KC_W,    KC_E,         KC_R,        KC_T,           KC_Y,          KC_U,      KC_I,    KC_O,    KC_P,    KC_BSLS},
  {CTL_T(KC_ESC),           KC_A,       KC_S,    KC_D,         KC_F,        KC_G,           KC_H,          KC_J,      KC_K,    KC_L,    KC_SCLN, MT(MOD_RCTL, KC_QUOT)},
  {KC_LSFT,                 KC_Z,       KC_X,    KC_C,         KC_V,        KC_B,           KC_N,          KC_M,      KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT)},
  {MO(_BACKLIGHT), MO(_NUMPAD), KC_LOCK, MO(_FUNCTION), MO(_LOWER), GUI_T(KC_BSPC), ALT_T(KC_SPC), MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT}
},

/* Lower
 *              ,-----------------------------------------------------------------------------------.
 *              | GUI-`| Mute | Vol- | Vol+ | Tab- | Tab+ |   £  |   {  |   }  |   [  |   ]  |  +   |
 *              |------+------+------+------+------+-------------+------+------+------+------+------|
 *  LCTRL------ |  `   | Prev | Play | Next |Desk- |Desk+ | Left | Down |  Up  |Right |   _  |  -   | ---RCTL when held
 *  when held   |------+------+------+------+------+------|------+------+------+------+------+------|
 *              |      |      |      |      |Pane- |Pane+ | Home |Bottom|  Top | End  |      |      |
 *              |------+------+------+------+------+------+------+------+------+------+------+------|
 *              |      |      |      |      |      |      | Del  |      |      |      |      |      |
 *              `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {LGUI(KC_GRV),  KC_AUDIO_MUTE,   KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,       LGUI(LALT(KC_LEFT)),  LGUI(LALT(KC_RIGHT)), LALT(KC_3), KC_LCBR,    KC_RCBR,    KC_LBRC, KC_RBRC, KC_PLUS},
  {CTL_T(KC_GRV), KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, LCTL(KC_LEFT), LCTL(KC_RIGHT), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_UNDS, MT(MOD_RCTL,KC_MINS)},
  {_______,       ___x___,         ___x___,             ___x___,               LGUI(KC_LBRC), LGUI(KC_RBRC), LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RIGHT), ___x___,  _______},
  {___x___, ___x___, _______, ___x___, _______, _______, KC_DEL, ___x___,    _______,    _______, _______, _______}
},

/* Raise
 *                 ,-----------------------------------------------------------------------------------.
 *                 |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  =   |
 *                 |------+------+------+------+------+-------------+------+------+------+------+------|
 *      LCTRL -----|   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  .   | ---RCTRL when held
 *      when held  |------+------+------+------+------+------|------+------+------+------+------+------|
 *                 |      |      |      |      |      |      |A-left|A-down| A-up |A-rght|      |      |
 *                 |------+------+------+------+------+------+------+------+------+------+------+------|
 *                 |      |      |      |      |      |      |      |Raise |      |      |      |      |
 *                 `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______,        KC_EXLM,    KC_AT,    KC_HASH,  KC_DLR,   KC_PERC, KC_CIRC,        KC_AMPR,       KC_ASTR,     KC_LPRN,        KC_RPRN, KC_EQL},
  {KC_TILD,        KC_1,       KC_2,     KC_3,     KC_4,     KC_5,    KC_6,           KC_7,          KC_8,        KC_9,           KC_0,    MT(MOD_RCTL, KC_DOT)},
  {_______,        ___x___,    ___x___,  ___x___,  ___x___,  ___x___, LALT(KC_LEFT),  LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RIGHT), _______, _______},
  {___x___,        ___x___,    _______,  ___x___,  ___x___,  _______, _______,        _______,       _______,     _______,        _______, _______}
},


/* Function
 *                 ,-----------------------------------------------------------------------------------.
 *                 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 *                 |------+------+------+------+------+-------------+------+------+------+------+------|
 *       LCTRL ----| Esc  |      |PrtSc1|PrtSc2|ForceQ|      |      |ScBr- |ScBr+ |      |      | Ctrl |
 *       when held |------+------+------+------+------+------|------+------+------+------+------+------|
 *                 | Shift|uPyMac|      |      |      |      |      |      |      |      |      |Shift |
 *                 |------+------+------+------+------+------+------+------+------+------+------+------|
 *                 | Lock |      |      | Func |      |  Gui |  Alt |      |      |      |Debug |Reset |
 *                 `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = {
  {KC_F1,          KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F8,   KC_F10,   KC_F11,  KC_F12},
  {CTL_T(KC_ESC),  ___x___,    LGUI(KC_F11),    LGUI(KC_F12),    LGUI(LALT(KC_ESC)),    ___x___,    ___x___,    KC_SLCK,    KC_PAUS, ___x___,  ___x___, KC_RCTL},
  {_______,        ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___, ___x___,  ___x___, KC_RSFT},
  {LCTL(LGUI(KC_Q)),        ___x___,    _______,    _______,    ___x___,    KC_LGUI,    KC_LALT,    ___x___,    ___x___, ___x___,  DEBUG,   RESET}
},

/* Number Pad
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |      |      |      |      |      |   7  |   8  |   9  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |      |      |      |      |      |   4  |   5  |   6  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |   1  |   2  |   3  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Num  |      |      |      |      |      |Enter |   0  |   .  |Enter |  +   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {KC_TAB,  ___x___, ___x___, ___x___,  ___x___,    ___x___,    ___x___,    ___x___,    KC_7,    KC_8,    KC_9,    KC_SLSH},
  {KC_ESC,  ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    KC_4,    KC_5,    KC_6,    KC_ASTR},
  {KC_LSFT, ___x___, ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    ___x___,    KC_1,    KC_2,    KC_3,    KC_MINS },
  {___x___, _______, ___x___, ___x___, ___x___,   ___x___,  ___x___,  KC_ENT,   KC_0, KC_DOT, KC_ENT,   KC_PLUS}
},
/* Backlight
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Breath|BLite-|Blite+|BLTogg|
 * `-----------------------------------------------------------------------------------'
 */

[_BACKLIGHT] = {
  {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {_______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, BL_BRTG, BL_DEC,  BL_INC,  BL_TOGG}
},

};

/* #ifdef AUDIO_ENABLE */
/*   float plover_song[][2]     = SONG(PLOVER_SOUND); */
/*   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND); */
/* #endif */

/* bool process_record_user( keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case QWERTY: */
/*       if (record->event.pressed) { */
/*         print("mode just switched to qwerty and this is a huge string\n"); */
/*         set_single_persistent_default_layer(_QWERTY); */
/*       } */
/*       return false; */
/*       break; */
/*     case COLEMAK: */
/*       if (record->event.pressed) { */
/*         set_single_persistent_default_layer(_COLEMAK); */
/*       } */
/*       return false; */
/*       break; */
/*     case DVORAK: */
/*       if (record->event.pressed) { */
/*         set_single_persistent_default_layer(_DVORAK); */
/*       } */
/*       return false; */
/*       break; */
/*     case LOWER: */
/*       if (record->event.pressed) { */
/*         layer_on(_LOWER); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } else { */
/*         layer_off(_LOWER); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*     case RAISE: */
/*       if (record->event.pressed) { */
/*         layer_on(_RAISE); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } else { */
/*         layer_off(_RAISE); */
/*         update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*       } */
/*       return false; */
/*       break; */
/*     case BACKLIT: */
/*       if (record->event.pressed) { */
/*         register_code(KC_RSFT); */
/*         #ifdef BACKLIGHT_ENABLE */
/*           backlight_step(); */
/*         #endif */
/*         PORTE &= ~(1<<6); */
/*       } else { */
/*         unregister_code(KC_RSFT); */
/*         PORTE |= (1<<6); */
/*       } */
/*       return false; */
/*       break; */
/*     case PLOVER: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           stop_all_notes(); */
/*           PLAY_SONG(plover_song); */
/*         #endif */
/*         layer_off(_RAISE); */
/*         layer_off(_LOWER); */
/*         layer_off(_ADJUST); */
/*         layer_on(_PLOVER); */
/*         if (!eeconfig_is_enabled()) { */
/*             eeconfig_init(); */
/*         } */
/*         keymap_config.raw = eeconfig_read_keymap(); */
/*         keymap_config.nkro = 1; */
/*         eeconfig_update_keymap(keymap_config.raw); */
/*       } */
/*       return false; */
/*       break; */
/*     case EXT_PLV: */
/*       if (record->event.pressed) { */
/*         #ifdef AUDIO_ENABLE */
/*           PLAY_SONG(plover_gb_song); */
/*         #endif */
/*         layer_off(_PLOVER); */
/*       } */
/*       return false; */
/*       break; */
/*   } */
/*   return true; */
/* } */
