//
// Created by pmher on 10/05/2021.
//

#ifndef RUBIKS_C_TYPEDEFS_H
#define RUBIKS_C_TYPEDEFS_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "conio.h"


typedef enum {R = 4,
    B = 3,
    G = 2,
    W = 0,
    Y = 1,
    O = 5,
    LG = 6}T_COLOR;
typedef enum {FRONT = 2,
    BACK = 3,
    UP = 0,
    DOWN = 1,
    RIGHT=4,
    LEFT=5}T_SIDE;

typedef struct {
    T_SIDE side;
    T_COLOR color;
} Square;
#define DEBUG_MOVEMENTS 1


#endif //RUBIKS_C_TYPEDEFS_H
