// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "features/orbital_mouse.h"

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
    _FUNC,
    _NUMBER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * 0. Base layer: QWERTY + Home row GACS modifiers
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
  KC_GRV,        KC_1,        KC_2,        KC_3,        KC_4,         KC_5,                                           KC_6,        KC_7,        KC_8,        KC_9,           KC_0, KC_PSCR,
  KC_TAB,        KC_Q,        KC_W,        KC_E,        KC_R,         KC_T,                                           KC_Y,        KC_U,        KC_I,        KC_O,           KC_P, KC_BSPC,
  KC_ESC, GUI_T(KC_A), ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F),         KC_G,                                           KC_H, SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), GUI_T(KC_SCLN), KC_QUOT,
  KC_LSFT,       KC_Z,        KC_X,        KC_C,        KC_V,         KC_B,      KC_MPLY,           KC_MUTE,          KC_N,        KC_M,     KC_COMM,      KC_DOT,        KC_SLSH, KC_RSFT,
                           KC_LGUI,     KC_LALT,     XXXXXXX, LT(1,KC_TAB), LT(2,KC_SPC),      LT(3,KC_ENT), LT(4,KC_BSPC),     XXXXXXX,     KC_RALT,     KC_RGUI
),

/* 1. Navigation */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       | Boot* |       |       |       |       |                    |  Ins  | Home  |  Up   |  End  |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       | LWin  | LAlt  | LCtrl | LSft  |       |                    | CWord | Left  | Down  | Right |       |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |  C-Z  |  C-X  |  C-C  |  C-V  |       |       |    |       |       | PgDn  | PgUp  |       |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |       | XXXXX |       |    | Enter |  Del  |       |       |       | */
/*                 |       |       |       | XXXXX |       |    |       |       |       |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_NAV] = LAYOUT(
  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, TD(TD_BOOT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_INS, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
  XXXXXXX,     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       CW_TOGG, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX,     C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, XXXXXXX,     XXXXXXX,  KC_INS, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_ENT,  KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX
),

/* 2. Mouse control */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       | Boot* |       |       |       |       |                    |       |       |  Up   |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       | LWin  | LAlt  | LCtrl | LSft  |       |                    |       | Left  | Down  | Right |       |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |       |       |       |       |       |       |    |       |       | WDown |  WUp  |       |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |       |       | XXXXX |    | Left  | Right |       |       |       | */
/*                 |       |       |       |       | XXXXX |    |  Btn  |  Btn  |       |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_MOUSE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,    OM_U, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       XXXXXXX,    OM_L,    OM_D,    OM_R, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  OM_W_D,  OM_W_U, OM_BTN3, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     OM_BTN2, OM_BTN1, XXXXXXX, XXXXXXX, XXXXXXX
),

/**/
/* 3. Functions */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |  F12  |   F7  |   F8  |   F9  | PrtSc |                    |       |       |       |       | Boot* |       | */
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
  XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX,  KC_APP,  KC_TAB,  KC_SPC,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* 4. Number & Symbols */
/* ,-----------------------------------------------,                    ,-----------------------------------------------, */
/* |       |       |       |       |       |       |                    |       |       |       |       |       |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |  [ {  |  7 &  |  8 *  |  9 (  |  ] }  |                    |       |       |       |       | Boot* |       | */
/* |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------| */
/* |       |  ' "  |  4 $  |  5 %  |  6 ^  |  = +  |                    |       | LSft  | LCtrl | LAlt  | LWin  |       | */
/* |-------+-------+-------+-------+-------+-------|-------,    ,-------|-------+-------+-------+-------+-------+-------| */
/* |       |  ` ~  |  1 !  |  2 @  |  3 #  |  \ |  |       |    |       |       |       |       |       |       |       | */
/* `-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------' */
/*                 |       |       |   (   |  0 )  |  - _  |    | XXXXX |       |       |       |       | */
/*                 |       |       |       |       |       |    | XXXXX |       |       |       |       | */
/*                 `---------------------------------------'    '---------------------------------------' */
/**/
[_NUMBER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_QUOT,    KC_4,    KC_5,    KC_6,  KC_EQL,                       XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, KC_LPRN,    KC_0, KC_MINS,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_orbital_mouse(keycode, record)) {
        return false;
    }
    return true;
}

void matrix_scan_user(void) {
    orbital_mouse_task();
}

// shift functions
const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

// mouse scroll wheels
const key_override_t mouse_up_override = ko_make_basic(MOD_MASK_SHIFT, KC_MS_U, KC_WH_U);
const key_override_t mouse_down_override = ko_make_basic(MOD_MASK_SHIFT, KC_MS_D, KC_WH_D);
const key_override_t mouse_left_override = ko_make_basic(MOD_MASK_SHIFT, KC_MS_L, KC_WH_L);
const key_override_t mouse_right_override = ko_make_basic(MOD_MASK_SHIFT, KC_MS_R, KC_WH_R);

const key_override_t *key_overrides[] = {
    &capsword_key_override,
    &mouse_up_override,
    &mouse_down_override,
    &mouse_left_override,
    &mouse_right_override,
};

// Key combos
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
    COMBO(zx_combo, KC_ESC),
};
