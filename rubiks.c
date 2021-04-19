//
// Created by pmher on 19/04/2021.
//

#include "rubiks.h"

enum T_COLOR{
    R = 0,B = 1,G = 2,W = 3,Y = 4,O = 5,LG = 6
};

enum T_SIDE{
    FRONT , BACK, UP, DOWN, RIGHT, LEFT
};

struct Face{
    T_SIDE side;
    T_COLOR squares[3][3];
};

int select_color(char color){
    switch(color) {
        case 'R' :
            return 0;
        case 'B' :
            return 1;
        case 'G' :
            return 2;
        case 'W' :
            return 3;
        case 'Y' :
            return 4;
        case 'O' :
            return 5;
        default:
            return 6;
    }
}
