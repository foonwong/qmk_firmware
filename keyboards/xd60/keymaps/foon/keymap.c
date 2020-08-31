#include QMK_KEYBOARD_H

#define _NUM 1
#define _FN 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_ansi(
            KC_GRV       , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
            KC_TAB       , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
            LT(2, KC_ESC), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
            KC_LSFT      , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
            KC_LCTL      , KC_LGUI, KC_LALT, KC_SPC , KC_RALT, MO(2)  , KC_RGUI, KC_RCTL
    ),

    // Numpad layer: Toggle to activate from layer 2
    [_NUM] = LAYOUT_60_ansi(
            TG(1)       , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS     , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4   , KC_5   , KC_6   , KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  ,
            TG(1)       , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1   , KC_2   , KC_3   , KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS     , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0   , KC_0   , KC_DOT , KC_TRNS, KC_TRNS,
            KC_TRNS     , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
    ),

    // Function layer, held to access
    [_FN] = LAYOUT_60_ansi(
            TG(1)       , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL,
            KC_TRNS     , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END , KC_PGDN, KC_PGUP, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  ,
            KC_TRNS     , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS     , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
            KC_TRNS     , KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
    )
};


// Loop
void matrix_scan_user(void) {
  // Empty
};


void keyboard_post_init_user(void) {
  // Call the post init code.
    rgblight_sethsv(HSV_MAGENTA); // sets the color to teal/cyan without saving
    rgblight_mode(RGBLIGHT_MODE_BREATHING + 5); // sets mode to Fast breathing without saving
//        rgblight_mode(1); // sets mode to Fast breathing without saving
//        rgblight_sethsv(HSV_PINK); // sets the color to teal/cyan without saving
};


uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _FN:
            backlight_disable();
            rgblight_enable(); 
            break;
        case _NUM:
            backlight_enable(); 
            rgblight_disable(); 
            break;
        default: //  for any other layers, or the default layer
            backlight_disable();
            rgblight_disable(); 
            break;
    }
  return state;
}
