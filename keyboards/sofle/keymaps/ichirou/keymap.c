// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Additional Features double tap guard
enum {
    TD_BOOT,
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
};

enum sofle_layers {
    _BASE,
    _NAV,
    _MOUSE,
    _SYMBOL,
    _NUMBER,
    _FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base layer: QWERTY + Home row GACS modifiers
 * ,-----------------------------------------------,                    ,-----------------------------------------------,
 * |  `    |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | Prnt  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Tab   |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   | Bspc  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | ESC   |  *A   |  *S   |  *D   |  *F   |   G   |                    |   H   |  *J   |  *K   |  *L   |  *;   |  '    |
 * |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------|
 * | LSft  |   Z   |   X   |   C   |   V   |   B   |  MUTE |    | MPLY  |   N   |   M   |   ,   |   .   |   /   | RSft  |
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 | LGUI  | LAlt  |  ESC  | Tab   | Enter |    | Space | Bspc  |  Del  | RAlt  | RGUI  |
 *                 |       |       |       | _Nav  | _Mouse|    |  _Sym | _Num  | _Fun  |       |       |
 *                 `---------------------------------------'    '---------------------------------------'
 */
[_BASE] = LAYOUT(
  KC_GRV,         KC_1,         KC_2,         KC_3,         KC_4,       KC_5,                        KC_6,         KC_7,         KC_8,         KC_9,            KC_0,       KC_PSCR,
  KC_TAB,         KC_Q,         KC_W,         KC_E,         KC_R,       KC_T,                        KC_Y,         KC_U,         KC_I,         KC_O,            KC_P,       KC_BSPC,
  KC_ESC, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),       KC_G,                        KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),       KC_QUOT,
  KC_LSFT,        KC_Z,         KC_X,         KC_C,         KC_V,       KC_B, KC_MUTE,      KC_MPLY, KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,       KC_RSFT,
                     KC_LGUI, KC_LALT, KC_ESC, LT(_NAV, KC_TAB), LT(_MOUSE, KC_SPC),      LT(_SYMBOL, KC_ENT), LT(_NUMBER, KC_BSPC), LT(_FUNC, KC_DEL), KC_RALT, KC_RGUI
),

/* Navigation keys */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* | Boot* |       |       |       |       |       |                    |       | PgDn  |  Up   | PgUp  |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       | LWin  | LAlt  | LCtrl | LSft  |       |                    |       | Left  | Down  | Right |       |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |       |       |       |       |       |       |    |       |  Ins  | Home  |       |  End  |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |       | XXXXX |       |    | Enter | Bspc  |  Del  |       |       | */
/*                 |       |       |       | XXXXX |       |    |       |       |       |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  TD(TD_BOOT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_PGDN,   KC_UP, KC_PGUP, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       CW_TOGG, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  KC_INS, KC_HOME, XXXXXXX,  KC_END, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_ENT, KC_BSPC,  KC_DEL, XXXXXXX, XXXXXXX
),

/* Mouse control */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* | Boot* |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       | LWin  | LAlt  | LCtrl | LSft  |       |                    |       | Left  | Down  |  Up   | Right |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |       |       |       |       |       |       |    |       |       | WLeft | WDown |  WUp  | WRight|       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |       |       | XXXXX |    |  Left | Right | Wheel |       |       | */
/*                 |       |       |       |       | XXXXX |    |  Btn  |  Btn  |  Btn  |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_MOUSE] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  TD(TD_BOOT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX, XXXXXXX
),

/* Symbol keys */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |  [ {  |   &   |   *   |   (   |  ] }  |                    |       |       |       |       |       | Boot* | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |       |   $   |   %   |   ^   |  = +  |                    |       | LSft  | LCtrl | LAlt  | LWin  |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |  ` ~  |   !   |   @   |   #   |  \ |  |       |    |       |       |       |       |       |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |   (   |   )   |  - _  |    | XXXXX |       |       |       |       | */
/*                 |       |       |       |       |       |    | XXXXX |       |       |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_SYMBOL] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RBRC,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_BOOT),
  XXXXXXX, XXXXXXX,  KC_DLR, KC_PERC, KC_CIRC,  KC_EQL,                       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX,  KC_GRV, KC_EXLM,   KC_AT, KC_HASH, KC_BSLS, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_MINS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Number keys */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |       |   7   |   8   |   9   |       |                    |       |       |       |       |       | Boot* | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |       |   4   |   5   |   6   |       |                    |       | LSft  | LCtrl | LAlt  | LWin  |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |       |   1   |   2   |   3   |       |       |    |       |       |       |       |       |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |       |   0   |       |    |       | XXXXX |       |       |       | */
/*                 |       |       |       |       |       |    |       | XXXXX |       |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_NUMBER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_BOOT),
  XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,                         XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX,    KC_0, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/**/
/* Function keys */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |  F12  |   F7  |   F8  |   F9  |       |                    |       |       |       |       |       | Boot* | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |  F11  |   F4  |   F5  |   F6  | ScrLk |                    |       | LSft  | LCtrl | LAlt  | LWin  |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |  F10  |   F1  |   F2  |   F3  | Pause |       |    |       |       |       |       |       |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       | Menu  |  Tab  | Space |    |       |       | XXXXX |       |       | */
/*                 |       |       |       |       |       |    |       |       | XXXXX |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_FUNC] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_BOOT),
  XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX,  KC_APP,  KC_TAB,  KC_SPC,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/**/
/* Description */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |       |       |       |       |       |       |    |       |       |       |       |       |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |       |       |       |    |       |       |       |       |       | */
/*                 |       |       |       |       |       |    |       |       |       |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
/* [NAME] = LAYOUT( */
/*   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/*   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/*   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/*   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/*                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
/* ) */
};
