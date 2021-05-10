//
// Created by pmher on 10/05/2021.
//

#include "enumTypesServices.h"
int select_color(char color){
    switch(color) {
        case 'R' :
            return R;
        case 'B' :
            return B;
        case 'G' :
            return G;
        case 'W' :
            return W;
        case 'Y' :
            return Y;
        case 'O' :
            return O;
        default:
            return LG;
    }
}

int side_to_index(char side,Square *** rubiks){
    T_SIDE searched;
    int i;
    switch (side) {
        case 'F':
            searched = FRONT;
            break;
        case 'B':
            searched = BACK;
            break;
        case 'U':
            searched = UP;
            break;
        case 'D':
            searched = DOWN;
            break;
        case 'R':
            searched = RIGHT;
            break;
        case 'L':
            searched = LEFT;
            break;
    }
    for(i = 0; i< 6;i++){
        if(rubiks[i][0][0].side == searched)
            return i;
    }
}