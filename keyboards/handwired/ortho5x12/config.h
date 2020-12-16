/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xAAAA
#define PRODUCT_ID      0xF0F0
#define DEVICE_VER      0x0000
#define MANUFACTURER    Alex
#define PRODUCT         ortho5x12
#define DESCRIPTION     Handwired ortholinear keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 13

/* Planck PCB default pin-out */
#define MATRIX_ROW_PINS { A2,  A1,  A0,  B8,  B13 }
#define MATRIX_COL_PINS { A8, A15,  B5,  B4,  B3,  B2,  B1, B0, A4, A5, A6, A7, B9}
#define FORCE_NKRO
#define ENCODERS_PAD_A { B14, A14 }
#define ENCODERS_PAD_B { B15, A14 }
#define ENCODER_RESOLUTION 2


#define QMK_ESC_OUTPUT B7
#define QMK_ESC_INPUT A2
#define QMK_LED     E6

#define DYNAMIC_MACRO_SIZE 256
#define COUNTING_KEY

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*Options for OLED screen*/
#define OLED_TIMEOUT 5000

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
