// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
// #define MOUSEKEY_DELAY          0
// #define MOUSEKEY_INTERVAL       16
// #define MOUSEKEY_WHEEL_DELAY    0
// #define MOUSEKEY_MAX_SPEED      7
// #define MOUSEKEY_TIME_TO_MAX    60

#define ORBITAL_MOUSE_SPEED_CURVE \
      {24, 24, 24, 32, 58, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66}
//     |               |               |               |           |
// t = 0.000           1.024           2.048           3.072       3.840 s

#define ORBITAL_MOUSE_RADIUS 18
#define ORBITAL_MOUSE_WHEEL_SPEED 0.4
#define ORBITAL_MOUSE_DBL_DELAY_MS 50
