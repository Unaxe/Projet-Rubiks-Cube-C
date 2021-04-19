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
void display_rubiks(Square *** rubiks);
void free_rubiks(Square **** rubiks);
void color_display(int color);

#endif //PROJETC_RUBIKS_H
