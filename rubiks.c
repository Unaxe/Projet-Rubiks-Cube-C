//
// Created by pmher on 19/04/2021.
//

#include "rubiks.h"

enum T_COLOR{R = 4,B = 3,G = 2,W = 0,Y = 1,O = 5,LG = 6};

enum T_SIDE{FRONT = 2,BACK = 3, UP = 0, DOWN = 1, RIGHT=4, LEFT=5};

struct Square{
    T_SIDE side;
    T_COLOR color;
};

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
            c_textcolor(LIGHTRED);
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
    printf("\n");

    for(j = 0;j<3;j++) {
        i = side_to_index('L', rubiks);
        for (k = 0; k < 3; k++) {
            color_display(rubiks[i][j][k].color);
            printf(" ");
        }
        i = side_to_index('F', rubiks);
        printf(" ");
        for (k = 0; k < 3; k++) {
            color_display(rubiks[i][j][k].color);
            printf(" ");
        }
        i = side_to_index('R', rubiks);
        printf(" ");
        for (k = 0; k < 3; k++) {
            color_display(rubiks[i][j][k].color);
            printf(" ");
        }
        i = side_to_index('B', rubiks);
        printf(" ");
        for (k = 0; k < 3; k++) {
            color_display(rubiks[i][j][k].color);
            printf(" ");
        }
        printf("\n");
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
    printf("Front-Clockwise-%d\n",type);
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
    printf("Up-Clockwise-%d\n",type);
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
    printf("Back-Clockwise-%d\n",type);
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
    printf("Down-Clockwise-%d\n",type);
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
    printf("Right-Clockwise-%d\n",type);
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
    printf("Left-Clockwise-%d\n",type);
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
    printf("Front-Anti-Clockwise-%d\n",type);
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
    printf("Back-Anti-Clockwise-%d\n",type);
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
    printf("Up-Anti-Clockwise-%d\n",type);
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
    printf("Down-Anti-Clockwise-%d\n",type);
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
    printf("Right-Anti-Clockwise-%d\n",type);
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
    printf("Left-Anti-Clockwise-%d\n",type);
}

void reverseFace(Square *** Face){
    exchangeColors(&((*Face)[0][0]), &((*Face)[2][2]));
    exchangeColors(&((*Face)[0][1]), &((*Face)[2][1]));
    exchangeColors(&((*Face)[0][2]), &((*Face)[2][0]));
    exchangeColors(&((*Face)[1][0]), &((*Face)[1][2]));
}

void horizontal_rotation(Square **** rubiks){
    int D,B,L,U,F,R,i,j;
    D = side_to_index('D', *rubiks);
    B = side_to_index('B', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);
    R = side_to_index('R', *rubiks);

    for(i = 0;i<6;i++){
        reverseFace(&((*rubiks)[i]));
    }


    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[D][i][j].side = UP;
        }
    }
    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[U][i][j].side = DOWN;
        }
    }
    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[L][i][j].side = RIGHT;
        }
    }
    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[R][i][j].side = LEFT;
        }
    }
    printf("Horizontal-Rotation\n");
}

void vertical_rotation(Square **** rubiks){
    int D,B,L,U,F,R,i,j;
    D = side_to_index('D', *rubiks);
    B = side_to_index('B', *rubiks);
    L = side_to_index('L', *rubiks);
    U = side_to_index('U', *rubiks);
    F = side_to_index('F', *rubiks);
    R = side_to_index('R', *rubiks);

    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[D][i][j].side = UP;
        }
    }
    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[U][i][j].side = DOWN;
        }
    }

    reverseFace(&((*rubiks)[D]));
    reverseFace(&((*rubiks)[U]));
    reverseFace(&((*rubiks)[L]));
    reverseFace(&((*rubiks)[R]));

    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[F][i][j].side = BACK;
        }
    }

    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[B][i][j].side = FRONT;
        }
    }
    printf("Vertical-Rotation\n");

}

void exchangeColors(Square * first,Square * second){
    int stock;
    stock = first->color;
    first->color = second->color;
    second->color = stock;
}

void scramble_rubiks(Square **** rubiks){
    srand(time(NULL));
    int hasard,i;
    const int MAX = 14, MIN = 1;
    for(i = 0;i<100;i++){
        hasard = (rand() % (MAX - MIN + 1)) + MIN;
        switch (hasard) {
            case 1 :
                FRONT_clockwise(rubiks,1);
                break;
            case 2:
                FRONT_anticlockwise(rubiks,1);
                break;
            case 3:
                BACK_clockwise(rubiks,1);
                break;
            case 4:
                BACK_anticlockwise(rubiks,1);
                break;
            case 5:
                RIGHT_clockwise(rubiks,1);
                break;
            case 6:
                RIGHT_anticlockwise(rubiks,1);
                break;
            case 7:
                LEFT_clockwise(rubiks,1);
                break;
            case 8:
                LEFT_anticlockwise(rubiks,1);
                break;
            case 9:
                UP_clockwise(rubiks,1);
                break;
            case 10:
                UP_anticlockwise(rubiks,1);
                break;
            case 11:
                DOWN_clockwise(rubiks,1);
                break;
            case 12:
                DOWN_anticlockwise(rubiks,1);
                break;
            case 13:
                horizontal_rotation(rubiks);
                break;
            case 14:
                vertical_rotation(rubiks);
                break;
            default:
                printf("Erreur\n");
        }
    }
}

void move_menu(Square **** rubiks){
    int choice;
    printf("Entrez le choix :\n"
           "1.F\n"
           "2.F'\n"
           "3.B\n"
           "4.B'\n"
           "5.R\n"
           "6.R'\n"
           "7.L\n"
           "8.L'\n"
           "9.U\n"
           "10.U'\n"
           "11.D\n"
           "12.D'\n"
           "13.horizontal rotation\n"
           "14.vertical rotation\n");
    scanf("%d",&choice);
    switch (choice) {
        case 1 :
            FRONT_clockwise(rubiks,1);
            break;
        case 2:
            FRONT_anticlockwise(rubiks,1);
            break;
        case 3:
            BACK_clockwise(rubiks,1);
            break;
        case 4:
            BACK_anticlockwise(rubiks,1);
            break;
        case 5:
            RIGHT_clockwise(rubiks,1);
            break;
        case 6:
            RIGHT_anticlockwise(rubiks,1);
            break;
        case 7:
            LEFT_clockwise(rubiks,1);
            break;
        case 8:
            LEFT_anticlockwise(rubiks,1);
            break;
        case 9:
            UP_clockwise(rubiks,1);
            break;
        case 10:
            UP_anticlockwise(rubiks,1);
            break;
        case 11:
            DOWN_clockwise(rubiks,1);
            break;
        case 12:
            DOWN_anticlockwise(rubiks,1);
            break;
        case 13:
            horizontal_rotation(rubiks);
            break;
        case 14:
            vertical_rotation(rubiks);
            break;
        default:
            printf("Erreur\n");
}
}

void editFaces(int* D,int* B,int* L,int* U,int* F,int* R,Square *** rubiks){
    (*D) = side_to_index('D', rubiks);
    (*B) = side_to_index('B', rubiks);
    (*L) = side_to_index('L', rubiks);
    (*U) = side_to_index('U', rubiks);
    (*F) = side_to_index('F', rubiks);
    (*R) = side_to_index('R', rubiks);
}

int Step1(Square **** rubiks){
    int D,B,L,U,F,R,i,j;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
    if(!(((*rubiks)[U][0][1].color != W || ((*rubiks)[B][0][1].color != (*rubiks)[B][1][1].color)) || ((*rubiks)[U][1][2].color != W || ((*rubiks)[R][0][1].color != (*rubiks)[R][1][1].color)) || ((*rubiks)[U][1][0].color != W || ((*rubiks)[L][0][1].color != (*rubiks)[L][1][1].color)) || ((*rubiks)[U][2][1].color != W || ((*rubiks)[F][0][1].color != (*rubiks)[F][1][1].color))))
        return 1;

    while(((*rubiks)[U][0][1].color != W || ((*rubiks)[B][0][1].color != (*rubiks)[B][1][1].color)) || ((*rubiks)[U][1][2].color != W || ((*rubiks)[R][0][1].color != (*rubiks)[R][1][1].color)) || ((*rubiks)[U][1][0].color != W || ((*rubiks)[L][0][1].color != (*rubiks)[L][1][1].color)) || ((*rubiks)[U][2][1].color != W || ((*rubiks)[F][0][1].color != (*rubiks)[F][1][1].color))   ) {
        display_rubiks(*rubiks);
        if ((*rubiks)[U][1][1].color == Y) {
            vertical_rotation(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 1
        if((*rubiks)[U][0][1].color == (*rubiks)[B][1][1].color && (*rubiks)[B][0][1].color == W){
            BACK_clockwise(rubiks,1);
            UP_anticlockwise(rubiks,1);
            RIGHT_clockwise(rubiks,1);
            UP_clockwise(rubiks,1);
        }

        if((*rubiks)[U][1][2].color == (*rubiks)[R][1][1].color && (*rubiks)[R][0][1].color == W){
            RIGHT_clockwise(rubiks,1);
            UP_anticlockwise(rubiks,1);
            FRONT_clockwise(rubiks,1);
            UP_clockwise(rubiks,1);
        }

        if((*rubiks)[U][1][0].color == (*rubiks)[L][1][1].color && (*rubiks)[L][0][1].color == W){
            LEFT_clockwise(rubiks,1);
            UP_anticlockwise(rubiks,1);
            BACK_clockwise(rubiks,1);
            UP_clockwise(rubiks,1);
        }

        if((*rubiks)[U][2][1].color == (*rubiks)[F][1][1].color && (*rubiks)[F][0][1].color == W){
            FRONT_clockwise(rubiks,1);
            UP_anticlockwise(rubiks,1);
            RIGHT_clockwise(rubiks,1);
            UP_clockwise(rubiks,1);
        }



        //case 2
        if((*rubiks)[B][2][1].color == W){
            if((*rubiks)[D][2][1].color == (*rubiks)[B][1][1].color){
                BACK_anticlockwise(rubiks,1);
                LEFT_anticlockwise(rubiks,1);
                DOWN_anticlockwise(rubiks,1);
                LEFT_clockwise(rubiks,1);
                BACK_anticlockwise(rubiks,2);
            }else {
                DOWN_clockwise(rubiks, 1);
            }
        }

        if((*rubiks)[R][2][1].color == W){
            if((*rubiks)[D][1][2].color == (*rubiks)[R][1][1].color){
                RIGHT_anticlockwise(rubiks,1);
                BACK_anticlockwise(rubiks,1);
                DOWN_anticlockwise(rubiks,1);
                BACK_clockwise(rubiks,1);
                RIGHT_anticlockwise(rubiks,2);
            }else{
                DOWN_clockwise(rubiks, 1);
            }
        }

        if((*rubiks)[L][2][1].color == W){
            if((*rubiks)[D][1][0].color == (*rubiks)[L][1][1].color){
                LEFT_anticlockwise(rubiks,1);
                FRONT_anticlockwise(rubiks,1);
                DOWN_anticlockwise(rubiks,1);
                FRONT_clockwise(rubiks,1);
                LEFT_anticlockwise(rubiks,2);
            }else{
                DOWN_clockwise(rubiks, 1);
            }
        }

        if((*rubiks)[F][2][1].color == W){
            if((*rubiks)[D][0][1].color == (*rubiks)[F][1][1].color){
                FRONT_anticlockwise(rubiks,1);
                RIGHT_anticlockwise(rubiks,1);
                DOWN_anticlockwise(rubiks,1);
                RIGHT_clockwise(rubiks,1);
                FRONT_anticlockwise(rubiks,2);
            }else{
                DOWN_clockwise(rubiks, 1);
            }
        }

        //case 3
        if((*rubiks)[F][1][2].color == W && (*rubiks)[F][1][1].color == (*rubiks)[R][1][0].color){
            RIGHT_anticlockwise(rubiks,1);
            DOWN_anticlockwise(rubiks,1);
            RIGHT_clockwise(rubiks,1);
            FRONT_anticlockwise(rubiks,2);
        }

        if((*rubiks)[R][1][2].color == W && (*rubiks)[R][1][1].color == (*rubiks)[B][1][0].color){
            BACK_anticlockwise(rubiks,1);
            DOWN_anticlockwise(rubiks,1);
            BACK_clockwise(rubiks,1);
            RIGHT_anticlockwise(rubiks,2);
        }

        if((*rubiks)[B][1][2].color == W && (*rubiks)[B][1][1].color == (*rubiks)[L][1][0].color){
            LEFT_anticlockwise(rubiks,1);
            DOWN_anticlockwise(rubiks,1);
            LEFT_clockwise(rubiks,1);
            BACK_anticlockwise(rubiks,2);
        }

        if((*rubiks)[L][1][2].color == W && (*rubiks)[L][1][1].color == (*rubiks)[F][1][0].color){
            FRONT_anticlockwise(rubiks,1);
            DOWN_anticlockwise(rubiks,1);
            FRONT_clockwise(rubiks,1);
            LEFT_anticlockwise(rubiks,2);
        }

        //case 4
        for (i=1;i<8;i+=2){
            if((*rubiks)[D][i/3][i%3].color == W){
                switch (i) {
                    case 1:// case FRONT
                        //
                        if((*rubiks)[F][2][1].color == (*rubiks)[F][1][1].color){
                            FRONT_clockwise(rubiks,2);
                        }else
                            DOWN_clockwise(rubiks,1);
                        break;
                    case 3:// case LEFT
                        if((*rubiks)[L][2][1].color == (*rubiks)[F][L][1].color){
                            LEFT_clockwise(rubiks,2);
                        }else
                            DOWN_clockwise(rubiks,1);
                        break;
                    case 5:// case RIGHT
                        if((*rubiks)[R][2][1].color == (*rubiks)[R][1][1].color){
                            RIGHT_clockwise(rubiks,2);
                        }else
                            DOWN_clockwise(rubiks,1);
                        break;
                    case 7:// case BACK
                        if((*rubiks)[B][2][1].color == (*rubiks)[B][1][1].color){
                            BACK_clockwise(rubiks,2);
                        }else
                            DOWN_clockwise(rubiks,1);
                        break;
                }
            }
        }
        //case 5




    }
    return 0;
}
