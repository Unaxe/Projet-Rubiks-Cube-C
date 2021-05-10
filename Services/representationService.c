//
// Created by pmher on 10/05/2021.
//

#include "../Headers/representationService.h"

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

void scramble_rubiks(Square **** rubiks,int numb){
    srand(time(NULL));
    int hasard,i;
    const int MAX = 14, MIN = 1;
    for(i = 0;i<numb;i++){
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