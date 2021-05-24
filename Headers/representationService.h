//
// Created by pmher on 10/05/2021.
//

#ifndef RUBIKS_C_REPRESENTATIONSERVICE_H
#define RUBIKS_C_REPRESENTATIONSERVICE_H
#include "enumTypesServices.h"
#include "movementsService.h"

Square *** create_rubiks();
void init_rubiks(Square **** rubiks);
void display_rubiks(Square *** rubiks);
void free_rubiks(Square **** rubiks);
void color_display(int color);
void blank_rubiks(Square **** rubiks);
void scramble_rubiks(Square **** rubiks,int numb);
void fill_rubiks(Square ****rubiks);


#endif //RUBIKS_C_REPRESENTATIONSERVICE_H
