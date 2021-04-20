//
// Created by pmher on 19/04/2021.
//

#include "rubiks.h"

enum T_COLOR{R = 0,B = 1,G = 2,W = 3,Y = 4,O = 5,LG = 6};

enum T_SIDE{FRONT,BACK, UP, DOWN, RIGHT, LEFT};

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
            }
        }
    }
}

void color_display(int color){
    switch (color) {
        case R :
            c_textcolor(RED);
            printf("R");
            break;
        case B :
            c_textcolor(BLUE);
            printf("B");
            break;
        case G :
            c_textcolor(GREEN);
            printf("G");
            break;
        case W :
            c_textcolor(WHITE);
            printf("W");
            break;
        case Y :
            c_textcolor(YELLOW);
            printf("Y");
            break;
        case O :
            c_textcolor(MAGENTA);
            printf("O");
            break;
        case LG :
            c_textcolor(LIGHTGRAY);
            printf("L");
            break;
    }
    c_textcolor(WHITE);
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
    printf("\n");
}

void blank_rubiks(Square **** rubiks){
    int i,j,k;
    for(i = 0; i<6;i++){
        for(j = 0;j<3;j++){
            for (k = 0; k < 3; k++) {
                (*rubiks)[i][j][k].color = LG;
            }
        }
    }
}

void FRONT_clockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,R,L,U,F;
    D = side_to_index('D', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[D][0][2 - i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[D][0][2 - i].color = (*rubiks)[R][0 + i][0].color;
            stock2 = (*rubiks)[L][2 - i][2].color;
            (*rubiks)[L][2 - i][2].color = stock;
            stock = (*rubiks)[U][2][0 + i].color;
            (*rubiks)[U][2][0 + i].color = stock2;
            (*rubiks)[R][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][0][2]));
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][2][2]));
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][2][0]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][1][2]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][2][1]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][1][0]));
    }
}

void UP_clockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    int B,R,L,U,F;
    B = side_to_index('B', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);
    // Rotation du premier groupe de carrés
    for(cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[F][0][2 - i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[F][0][2 - i].color = (*rubiks)[R][0][2 - i].color;
            stock2 = (*rubiks)[L][0][2-i].color;
            (*rubiks)[L][0][2-i].color = stock;
            stock = (*rubiks)[B][0][2 - i].color;
            (*rubiks)[B][0][2 - i].color = stock2;
            (*rubiks)[R][0][2 - i].color = stock;
        }
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][0][2]));
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][2]));
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][0]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][2]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][2][1]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][0]));
    }
}

void BACK_clockwise(Square **** rubiks,int type) {
    int stock, stock2, i,cpt;
    int B, R, L, U, D;
    B = side_to_index('B', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    D = side_to_index('D', *rubiks);
    // Rotation du premier groupe de carrés
    for(cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[D][2][0 + i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[D][2][0 + i].color = (*rubiks)[L][0 + i][0].color;
            stock2 = (*rubiks)[R][2 - i][2].color;
            (*rubiks)[R][2 - i][2].color = stock;
            stock = (*rubiks)[U][0][2 - i].color;
            (*rubiks)[U][0][2 - i].color = stock2;
            (*rubiks)[L][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][0][2]));
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][2][2]));
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][2][0]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][1][2]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][2][1]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][1][0]));
    }
}

void DOWN_clockwise(Square **** rubiks,int type) {
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,R,L,B,F;
    D = side_to_index('D', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    B = side_to_index('B', *rubiks);
    F = side_to_index('F', *rubiks);

    for(cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[B][2][0 + i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[B][2][0 + i].color = (*rubiks)[R][2][0 + i].color;
            stock2 = (*rubiks)[L][2][0 + i].color;
            (*rubiks)[L][2][0 + i].color = stock;
            stock = (*rubiks)[F][2][0 + i].color;
            (*rubiks)[F][2][0 + i].color = stock2;
            (*rubiks)[R][2][0 + i].color = stock;
        }
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][0][2]));
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][2]));
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][0]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][2]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][2][1]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][0]));
    }
}

void RIGHT_clockwise(Square **** rubiks,int type) {
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,R,B,U,F;
    D = side_to_index('D', *rubiks);
    R = side_to_index('R', *rubiks);
    B = side_to_index('B', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);

    for(cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[D][2 - i][2].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[D][2 - i][2].color = (*rubiks)[B][0 + i][0].color;
            stock2 = (*rubiks)[F][2 - i][2].color;
            (*rubiks)[F][2 - i][2].color = stock;
            stock = (*rubiks)[U][2 - i][2].color;
            (*rubiks)[U][2 - i][2].color = stock2;
            (*rubiks)[B][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][0][2]));
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][2][2]));
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][2][0]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][1][2]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][2][1]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][1][0]));
    }
}

void LEFT_clockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,B,L,U,F;
    D = side_to_index('D', *rubiks);
    B = side_to_index('B', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[D][0+i][0].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[D][0+i][0].color = (*rubiks)[F][0 + i][0].color;
            stock2 = (*rubiks)[B][2 - i][2].color;
            (*rubiks)[B][2 - i][2].color = stock;
            stock = (*rubiks)[U][0+i][0].color;
            (*rubiks)[U][0+i][0].color = stock2;
            (*rubiks)[F][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][0][2]));
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][2][2]));
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][2][0]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][1][2]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][2][1]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][1][0]));
    }
}

void FRONT_anticlockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,R,L,U,F;
    D = side_to_index('D', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[U][2][0+i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[U][2][0+ i].color = (*rubiks)[R][0 + i][0].color;
            stock2 = (*rubiks)[L][2 - i][2].color;
            (*rubiks)[L][2 - i][2].color = stock;
            stock = (*rubiks)[D][0][2- i].color;
            (*rubiks)[D][0][2 - i].color = stock2;
            (*rubiks)[R][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][0][2]));
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][2][2]));
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][2][0]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][1][2]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][2][1]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][1][0]));
    }
}

void BACK_anticlockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,R,L,U,B;
    D = side_to_index('D', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    B = side_to_index('B', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[U][0][2-i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[U][0][2- i].color = (*rubiks)[L][0 +i][0].color;
            stock2 = (*rubiks)[R][2 - i][2].color;
            (*rubiks)[R][2 - i][2].color = stock;
            stock = (*rubiks)[D][2][0+i].color;
            (*rubiks)[D][2][0 + i].color = stock2;
            (*rubiks)[L][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][0][2]));
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][2][2]));
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][2][0]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][1][2]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][2][1]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][1][0]));
    }
}

void UP_anticlockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int B,R,L,U,F;
    B = side_to_index('B', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[B][0][2-i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[B][0][2-i].color = (*rubiks)[R][0][2-i].color;
            stock2 = (*rubiks)[L][0][2-i].color;
            (*rubiks)[L][0][2-i].color = stock;
            stock = (*rubiks)[F][0][2- i].color;
            (*rubiks)[F][0][2 - i].color = stock2;
            (*rubiks)[R][0][2-i].color = stock;
        }
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][0][2]));
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][2]));
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][0]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][2]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][2][1]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][0]));
    }
}

void DOWN_anticlockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,R,L,B,F;
    D = side_to_index('D', *rubiks);
    R = side_to_index('R', *rubiks);
    L = side_to_index('L', *rubiks);
    B = side_to_index('B', *rubiks);
    F = side_to_index('F', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[F][2][0+i].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[F][2][0+ i].color = (*rubiks)[R][2][0+i].color;
            stock2 = (*rubiks)[L][2][0+i].color;
            (*rubiks)[L][2][0+i].color = stock;
            stock = (*rubiks)[B][2][0+i].color;
            (*rubiks)[B][2][0+i].color = stock2;
            (*rubiks)[R][2][0+i].color = stock;
        }
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][0][2]));
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][2]));
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][0]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][2]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][2][1]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][0]));
    }
}

void RIGHT_anticlockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,R,B,U,F;
    D = side_to_index('D', *rubiks);
    R = side_to_index('R', *rubiks);
    B = side_to_index('B', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[U][2-i][2].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[U][2-i][2].color = (*rubiks)[B][0+i][0].color;
            stock2 = (*rubiks)[F][2 - i][2].color;
            (*rubiks)[F][2 - i][2].color = stock;
            stock = (*rubiks)[D][2-i][2].color;
            (*rubiks)[D][2-i][2].color = stock2;
            (*rubiks)[B][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][0][2]));
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][2][2]));
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][2][0]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][1][2]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][2][1]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][1][0]));
    }
}

void LEFT_anticlockwise(Square **** rubiks,int type){
    int stock,stock2,i,cpt;
    // Rotation du premier groupe de carrés
    int D,B,L,U,F;
    D = side_to_index('D', *rubiks);
    B = side_to_index('B', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);

    for (cpt = 0;cpt<type;cpt++){
        for (i = 0; i < 3; i++) {
            stock = (*rubiks)[U][0+i][0].color; // stocker la valeur de la case D[0][2]
            (*rubiks)[U][0+i][0].color = (*rubiks)[F][0 + i][0].color;
            stock2 = (*rubiks)[B][2 - i][2].color;
            (*rubiks)[B][2 - i][2].color = stock;
            stock = (*rubiks)[D][0+i][0].color;
            (*rubiks)[D][0+i][0].color = stock2;
            (*rubiks)[F][0 + i][0].color = stock;
        }
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][0][2]));
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][2][2]));
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][2][0]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][1][2]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][2][1]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][1][0]));
    }
}

void exchangeColors(Square * first,Square * second){
    int stock;
    stock = first->color;
    first->color = second->color;
    second->color = stock;
}

