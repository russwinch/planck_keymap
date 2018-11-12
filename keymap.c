/* Copyright 2015-2017 Jack Humbert
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ****************************************************************************************
 * The following should be modified within MacOS:
 * Set the keyboard Input Source to U.S.
 * Set Screen Shot shortcuts for copy screen and copy screen area set to hyper+S and hyper+D
 * Use Automator to create a service to launch the calculator app. Keyboard shortcut set to hyper+C in Services
 * Use Automator to create a service to get and reveal finder items in the home directory. Keyboard shortcut set to hyper+X in Services
 * Deactivate Services shortcut for Convert Text to Simplified Chineese (hyper+C)
 * Set Misson Control shortcuts for move left and right a space to ctrl+left ctrl+right, Misson Control as ctrl+up and application windows as ctrl+down
 * ****************************************************************************************
 * Compile with: make planck/rev5:russwinch
 * While in the qmk-firmware folder
 * Then flash to keyboard with QMK Toolbox
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ARROWS,
  _BACKLIGHT
};

// Key aliases for legibility
#define _______ KC_TRNS
#define ___x___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *             ,-----------------------------------------------------------------------------------.
 *             | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 *             |------+------+------+------+------+-------------+------+------+------+------+------|
 * LCTRL------ | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   | ---RCTL when held
 * when held   |------+------+------+------+------+------|------+------+------+------+------+------|
 *             | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter | ---RSHIFT when held
 *             |------+------+------+------+------+------+------+------+------+------+------+------|
 *             | BLITE|Breath| FUNC |  ALT | Lower| Bksp | Space| Raise| Left | Down |  Up  |Right |
 *             `-----------------------------------------------------------------------------------'
 *                                           GUI____/
 *                                    when held
 */
[_QWERTY] = {
  {KC_TAB,         KC_Q,        KC_W,          KC_E,    KC_R,       KC_T,           KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSLS},
  {CTL_T(KC_ESC),  KC_A,        KC_S,          KC_D,    KC_F,       KC_G,           KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, MT(MOD_RCTL, KC_QUOT)},
  {KC_LSFT,        KC_Z,        KC_X,          KC_C,    KC_V,       KC_B,           KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT},
  {MO(_BACKLIGHT), BL_BRTG, MO(_FUNCTION), KC_LALT, MO(_LOWER), GUI_T(KC_BSPC), KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 *              ,-----------------------------------------------------------------------------------.
 *              | GUI-`| Mute | Vol- | Vol+ | Tab- | Tab+ |   £  |   {  |   }  |   [  |   ]  |  +   |
 *              |------+------+------+------+------+-------------+------+------+------+------+------|
 *  LCTRL------ |  `   | Prev | Play | Next |Desk- |Desk+ | Left | Down |  Up  |Right |   _  |  -   | ---RCTL when held
 *  when held   |------+------+------+------+------+------|------+------+------+------+------+------|
 *              |      |      |      |      |Miss C|App Wi| Home |Bottom|  Top | End  |      |      |
 *              |------+------+------+------+------+------+------+------+------+------+------+------|
 *              |      |      |      |      |      |      | Del  |      |      |      |      |      |
 *              `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {LGUI(KC_GRV),  KC_AUDIO_MUTE,   KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,       LGUI(LALT(KC_LEFT)), LGUI(LALT(KC_RIGHT)), LALT(KC_3),    KC_LCBR,       KC_RCBR,     KC_LBRC,        KC_RBRC, KC_PLUS},
  {CTL_T(KC_GRV), KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, LCTL(KC_LEFT),          LCTL(KC_RIGHT),           KC_LEFT,       KC_DOWN,       KC_UP,       KC_RGHT,        KC_UNDS, MT(MOD_RCTL,KC_MINS)},
  {_______,       ___x___,         ___x___,             ___x___,               LCTL(KC_UP),       LCTL(KC_DOWN),        LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_RIGHT), ___x___, _______},
  {___x___,       ___x___,         _______,             ___x___,               _______,             _______,              KC_DEL,        ___x___,       _______,     _______,        _______, _______}
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
  {_______, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC, KC_CIRC,       KC_AMPR,       KC_ASTR,     KC_LPRN,        KC_RPRN, KC_EQL},
  {KC_TILD, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,    KC_6,          KC_7,          KC_8,        KC_9,           KC_0,    MT(MOD_RCTL, KC_DOT)},
  {_______, ___x___,  ___x___,  ___x___,  ___x___,  ___x___, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), _______, _______},
  {___x___, ___x___,  _______,  ___x___,  ___x___,  _______, _______,       _______,       _______,     _______,        _______, _______}
},


/* Function
 *                 ,-----------------------------------------------------------------------------------.
 *                 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 *                 |------+------+------+------+------+-------------+------+------+------+------+------|
 *       LCTRL ----| Esc  |      |PrtSc1|PrtDsk|ForceQ|      |      |ScrBr-|ScrBr+|      |ArrowL| Ctrl |
 *       when held |------+------+------+------+------+------|------+------+------+------+------+------|
 *                 |Capslk|      |Finder| Calc |      |      |      |      |      |      |      |Shift |
 *                 |------+------+------+------+------+------+------+------+------+------+------+------|
 *                 | Lock |Numlk | Func | Alt  |      |  Gui |      |RaisLk|      |      |Debug |Reset |
 *                 `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = {
  {KC_F1,            KC_F2,   KC_F3,        KC_F4,        KC_F5,              KC_F6,      KC_F7,      KC_F8,      KC_F8,   KC_F10,   KC_F11,      KC_F12},
  {CTL_T(KC_ESC),    ___x___, HYPR(KC_S),   HYPR(KC_D),   LGUI(LALT(KC_ESC)), ___x___,    ___x___,    KC_SLCK,    KC_PAUS, ___x___,  TO(_ARROWS), KC_RCTL},
  {KC_CAPS,          ___x___, HYPR(KC_X),   HYPR(KC_C),   ___x___,            ___x___,    ___x___,    ___x___,    ___x___, ___x___,  ___x___,     KC_RSFT},
  {LCTL(LGUI(KC_Q)), _______, _______,      _______,      ___x___,            KC_LGUI,    ___x___,    TO(_RAISE), ___x___, ___x___,  DEBUG,       RESET}
},

/* Number Pad (not used)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |      |      |      | Left | Down |  Up  |Right |      | Ctrl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Exit |      | Exit |      |      | Exit |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = {
  {KC_TAB,  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {KC_ESC,  ___x___, ___x___, ___x___, ___x___, ___x___, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ___x___, KC_RCTL},
  {KC_LSFT, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {_______, _______, TO(_QWERTY), _______, TO(_QWERTY), _______, _______, TO(_QWERTY),  ___x___, ___x___, ___x___, ___x___}
},
/* Backlight
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |BLite-|Blite+|BLTogg|
 * `-----------------------------------------------------------------------------------'
 */

[_BACKLIGHT] = {
  {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___},
  {_______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, BL_BRTG, BL_DEC,  BL_INC,  BL_TOGG}
},

};
