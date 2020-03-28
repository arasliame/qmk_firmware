/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define NUMB 1 // numbers
#define NUMPAD 2 // numpad/motion
#define SYMB 3 // symbols

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  + =   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | Base   |   A  |   S  |  D   |   F  |   G  | Ins  |           | Esc  |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | Ctrl   |   Z  |   X  |   C  |   V  |   B  | PrtSc|           | XXXX |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .-------.   .-------.                                 .------.   .-----.
 *                    | Del   |   |Alt    |                                 |NUMB  |   |Win  | 
 *                    '-------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        |Toggle
 *                                          Numpad|                      |Launchy|
 *                                 ,------|-------|                      |-------|------.
 *                                 | NUMB | SYMB  |                      | SYMB  | Shift|    
 *                                 | Space| Bksp  |                      | Enter |      |    
 *                                 |      |       |                      |       |      |    
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R, KC_T,                                               KC_Y,   KC_U,    KC_I, KC_O,      KC_P, KC_EQL/*add plus eq*/,
    TO(BASE),  KC_A,   KC_S,   KC_D,   KC_F, KC_G, KC_INSERT,                           KC_ESC,  KC_H,   KC_J,    KC_K, KC_L,   KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,   KC_C,   KC_V, KC_B, KC_PSCREEN, TG(NUMPAD),      LALT(KC_SPC), KC_NO,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
    KC_DEL, KC_LALT, LT(NUMB, KC_SPC), LT(SYMB, KC_BSPC),                       LT(SYMB, KC_ENT),  KC_RSFT, TT(NUMB), KC_RGUI
    ),
/* Keymap 3: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                         |  ^   |  &   |  *   |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  {   |  }   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  |   |  ^   |  [   |  ]   |  ~   |      |           |      |   =  |  \ | |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LCBR, KC_RCBR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS,                          KC_TRNS, KC_PLUS, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_PIPE, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_EQL, KC_BSLS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  | F2   | F3   | F4   | F5   |      |           |      | PgUp | UP   | PgDn | Home |VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  F6  | F7   | F8   | F9   | F10  |      |           |      | LEFT | DOWN | RIGHT| End  |Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,                         KC_TRNS,  KC_PGUP, KC_UP, KC_PGDN,  KC_HOME, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_TRNS, KC_TRNS,				  KC_TRNS,  KC_TRNS, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_END, KC_MPLY, KC_MNXT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),


/* NUMPAD
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         | Num  |  7   |  8   |  9   |  -   |   /    |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      | LCLK | mUP  | RCLK |  wUP |      |           |      | Bksp |  4   |  5   |  6   |  +   |   *    |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |  mLT | mDN  |  mRT |  wDN |      |           |      |      |  1   |  2   |  3   |  .   |  Ent   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |  0  |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'*/
[NUMPAD] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_PSLS,
    KC_TRNS, KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_TRNS,                           KC_TRNS, KC_BSPC, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PAST,
    KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_P1  , KC_P2  , KC_P3  , KC_PDOT, KC_PENT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_P0
    ),
 };