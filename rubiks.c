//
// Created by pmher on 19/04/2021.
//

#include "rubiks.h"

enum T_COLOR{
    R,B,G,W,Y,O,LG
};

enum T_SIDE{
    FRONT, BACK, UP, DOWN, RIGHT, LEFT
};

struct Face{
    T_SIDE side;
    T_COLOR squares[3][3];
};
