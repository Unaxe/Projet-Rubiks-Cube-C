//
// Created by pmher on 19/04/2021.
//

#ifndef PROJETC_RUBIKS_H
#define PROJETC_RUBIKS_H

#include <stdlib.h>
#include <stdio.h>
#include "conio.h"

typedef enum T_COLOR T_COLOR;
typedef enum T_SIDE T_SIDE;
typedef struct Square Square;

int select_color(char color);
Square *** create_rubiks();
void init_rubiks(Square **** rubiks);
int side_to_index(char side,Square *** rubiks);
void display_rubiks(Square *** rubiks);
void free_rubiks(Square **** rubiks);
void color_display(int color);
void blank_rubiks(Square **** rubiks);
//Rotations sens horaire
void FRONT_clockwise(Square **** rubiks,int type);
void BACK_clockwise(Square **** rubiks,int type);
void UP_clockwise(Square **** rubiks,int type);
void DOWN_clockwise(Square **** rubiks,int type);
void RIGHT_clockwise(Square **** rubiks,int type);
void LEFT_clockwise(Square **** rubiks,int type);
//Rotations sens antihoraire
void FRONT_anticlockwise(Square **** rubiks,int type);
void BACK_anticlockwise(Square **** rubiks,int type);
void UP_anticlockwise(Square **** rubiks,int type);
void DOWN_anticlockwise(Square **** rubiks,int type);
void RIGHT_anticlockwise(Square **** rubiks,int type);
void LEFT_anticlockwise(Square **** rubiks,int type);

void exchangeColors(Square * first,Square * second);
#endif //PROJETC_RUBIKS_H
