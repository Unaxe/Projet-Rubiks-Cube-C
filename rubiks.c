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
        default:
            return -1;
    }
    for(i = 0; i< 6;i++){
        if(rubiks[i][0][0].side == searched)
            return i;
    }
}

Square *** create_rubiks(){
    int i,j;
    Square ***rubiks = (Square ***)malloc(6*sizeof(Square**));
    for(i = 0;i<6;i++){
        rubiks[i] = (Square **)malloc(3*sizeof(Square*));
        for (j = 0;j<3;j++)
            rubiks[i][j] = (Square *)malloc(3*sizeof(Square));
    }
    return rubiks;
}

void free_rubiks(Square **** rubiks){
    int i,j;
    for(i = 0;i<6;i++){
        for (j = 0;j<3;j++)
            free((*rubiks)[i][j]);
        free((*rubiks)[i]);
    }
    free(*rubiks);
}

void init_rubiks(Square **** rubiks){
    int i,j,k;
    for (i = 0;i<6;i++){
        for(j = 0;j<3;j++){
            for(k = 0;k<3;k++){
                (*rubiks)[i][j][k].color = i;
                (*rubiks)[i][j][k].side = i;
                printf("Check : %d %d %d\n",i,j,k);
            }
        }
    }
    printf("End\n");
}

void color_display(int color){
    switch (color) {
        case 0 :
            c_textcolor(4);
            printf("R");
            break;
        case 1 :
            c_textcolor(1);
            printf("B");
            break;
        case 2 :
            c_textcolor(2);
            printf("G");
            break;
        case 3 :
            c_textcolor(15);
            printf("W");
            break;
        case 4 :
            c_textcolor(14);
            printf("Y");
            break;
        case 5 :
            c_textcolor(12);
            printf("O");
            break;
        case -1 :
            c_textcolor(LIGHTGRAY);
            printf("L");
            break;
    }
}


void display_rubiks(Square *** rubiks){
    int i,j,k;
    i = side_to_index('U',rubiks);
    for (j = 0; j < 3; j++) {
        printf("      ");
        for (k = 0; k < 3; k++) {
            printf(" ");
            color_display(rubiks[i][j][k].color);
        }
        printf("\n");
    }


    j = 0;
    i = side_to_index('L',rubiks);
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('F',rubiks);
    printf(" ");
    for (k = 0;k<3;k++) {
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('R',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('B',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    printf("\n");
    j = 1;
    i = side_to_index('L',rubiks);
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('F',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('R',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('B',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    printf("\n");


    j = 2;
    i = side_to_index('L',rubiks);
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('F',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('R',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    i = side_to_index('B',rubiks);
    printf(" ");
    for (k = 0;k<3;k++){
        color_display(rubiks[i][j][k].color);
        printf(" ");
    }
    printf("\n");
    i = side_to_index('D',rubiks);
    for (j = 0; j < 3; j++) {
        printf("      ");
        for (k = 0; k < 3; k++)  {
            printf(" ");
            color_display(rubiks[i][j][k].color);
        }
        printf("\n");
    }
}



