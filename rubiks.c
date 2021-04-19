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

struct Square{
    T_SIDE side;
    T_COLOR color;
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

Square *** create_rubiks(){
    int i,j;
    Square ***T = (Square ***)malloc(6*sizeof(Square**));
    for(i = 0;i<6;i++){
        T[i] = (Square **)malloc(3*sizeof(Square*));
        for (j = 0;j<3;j++)
            T[i][j] = (Square *)malloc(3*sizeof(Square));
    }
}

