#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |Cmd+` |Cmd+{ |Cmd+} | Space|ADJUST|                    |Alt0  |Alt1  |Alt2  | Del  | Ent  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Enter  /       \Space \  |RAISE |BackSP|Ctrl+B|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT( \
    KC_ESC, LGUI(KC_GRV), SGUI(KC_LBRC), SGUI(KC_RBRC), KC_SPC, MO(_ADJUST),   LAG(KC_0), LAG(KC_1), LAG(KC_2), KC_DEL, KC_ENT, KC_BSPC, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_LCBR,                KC_RCBR,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \

    KC_LALT, KC_LGUI, MO(_LOWER),           KC_ENT,                        KC_SPC, MO(_RAISE), KC_BSPC, LCTL(KC_B)),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   -  |   =  | Del  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   `  |   ~  |   _  |   +  |   [  |-------|    |-------|   ]  |      |   (  |   )  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |ADJST | /       /       \      \  |      |      | Del  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
  KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,                                            KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
  KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, KC_DEL,
  KC_TRNS, KC_GRV, KC_TILD, KC_UNDS, KC_PLUS, KC_LBRC,   KC_TRNS,    KC_TRNS,       KC_RBRC, KC_NO, KC_LPRN, KC_RPRN, KC_NO, KC_TRNS,
  KC_TRNS, KC_TRNS, MO(3), KC_TRNS,                                                 KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | F11  | F10  |      |      |      |                    |MPLAY |MRWD  |MFFD  |MUTE  |VOLD  |VOLU  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |WHLDN |MS_UP |WHLUP |      |                    |PGUP  |HOME  | UP   |END   |ACL1  |   0  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |WHLLF |MS_LF |MS_DN |MS_RT |WHLRT |-------.    ,-------|PGDN  |LEFT  |DOWN  |RIGHT |ACL2  |      |
 * |------+------+------+------+------+------|BTN2   |    |BTN1   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
	[_RAISE] = LAYOUT(
  KC_TRNS, KC_F11, KC_F10, KC_NO, KC_NO, KC_TRNS,                                       KC_MPLY, KC_MRWD, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU,
  KC_TRNS, KC_NO, KC_WH_D, KC_MS_U, KC_WH_U, KC_NO,                                     KC_PGUP, KC_HOME, KC_UP, KC_END, KC_ACL1, KC_0,
  KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,                                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ACL2, KC_TRNS,
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_BTN2, KC_BTN1,     KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |  /   |  *   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |WHLUP |      |      |                    |      |  7   |  8   |  9   |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |WHLLF |WHLDN |WHLRT |      |-------.    ,-------|      |  4   |  5   |  6   |  ,   |      |
 * |------+------+------+------+------+------|Cmd+{  |    |Cmd+}  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  1   |  2   |  3   |  =   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |  0   |      |  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_ADJUST] = LAYOUT(
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
  KC_TRNS, KC_NO, KC_NO, KC_WH_U, KC_NO, KC_NO,                                     KC_NO,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_TRNS,
  KC_TRNS, KC_NO, KC_WH_L, KC_WH_D, KC_WH_R, KC_NO,                                 KC_NO,   KC_P4,   KC_P5,   KC_P6, KC_PCMM, KC_TRNS,
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     SGUI(KC_LBRC), SGUI(KC_RBRC),     KC_NO,   KC_P1,   KC_P2,   KC_P3, KC_PEQL, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS,      KC_P0, KC_TRNS, KC_PDOT),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return state;
  // return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
