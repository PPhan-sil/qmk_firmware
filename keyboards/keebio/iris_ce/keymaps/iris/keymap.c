// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/socd_cleaner.h"

socd_cleaner_t socd_v     = {{KC_W, KC_S}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_h     = {{KC_A, KC_D}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_a_v   = {{KC_UP, KC_DOWN}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_a_h   = {{KC_LEFT, KC_RGHT}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_vim_v = {{KC_J, KC_K}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_vim_h = {{KC_H, KC_L}, SOCD_CLEANER_LAST};

// Layers
enum custom_layers { _QWERTY, _LOWER, _RAISE };

// Macros
enum {
    M1 = SAFE_RANGE,
    M2,
    M3,
};

// Tap Dance
enum {
    TD_CTL_GUI
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Ctrl, twice for Gui
    [TD_CTL_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐                              ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
        KC_ESC,        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                                        KC_6,         KC_7,         KC_8,         KC_9,         KC_0,        KC_BSPC,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_TAB,        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                        KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,        KC_DEL,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
      MO(_LOWER),      KC_A,         KC_S,         KC_D,         KC_F,         KC_G,                                        KC_H,         KC_J,         KC_K,         KC_L,        KC_SCLN,      KC_QUOT,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┐  ┌─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_LSFT,       KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,        KC_LGUI,         KC_SPC,        KC_N,         KC_M,        KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,
  //└─────────────┴─────────────┴─────────────┴───────┬─────┴───────┬─────┴───────┬─────┴───────┬─────┘  └─────┬───────┴─────┬───────┴─────┬───────┴─────┬───────┴─────────────┴─────────────┴─────────────┘
                                                          KC_LALT,  TD(TD_CTL_GUI),   KC_SPC,                  LGUI_T(KC_ENT),  MO(_RAISE),   MO(_LOWER)
  //                                                  └─────────────┴─────────────┴─────────────┘              └─────────────┴─────────────┴─────────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐                              ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
        KC_GRV,        KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,                                       KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_DEL,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_CAPS,        M1,         KC_MS_UP,       M2,           M3,         KC_TRNS,                                    KC_MS_BTN4,   KC_MS_BTN1,   KC_MS_BTN2,  KC_MS_BTN5,    KC_MS_BTN3,     KC_TRNS,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_TRNS,     KC_MS_LEFT,   KC_MS_DOWN,  KC_MS_RIGHT,    KC_TRNS,      KC_TRNS,                                     KC_LEFT,      KC_DOWN,       KC_UP,      KC_RIGHT,       KC_UP,       KC_TRNS,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┐  ┌─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_TRNS,       KC_F11,       KC_F12,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_RPRN,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_LEFT,      KC_DOWN,      KC_RGHT,
  //└─────────────┴─────────────┴─────────────┴───────┬─────┴───────┬─────┴───────┬─────┴───────┬─────┘  └─────┬───────┴─────┬───────┴─────┬───────┴─────┬───────┴─────────────┴─────────────┴─────────────┘
                                                        MO(_RAISE),     KC_LGUI,    KC_MS_BTN1,                   KC_MS_BTN1,   MO(_RAISE),   MO(_LOWER)
  //                                                  └─────────────┴─────────────┴─────────────┘              └─────────────┴─────────────┴─────────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐                              ┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐
        KC_TRNS,      KC_TRNS,      KC_TRNS,      RGB_MOD,      RGB_HUI,      RGB_SAI,                                     KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_MINS,       KC_EQL,      KC_BSLS,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_TRNS,      KC_TRNS,      KC_TRNS,     RGB_RMOD,      RGB_HUD,      RGB_SAD,                                     KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_LBRC,      KC_RBRC,      KC_VOLU,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤                              ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      RGB_VAI,      RGB_SPI,                                  KC_MS_WH_LEFT,KC_MS_WH_DOWN, KC_MS_WH_UP,KC_MS_WH_RIGHT,   KC_MPLY,      KC_VOLD,
  //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┐  ┌─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      RGB_VAD,      RGB_SPD,      KC_TRNS,         RGB_TOG,      KC_TRNS,      KC_PGDN,      KC_PGUP,      KC_MPRV,      KC_MUTE,      KC_MNXT,
  //└─────────────┴─────────────┴─────────────┴───────┬─────┴───────┬─────┴───────┬─────┴───────┬─────┘  └─────┬───────┴─────┬───────┴─────┬───────┴─────┬───────┴─────────────┴─────────────┴─────────────┘
                                                          KC_TRNS,      KC_TRNS,      KC_TRNS,                     KC_TRNS,      KC_TRNS,     TG(_LOWER)
  //                                                  └─────────────┴─────────────┴─────────────┘              └─────────────┴─────────────┴─────────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_socd_cleaner(keycode, record, &socd_v)) { return false; }
  if (!process_socd_cleaner(keycode, record, &socd_h)) { return false; }
  if (!process_socd_cleaner(keycode, record, &socd_a_v)) { return false; }
  if (!process_socd_cleaner(keycode, record, &socd_a_h)) { return false; }
  if (!process_socd_cleaner(keycode, record, &socd_vim_v)) { return false; }
  if (!process_socd_cleaner(keycode, record, &socd_vim_h)) { return false; }
  switch (keycode) {
      // Go to left workspace on Linux and Windows
      case M1:
          if (record->event.pressed) {
              SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
          }
          return false;
      // Go to right workspace on Linux and Windows
      case M2:
          if (record->event.pressed) {
              SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
          }
          return false;
      // Tmux prefix
      case M3:
          if (record->event.pressed) {
              SEND_STRING(SS_LCTL(SS_TAP(X_E)));
          }
          return false;
      // Shift+Backspace -> Ctrl+Backspace
      case KC_BSPC:
          if (record->event.pressed) {
              const uint8_t mods       = get_mods();
              uint8_t       shift_mods = mods & MOD_MASK_SHIFT;
              // Normal behaviour if both shifts are held
              if (shift_mods && shift_mods != MOD_MASK_SHIFT) {
                  unregister_mods(MOD_MASK_SHIFT);
                  register_mods(MOD_MASK_CTRL);
              }
              register_code(KC_BSPC);
              set_mods(mods);
          } else {
              unregister_code(KC_BSPC);
          }
          return false;
  }
  return true;
}
