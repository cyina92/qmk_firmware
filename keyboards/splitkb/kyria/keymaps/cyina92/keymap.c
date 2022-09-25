/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "../../../../../quantum/keymap_extras/keymap_german.h"
#include "../../../../../quantum/keymap_extras/sendstring_german.h"

enum layers {
    _VOU = 0,
    _QWERTY,
    _NAV,
    _NUM,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

enum custome_keycodes {
    CARET = SAFE_RANGE,
    G_ACC,
};

// Aliases for readability
#define VOU      DF(_VOU)
#define QWERTY   DF(_QWERTY)

#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define SYM      MO(_SYM)
#define FKEYS    OSL(_FUNCTION)
#define ADJUST   TG(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define BSP_NAV LT(_NAV, KC_BSPC)
#define SPC_NUM LT(_NUM, KC_SPC)
#define SPC_SYM LT(_SYM, KC_SPC)

// Left-hand home row mods
#define HOME_C LGUI_T(KC_C)
#define HOME_A LALT_T(KC_A)
#define HOME_E LCTL_T(KC_E)
#define HOME_I LSFT_T(KC_I)

// Right-hand home row mods
#define HOME_T RSFT_T(KC_T)
#define HOME_R RCTL_T(KC_R)
#define HOME_N LALT_T(KC_N)
#define HOME_S RGUI_T(KC_S)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
 * Base Layer: Vou
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | ESC    |   V  |   .  |   O  |   U  |   Ä  |                              |   Q  |   G  |   L  |   H  |   F  |   J    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Tab    |   C  |   A  |   E  |   I  |   Y  |                              |   B  |   T  |   R  |   N  |   S  |   ß    |
 * |        |  GUI |  Alt | lCTL |lShift|      |                              |      |lShift| lCTL |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | lShift |   Z  |   X  |   ,  |   Ü  |   Ö  | FKeys|Adjust|  | Del  |      |   P  |   D  |   W  |   M  |   K  |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  Alt | lCTL | Space| Bspc | Enter|  | Enter| Bspc | Space| rCTL | AltGr|
 *                        |      |      | Num  |      |      |  |      | Nav  | Sym  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_VOU] = LAYOUT(
      KC_ESC , DE_V  , DE_DOT, DE_O   , DE_U   , DE_ADIA,                                     DE_Q    , DE_G   , DE_L   , DE_H  , DE_F  , DE_J,
      KC_TAB , HOME_C, HOME_A, HOME_E , HOME_I , DE_Y   ,                                     DE_B    , HOME_T , HOME_R , HOME_N, HOME_S, DE_SS,
      KC_LSFT, DE_Z  , DE_X  , DE_COMM, DE_UDIA, DE_ODIA, FKEYS  , ADJUST , KC_DEL , _______, DE_P    , DE_D   , DE_W   , DE_M  , DE_K  , DE_MINS,
                               KC_LALT, KC_LCTL, SPC_NUM, KC_BSPC, KC_ENT , KC_ENT , BSP_NAV, SPC_SYM , KC_RCTL, KC_RALT
    ),

/*
 * Numbers and Media (DE Layout)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | VolUp|      |      |                              |   .  |   7  |   8  |   9  |   -  |   /    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next |      |                              |   =  |   4  |   5  |   4  |   +  |   *    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | VolDn| Mute |      |      |      |  |      | NumLk|   0  |   1  |   2  |   3  |   ,  | Enter  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Enter| Bspc | Space|      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, _______, _______, KC_VOLU, _______, _______,                                     DE_DOT , DE_7   , DE_8   , DE_9, DE_MINS, DE_SLSH,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                     DE_EQL , DE_4   , DE_5   , DE_6, DE_PLUS, DE_ASTR,
      _______, _______, _______, KC_VOLD, KC_MUTE, _______, _______, _______, _______, KC_NLCK, DE_0   , DE_1   , DE_2   , DE_3, DE_COMM, KC_ENT,
                                 _______, _______, _______, _______, _______, KC_ENT , KC_BSPC, KC_SPC, _______, _______
    ),

/*S
 * Symbols Layer (DE Layout)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   @  |   %  |   {  |   }  |   ^  |                              |   !  |   <  |   >  |   =  |   &  |   €    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   |  |   `  |   (  |   )  |   *  |                              |   ?  |   /  |   :  |   -  |   _  |   µ    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ~  |   #  |   [  |   ]  |   $  |      |      |  |      |      |   +  |   "  |   '  |   \  |   ;  |   °    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | Space| Bspc | Enter|  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, DE_AT  , DE_PERC, DE_LCBR, DE_RCBR, CARET  ,                                     DE_EXLM, DE_LABK, DE_RABK, DE_EQL , DE_AMPR, DE_EURO,
      _______, DE_PIPE, G_ACC  , DE_LPRN, DE_RPRN, DE_ASTR,                                     DE_QUES, DE_SLSH, DE_COLN, DE_MINS, DE_UNDS, DE_MICR,
      _______, DE_TILD, DE_HASH, DE_LBRC, DE_RBRC, DE_DLR , _______, _______, _______, _______, DE_PLUS, DE_DQUO, DE_QUOT, DE_BSLS, DE_SCLN, DE_DEG,
                                 _______, _______, KC_SPC , KC_BSPC, KC_ENT , _______, _______, _______, _______, _______
    ),

 /*
  * Navigation Layer
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      | MW_L | MS_U | MW_R | MW_U |                              | PgUp | MB_1 | MB_2 | Print|Insert| ScrlLk |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      | MS_L | MS_D | MS_R | MW_D |                              | PgDn | Left | Down | Up   | Right| Delete |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      | MA_0 | MA_1 | MA_2 | MB_3 |      |      |  |      |      | Pause| Home | End  |      |      | CapsLk |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      | Space| Bspc | Enter|  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_NAV] = LAYOUT(
       _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                                     KC_PGUP , KC_BTN1, KC_BTN2, KC_PSCR, KC_INS , KC_SLCK,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                     KC_PGDN , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_DEL ,
       _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN3, _______, _______, _______, _______, KC_PAUSE, KC_HOME, KC_END , _______, KC_PSCR, KC_CAPS,
                                  _______, _______, KC_SPC , KC_BSPC, KC_ENT , _______, _______, _______ , _______, _______
     ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | QWERTY |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Vou    | MOD  | VAI  | HUI  | SAI  | TOG  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | RMOD | VAD  | HUD  | SAD  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      QWERTY , _______ , _______, _______, _______, _______,                                    _______, _______, _______, _______, _______, _______,
      VOU    , RGB_MOD , RGB_VAI, RGB_HUI, RGB_SAI, RGB_TOG,                                    _______, _______, _______, _______, _______, _______,
      _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  GUI |  Alt | lCTL |lShift|      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                                     _______, _______, _______, _______, _______, _______,
        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______, _______, _______, _______
    ),

/*
 * QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CARET:
            if (record->event.pressed) {
                SEND_STRING("^ ");
            }
            break;
        case G_ACC:
            if (record->event.pressed) {
                SEND_STRING("` ");
            }
            break;
    }
    return true;
}

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so     that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _VOU:
                oled_write_P(PSTR("Vou\n"), false);
                break;
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Number\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
