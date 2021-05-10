//
// Created by pmher on 10/05/2021.
//

#ifndef RUBIKS_C_MOVEMENTSSERVICE_H
#define RUBIKS_C_MOVEMENTSSERVICE_H
#include "enumTypesServices.h"
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

//rotations du rubiks
void reverseFace(Square *** Face);
void horizontal_rotation(Square **** rubiks);
void vertical_rotation(Square **** rubiks);
void quarterTurnRight(Square **** rubiks);


void exchangeColors(Square * first,Square * second);
void editFaces(int* D,int* B,int* L,int* U,int* F,int* R,Square *** rubiks);


#endif //RUBIKS_C_MOVEMENTSSERVICE_H
