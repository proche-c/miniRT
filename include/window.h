
#ifndef WINDOW_H
#define WINDOW_H


#include "minirt.h"

#  define KV_ESCAPE 65307
#  define KV_ESCAPE_M 53

#  define KV_SPACE 32
#  define KV_SPACE_M 49

#  define KV_PLUS 61
#  define KV_PLUS_M 24
#  define KV_MINUS 45
#  define KV_MINUS_M 27

#  define KV_PLUS2 65451
#  define KV_MINUS2 65453

#  define KV_R 114
#  define KV_R_M 15

#  define KV_P 112
#  define KV_P_M 35

#  define KV_W 119
#  define KV_W_M 13
#  define KV_A 97
#  define KV_A_M 0
#  define KV_S 115
#  define KV_S_M 1
#  define KV_D 100
#  define KV_D_M 2

#  define KV_C 99
#  define KV_C_M 8

#  define KV_LEFTARROW 65361
#  define KV_LEFTARROW_M 123
#  define KV_RIGHTARROW 65363
#  define KV_RIGHTARROW_M 124
#  define KV_TOPARROW 65362
#  define KV_TOPARROW_M  126
#  define KV_BOTTOMARROW 65364
#  define KV_BOTTOMARROW_M 125

/* Same on linux and macos */

#  define KV_SCROLLUP 4
#  define KV_SCROLLDOWN 5
#  define KV_SCROLLLEFT 7
#  define KV_SCROLLRIGHT 6

#  define KV_SCROLLBUTTON 2

#  define KV_LEFTCLICK 1
#  define KV_RIGHTCLICK 3





enum {
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
};




# endif