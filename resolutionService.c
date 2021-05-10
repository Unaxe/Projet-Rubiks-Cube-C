//
// Created by pmher on 10/05/2021.
//

#include "resolutionService.h"

int Step1(Square **** rubiks){
    int D,B,L,U,F,R,i,j,bol,cpt = 0,z;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
    if ((*rubiks)[U][1][1].color == Y) {
        vertical_rotation(rubiks);
        editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
    }
    if(!(((*rubiks)[U][0][1].color != W || ((*rubiks)[B][0][1].color != (*rubiks)[B][1][1].color)) || ((*rubiks)[U][1][2].color != W || ((*rubiks)[R][0][1].color != (*rubiks)[R][1][1].color)) || ((*rubiks)[U][1][0].color != W || ((*rubiks)[L][0][1].color != (*rubiks)[L][1][1].color)) || ((*rubiks)[U][2][1].color != W || ((*rubiks)[F][0][1].color != (*rubiks)[F][1][1].color))))
        return 1;

    while(((*rubiks)[U][0][1].color != W || ((*rubiks)[B][0][1].color != (*rubiks)[B][1][1].color)) || ((*rubiks)[U][1][2].color != W || ((*rubiks)[R][0][1].color != (*rubiks)[R][1][1].color)) || ((*rubiks)[U][1][0].color != W || ((*rubiks)[L][0][1].color != (*rubiks)[L][1][1].color)) || ((*rubiks)[U][2][1].color != W || ((*rubiks)[F][0][1].color != (*rubiks)[F][1][1].color))   ) {
        cpt ++;
        if (cpt>= 1000) {
            scramble_rubiks(rubiks,15);
            cpt = 0;
            printf("rerolled\n");
        }

        if ((*rubiks)[U][1][1].color == Y) {
            vertical_rotation(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 1
        for(z = 0;z<4;z++) {
            if ((*rubiks)[U][2][1].color == (*rubiks)[F][1][1].color && (*rubiks)[F][0][1].color == W) {
                FRONT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }


        bol = 0;
        //case 2
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][2][1].color == W) {
                if ((*rubiks)[D][0][1].color == (*rubiks)[F][1][1].color) {
                    FRONT_anticlockwise(rubiks, 1);
                    RIGHT_anticlockwise(rubiks, 1);
                    DOWN_anticlockwise(rubiks, 1);
                    RIGHT_clockwise(rubiks, 1);
                    FRONT_anticlockwise(rubiks, 2);
                } else bol = 1;
            }
        }

        if (bol)
            DOWN_clockwise(rubiks,1);

        //case 3
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][1][2].color == W && (*rubiks)[F][1][1].color == (*rubiks)[R][1][0].color) {
                RIGHT_anticlockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 2);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 3 bis
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][1][0].color == W && (*rubiks)[F][1][1].color == (*rubiks)[L][1][2].color) {
                LEFT_clockwise(rubiks, 1);
                DOWN_clockwise(rubiks, 1);
                LEFT_anticlockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 2);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 4
        for (i=1;i<8;i+=2){
            if((*rubiks)[U][i/3][i%3].color == W){
                switch (i) {
                    case 1:// case BACK
                        if((*rubiks)[B][0][1].color != (*rubiks)[B][1][1].color)
                            BACK_clockwise(rubiks,2);
                        break;
                    case 3:// case LEFT
                        if((*rubiks)[L][0][1].color != (*rubiks)[L][1][1].color)
                            LEFT_clockwise(rubiks,2);
                        break;
                    case 5:// case RIGHT
                        if((*rubiks)[R][0][1].color != (*rubiks)[R][1][1].color)
                            RIGHT_clockwise(rubiks,2);
                        break;
                    case 7:// case FRONT
                        if((*rubiks)[F][0][1].color != (*rubiks)[F][1][1].color)
                            FRONT_clockwise(rubiks,2);
                        break;
                }
            }
        }
        bol = 0;
        //case 5
        for (i=1;i<8;i+=2){
            if((*rubiks)[D][i/3][i%3].color == W){
                switch (i) {
                    case 1:// case FRONT
                        //
                        if((*rubiks)[F][2][1].color == (*rubiks)[F][1][1].color){
                            FRONT_clockwise(rubiks,2);
                        }else bol = 1;
                        break;
                    case 3:// case LEFT
                        if((*rubiks)[L][2][1].color == (*rubiks)[L][1][1].color){
                            LEFT_clockwise(rubiks,2);
                        }else bol = 1;
                        break;
                    case 5:// case RIGHT
                        if((*rubiks)[R][2][1].color == (*rubiks)[R][1][1].color){
                            RIGHT_clockwise(rubiks,2);
                        }else bol = 1;
                        break;
                    case 7:// case BACK
                        if((*rubiks)[B][2][1].color == (*rubiks)[B][1][1].color){
                            BACK_clockwise(rubiks,2);
                        }else bol = 1;
                        break;
                }
            }
        }
        if (bol)
            DOWN_clockwise(rubiks,1);


        //case 6
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][1][2].color == (*rubiks)[F][1][1].color && (*rubiks)[R][1][0].color == W) {
                FRONT_anticlockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 6 bis
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][1][0].color == (*rubiks)[F][1][1].color && (*rubiks)[L][1][2].color == W) {
                FRONT_clockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }
        //case 7
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][0][1].color == W && (*rubiks)[U][2][1].color == (*rubiks)[R][1][1].color) {
                FRONT_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 7 bis
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][0][1].color == W && (*rubiks)[U][2][1].color == (*rubiks)[L][1][1].color) {
                FRONT_anticlockwise(rubiks, 1);
                LEFT_anticlockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 8
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][1][2].color != (*rubiks)[F][1][1].color && (*rubiks)[R][1][0].color == W) {
                FRONT_clockwise(rubiks, 1);
                DOWN_clockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //case 8bis
        for(z = 0;z<4;z++){
            if ((*rubiks)[F][1][0].color != (*rubiks)[F][1][1].color && (*rubiks)[L][1][2].color == W) {
                FRONT_anticlockwise(rubiks, 1);
                DOWN_clockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }
        //case 9
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][1][2].color == W && (*rubiks)[R][1][0].color != (*rubiks)[F][1][1].color) {
                FRONT_clockwise(rubiks, 1);
                DOWN_clockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }
        //case 9bis
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][1][2].color == W && (*rubiks)[L][1][2].color != (*rubiks)[F][1][1].color) {
                FRONT_anticlockwise(rubiks, 1);
                DOWN_clockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

    }
    return 0;
}

int Step2(Square **** rubiks){
    int D,B,L,U,F,R,i,j,bol,cpt,z;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
    if ((*rubiks)[U][1][1].color == Y) {
        vertical_rotation(rubiks);
        editFaces(&D, &B, &L, &U, &F, &R, *rubiks);
    }

    if(!((*rubiks)[U][0][0].color != W || (*rubiks)[U][0][1].color != W || (*rubiks)[U][0][2].color != W || (*rubiks)[U][1][0].color != W || (*rubiks)[U][1][1].color != W || (*rubiks)[U][1][2].color != W || (*rubiks)[U][2][0].color != W || (*rubiks)[U][2][1].color != W || (*rubiks)[U][2][2].color != W || !((*rubiks)[F][0][0].color == (*rubiks)[F][1][1].color && (*rubiks)[F][0][1].color == (*rubiks)[F][1][1].color && (*rubiks)[F][0][2].color == (*rubiks)[F][1][1].color && (*rubiks)[R][0][0].color == (*rubiks)[R][1][1].color && (*rubiks)[R][0][1].color == (*rubiks)[R][1][1].color && (*rubiks)[R][0][2].color == (*rubiks)[R][1][1].color && (*rubiks)[B][0][0].color == (*rubiks)[B][1][1].color && (*rubiks)[B][0][1].color == (*rubiks)[B][1][1].color && (*rubiks)[B][0][2].color == (*rubiks)[B][1][1].color && (*rubiks)[L][0][0].color == (*rubiks)[L][1][1].color && (*rubiks)[L][0][1].color == (*rubiks)[L][1][1].color && (*rubiks)[L][0][2].color == (*rubiks)[L][1][1].color)))
        return 1;

    while((*rubiks)[U][0][0].color != W || (*rubiks)[U][0][1].color != W || (*rubiks)[U][0][2].color != W || (*rubiks)[U][1][0].color != W || (*rubiks)[U][1][1].color != W || (*rubiks)[U][1][2].color != W || (*rubiks)[U][2][0].color != W || (*rubiks)[U][2][1].color != W || (*rubiks)[U][2][2].color != W || !((*rubiks)[F][0][0].color == (*rubiks)[F][1][1].color && (*rubiks)[F][0][1].color == (*rubiks)[F][1][1].color && (*rubiks)[F][0][2].color == (*rubiks)[F][1][1].color && (*rubiks)[R][0][0].color == (*rubiks)[R][1][1].color && (*rubiks)[R][0][1].color == (*rubiks)[R][1][1].color && (*rubiks)[R][0][2].color == (*rubiks)[R][1][1].color && (*rubiks)[B][0][0].color == (*rubiks)[B][1][1].color && (*rubiks)[B][0][1].color == (*rubiks)[B][1][1].color && (*rubiks)[B][0][2].color == (*rubiks)[B][1][1].color && (*rubiks)[L][0][0].color == (*rubiks)[L][1][1].color && (*rubiks)[L][0][1].color == (*rubiks)[L][1][1].color && (*rubiks)[L][0][2].color == (*rubiks)[L][1][1].color)) {


        //dans le cas ou le coin est originellement en bas à droite
        for(z = 0;z<4;z++){
            //Tester pour la face front, si le coin est bien en bas a droite, le placer sur la face UP
            if (((*rubiks)[F][2][2].color == W || (*rubiks)[D][0][2].color == W || (*rubiks)[R][2][0].color == W) &&
                ((*rubiks)[F][2][2].color == (*rubiks)[F][1][1].color ||
                 (*rubiks)[D][0][2].color == (*rubiks)[F][1][1].color ||
                 (*rubiks)[R][2][0].color == (*rubiks)[F][1][1].color) &&
                ((*rubiks)[F][2][2].color == (*rubiks)[R][1][1].color ||
                 (*rubiks)[D][0][2].color == (*rubiks)[R][1][1].color ||
                 (*rubiks)[R][2][0].color == (*rubiks)[R][1][1].color)) {
                while ((*rubiks)[U][2][2].color != W || (*rubiks)[F][0][2].color != (*rubiks)[F][1][1].color ||
                       (*rubiks)[R][0][0].color != (*rubiks)[R][1][1].color) {
                    RIGHT_anticlockwise(rubiks, 1);
                    DOWN_anticlockwise(rubiks, 1);
                    RIGHT_clockwise(rubiks, 1);
                    DOWN_clockwise(rubiks, 1);
                }
            } else if ((*rubiks)[F][2][2].color == W || (*rubiks)[D][0][2].color == W || (*rubiks)[R][2][0].color == W)
                DOWN_clockwise(rubiks, 1);
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        //dans le cas ou c'est la case en haut à droite
        for(z = 0;z<4;z++) {
            if ((*rubiks)[F][0][2].color == W || (*rubiks)[R][0][0].color == W) {
                RIGHT_anticlockwise(rubiks, 1);
                DOWN_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                DOWN_anticlockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }
    }
    return 0;
}

int Step3(Square **** rubiks){
    int D,B,L,U,F,R,i,j,bol,cpt,z;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
    if ((*rubiks)[U][1][1].color == W) {
        vertical_rotation(rubiks);
        editFaces(&D, &B, &L, &U, &F, &R, *rubiks);
    }

    if(!((*rubiks)[F][1][0].color!=(*rubiks)[F][1][1].color || (*rubiks)[F][1][2].color!=(*rubiks)[F][1][1].color || (*rubiks)[R][1][0].color!=(*rubiks)[R][1][1].color || (*rubiks)[R][1][2].color!=(*rubiks)[R][1][1].color || (*rubiks)[B][1][0].color!=(*rubiks)[B][1][1].color || (*rubiks)[B][1][2].color!=(*rubiks)[B][1][1].color || (*rubiks)[L][1][0].color!=(*rubiks)[L][1][1].color || (*rubiks)[L][1][2].color!=(*rubiks)[L][1][1].color))
        return 1;

    while((*rubiks)[F][1][0].color!=(*rubiks)[F][1][1].color || (*rubiks)[F][1][2].color!=(*rubiks)[F][1][1].color || (*rubiks)[R][1][0].color!=(*rubiks)[R][1][1].color || (*rubiks)[R][1][2].color!=(*rubiks)[R][1][1].color || (*rubiks)[B][1][0].color!=(*rubiks)[B][1][1].color || (*rubiks)[B][1][2].color!=(*rubiks)[B][1][1].color || (*rubiks)[L][1][0].color!=(*rubiks)[L][1][1].color || (*rubiks)[L][1][2].color!=(*rubiks)[L][1][1].color){


        for(z = 0;z<4;z++){
            if((*rubiks)[F][0][1].color == (*rubiks)[F][1][1].color && (*rubiks)[U][2][1].color != Y){
                if((*rubiks)[U][2][1].color == (*rubiks)[R][1][1].color){
                    UP_clockwise(rubiks,1);
                    RIGHT_clockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    RIGHT_anticlockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    FRONT_anticlockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    FRONT_clockwise(rubiks,1);
                }else if((*rubiks)[U][2][1].color == (*rubiks)[L][1][1].color){
                    UP_anticlockwise(rubiks,1);
                    LEFT_anticlockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    LEFT_clockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    FRONT_clockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    FRONT_anticlockwise(rubiks,1);
                }
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        for(z = 0;z<4;z++) {
            //cas de mauvaise orientation
            if ((*rubiks)[F][1][2].color == (*rubiks)[R][1][1].color &&
                (*rubiks)[R][1][0].color == (*rubiks)[F][1][1].color) {
                UP_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 1);
                UP_clockwise(rubiks, 2);
                UP_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }


        //Dans le cas ou il y a une mauvaise couleur à une position angulaire
        for(z = 0;z<4;z++){
            if (((*rubiks)[F][1][2].color != (*rubiks)[R][1][1].color &&
                 (*rubiks)[F][1][2].color != (*rubiks)[F][1][1].color) ||
                ((*rubiks)[R][1][0].color != (*rubiks)[F][1][1].color &&
                 (*rubiks)[R][1][0].color != (*rubiks)[R][1][1].color) && (*rubiks)[F][1][2].color != Y &&
                (*rubiks)[R][1][0].color != Y) {
                UP_clockwise(rubiks, 1);
                RIGHT_clockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                RIGHT_anticlockwise(rubiks, 1);
                UP_anticlockwise(rubiks, 1);
                FRONT_anticlockwise(rubiks, 1);
                UP_clockwise(rubiks, 1);
                FRONT_clockwise(rubiks, 1);
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }

        UP_clockwise(rubiks,1);



    }
    return 0;
}

int Step4(Square **** rubiks){
    int D,B,L,U,F,R,i,cpt = 0,z,bol;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
    if(!((*rubiks)[U][0][1].color != Y || (*rubiks)[U][1][0].color != Y || (*rubiks)[U][1][2].color != Y || (*rubiks)[U][2][1].color != Y || (*rubiks)[F][0][1].color != (*rubiks)[F][1][1].color || (*rubiks)[R][0][1].color != (*rubiks)[R][1][1].color || (*rubiks)[B][0][1].color != (*rubiks)[B][1][1].color || (*rubiks)[L][0][1].color != (*rubiks)[L][1][1].color))
        return 1;


    while((*rubiks)[U][0][1].color != Y || (*rubiks)[U][1][0].color != Y || (*rubiks)[U][1][2].color != Y || (*rubiks)[U][2][1].color != Y || (*rubiks)[F][0][1].color != (*rubiks)[F][1][1].color || (*rubiks)[R][0][1].color != (*rubiks)[R][1][1].color || (*rubiks)[B][0][1].color != (*rubiks)[B][1][1].color || (*rubiks)[L][0][1].color != (*rubiks)[L][1][1].color){
        //compter le nombre de cubes de la croix bien placés
        cpt = 0;
        for(i = 1;i<8; i+=2){
            if((*rubiks)[U][i/3][i%3].color == Y)
                cpt++;
        }

        switch (cpt) {
            //dans les cas 1 ou 2, la croix n'est pas encore faite, si c'est cas 4, alors résoudre bien orienter la croix
            case 0:
                RIGHT_anticlockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                FRONT_anticlockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                FRONT_clockwise(rubiks,1);
                RIGHT_clockwise(rubiks,1);
                FRONT_clockwise(rubiks,1);
                RIGHT_clockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                RIGHT_anticlockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                FRONT_anticlockwise(rubiks,1);
                break;
            case 1:
                RIGHT_anticlockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                FRONT_anticlockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                FRONT_clockwise(rubiks,1);
                RIGHT_clockwise(rubiks,1);
                FRONT_clockwise(rubiks,1);
                RIGHT_clockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                RIGHT_anticlockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                FRONT_anticlockwise(rubiks,1);
                break;
            case 2:
                if((*rubiks)[U][0][1].color == (*rubiks)[U][2][1].color || (*rubiks)[U][1][0].color == (*rubiks)[U][1][2].color){
                    //cas de la barre jaune
                    if((*rubiks)[U][0][1].color == Y)
                        UP_clockwise(rubiks,1);
                    FRONT_clockwise(rubiks,1);
                    RIGHT_clockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    RIGHT_anticlockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    FRONT_anticlockwise(rubiks,1);
                }else{
                    //cas du L
                    for(i = 0;i<2;i++){
                        if((*rubiks)[U][2][1].color == Y)
                            UP_clockwise(rubiks,1);
                        else if((*rubiks)[U][1][2].color == Y)
                            UP_anticlockwise(rubiks,1);
                    }
                    RIGHT_anticlockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    FRONT_anticlockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    FRONT_clockwise(rubiks,1);
                    RIGHT_clockwise(rubiks,1);
                }
                break;
            case 4:
                cpt = 0;
                if ((*rubiks)[F][0][1].color == (*rubiks)[F][1][1].color )
                    cpt++;
                if ((*rubiks)[R][0][1].color == (*rubiks)[R][1][1].color )
                    cpt++;
                if ((*rubiks)[L][0][1].color == (*rubiks)[L][1][1].color )
                    cpt++;
                if ((*rubiks)[B][0][1].color == (*rubiks)[B][1][1].color )
                    cpt++;
                if(cpt == 2){
                    bol = 1;
                    for(z = 0;z<4 && bol;z++){
                        if((*rubiks)[L][0][1].color == (*rubiks)[L][1][1].color && (*rubiks)[B][0][1].color == (*rubiks)[B][1][1].color){ // deux cotés cotes a cote
                            RIGHT_clockwise(rubiks,1);
                            UP_clockwise(rubiks,2);
                            RIGHT_anticlockwise(rubiks,1);
                            UP_anticlockwise(rubiks,1);
                            RIGHT_clockwise(rubiks,1);
                            UP_anticlockwise(rubiks,1);
                            RIGHT_anticlockwise(rubiks,1);
                            UP_anticlockwise(rubiks,1);
                            bol = 0;
                        }else if((*rubiks)[F][0][1].color == (*rubiks)[F][1][1].color && (*rubiks)[B][0][1].color == (*rubiks)[B][1][1].color){ // deux cotés opposés
                            RIGHT_clockwise(rubiks,1);
                            UP_clockwise(rubiks,2);
                            RIGHT_anticlockwise(rubiks,1);
                            UP_anticlockwise(rubiks,1);
                            RIGHT_clockwise(rubiks,1);
                            UP_anticlockwise(rubiks,1);
                            RIGHT_anticlockwise(rubiks,1);
                            bol = 0;
                        }
                        quarterTurnRight(rubiks);
                        editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
                    }
                }else{
                    UP_clockwise(rubiks,1);
                }




                break;

        }

    }
    return 0;
}

int Step5(Square **** rubiks){
    int D,B,L,U,F,R,i,cpt = 0,z,bol;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);

    for(z = 0;z<4;z++){
        if(((*rubiks)[F][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[F][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[F][1][1].color == (*rubiks)[U][2][0].color  )
           &&  ((*rubiks)[U][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[U][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[U][1][1].color == (*rubiks)[U][2][0].color)
           &&  ((*rubiks)[L][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[L][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[L][1][1].color == (*rubiks)[U][2][0].color  )){
            cpt++;
        }
        quarterTurnRight(rubiks);
        editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
    }
    if(cpt == 4)
        return 1;

    while(cpt != 4){
        cpt = 0;
        for(z = 0;z<4;z++){
            if(((*rubiks)[F][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[F][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[F][1][1].color == (*rubiks)[U][2][0].color  )
               &&  ((*rubiks)[U][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[U][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[U][1][1].color == (*rubiks)[U][2][0].color)
               &&  ((*rubiks)[L][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[L][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[L][1][1].color == (*rubiks)[U][2][0].color  )){
                cpt++;
            }
            quarterTurnRight(rubiks);
            editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
        }
        printf("%d\n",cpt);
        display_rubiks(*rubiks);
        if(cpt == 0){
            LEFT_anticlockwise(rubiks,1);
            UP_clockwise(rubiks,1);
            RIGHT_clockwise(rubiks,1);
            UP_anticlockwise(rubiks,1);
            LEFT_clockwise(rubiks,1);
            UP_clockwise(rubiks,1);
            RIGHT_anticlockwise(rubiks,1);
            UP_anticlockwise(rubiks,1);
        }
        if(cpt == 1){
            bol = 1;
            for(z = 0;z<4 && bol;z++){
                //cas du coin Front/Up/Left bien placé et rotation sens horaire des autres coins
                if(((((*rubiks)[F][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[F][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[F][1][1].color == (*rubiks)[U][2][0].color  )// Si le coin en haut a gauche est bien placé //couleur de la face front
                     &&  ((*rubiks)[U][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[U][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[U][1][1].color == (*rubiks)[U][2][0].color)
                     &&  ((*rubiks)[L][1][1].color == (*rubiks)[F][0][0].color || (*rubiks)[L][1][1].color == (*rubiks)[L][0][2].color || (*rubiks)[L][1][1].color == (*rubiks)[U][2][0].color  )))
                   &&
                   (((*rubiks)[B][1][1].color == (*rubiks)[R][0][2].color || (*rubiks)[B][1][1].color == (*rubiks)[B][0][0].color || (*rubiks)[B][1][1].color == (*rubiks)[U][0][2].color)
                    &&((*rubiks)[U][1][1].color == (*rubiks)[R][0][2].color || (*rubiks)[U][1][1].color == (*rubiks)[B][0][0].color || (*rubiks)[U][1][1].color == (*rubiks)[U][0][2].color)
                    &&((*rubiks)[L][1][1].color == (*rubiks)[R][0][2].color || (*rubiks)[L][1][1].color == (*rubiks)[B][0][0].color || (*rubiks)[L][1][1].color == (*rubiks)[U][0][2].color))) {
                    bol = 0;
                    printf("case 1\n");
                    RIGHT_clockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    LEFT_anticlockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    RIGHT_anticlockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    LEFT_clockwise(rubiks,1);
                    UP_clockwise(rubiks,1);//cas 2
                }else if((((*rubiks)[F][1][1].color == (*rubiks)[F][0][2].color || (*rubiks)[F][1][1].color == (*rubiks)[R][0][0].color || (*rubiks)[F][1][1].color == (*rubiks)[U][2][2].color )
                          &&((*rubiks)[U][1][1].color == (*rubiks)[F][0][2].color || (*rubiks)[U][1][1].color == (*rubiks)[R][0][0].color || (*rubiks)[U][1][1].color == (*rubiks)[U][2][2].color)
                          &&((*rubiks)[R][1][1].color == (*rubiks)[F][0][2].color || (*rubiks)[R][1][1].color == (*rubiks)[R][0][0].color || (*rubiks)[R][1][1].color == (*rubiks)[U][2][2].color))
                         &&
                         (((*rubiks)[B][1][1].color == (*rubiks)[L][0][0].color || (*rubiks)[B][1][1].color == (*rubiks)[B][0][2].color || (*rubiks)[B][1][1].color == (*rubiks)[U][0][0].color)//verifier la rotation
                          &&((*rubiks)[R][1][1].color == (*rubiks)[L][0][0].color || (*rubiks)[R][1][1].color == (*rubiks)[B][0][2].color || (*rubiks)[R][1][1].color == (*rubiks)[U][0][0].color)
                          &&((*rubiks)[U][1][1].color == (*rubiks)[L][0][0].color || (*rubiks)[U][1][1].color == (*rubiks)[B][0][2].color || (*rubiks)[U][1][1].color == (*rubiks)[U][0][0].color))) {//coin haut droit
                    bol = 0;
                    printf("case 2\n");
                    LEFT_anticlockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    RIGHT_clockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    LEFT_clockwise(rubiks,1);// cas 1
                    UP_clockwise(rubiks,1);
                    RIGHT_anticlockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                }



                quarterTurnRight(rubiks);
                editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
            }
        }


    }

    return 0;
}

int Step6(Square **** rubiks){
    int D,B,L,U,F,R,i,cpt = 0,z,bol;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);

    if((*rubiks)[U][0][0].color == Y && (*rubiks)[U][0][2].color == Y && (*rubiks)[U][2][0].color == Y && (*rubiks)[U][2][2].color == Y)
        return 1;


    while((*rubiks)[U][0][0].color != Y || (*rubiks)[U][0][2].color != Y || (*rubiks)[U][2][0].color != Y || (*rubiks)[U][2][2].color != Y){
        cpt = 0;
        if((*rubiks)[U][0][0].color == Y)
            cpt++;
        if((*rubiks)[U][0][2].color == Y)
            cpt++;
        if((*rubiks)[U][2][0].color == Y)
            cpt++;
        if((*rubiks)[U][2][2].color == Y)
            cpt++;

        switch (cpt) {
            case 0:
                RIGHT_clockwise(rubiks,1);
                UP_clockwise(rubiks,2);
                RIGHT_anticlockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                RIGHT_clockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                RIGHT_anticlockwise(rubiks,1);
                LEFT_anticlockwise(rubiks,1);
                UP_clockwise(rubiks,2);
                LEFT_clockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                LEFT_anticlockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                LEFT_clockwise(rubiks,1);
                break;
            case 1:
                while((((*rubiks)[F][0][0].color != Y && (*rubiks)[F][0][2].color != Y )|| ((*rubiks)[R][0][0].color != Y && (*rubiks)[R][0][2].color != Y) ||((*rubiks)[L][0][0].color != Y && (*rubiks)[L][0][2].color != Y))&& (((*rubiks)[B][0][0].color != Y && (*rubiks)[B][0][2].color != Y )|| ((*rubiks)[R][0][0].color != Y && (*rubiks)[R][0][2].color != Y) ||((*rubiks)[L][0][0].color != Y && (*rubiks)[L][0][2].color != Y))){
                    quarterTurnRight(rubiks);
                    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
                }
                RIGHT_clockwise(rubiks,1);
                UP_clockwise(rubiks,2);
                RIGHT_anticlockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                RIGHT_clockwise(rubiks,1);
                UP_anticlockwise(rubiks,1);
                RIGHT_anticlockwise(rubiks,1);
                LEFT_anticlockwise(rubiks,1);
                UP_clockwise(rubiks,2);
                LEFT_clockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                LEFT_anticlockwise(rubiks,1);
                UP_clockwise(rubiks,1);
                LEFT_clockwise(rubiks,1);
                break;
            case 2:
                while(((*rubiks)[U][0][2].color == Y || (*rubiks)[U][2][2].color == Y ) && ((*rubiks)[U][2][0].color == Y || (*rubiks)[U][0][2].color == Y || (*rubiks)[F][0][0].color != Y ) && ((*rubiks)[U][0][0].color == Y || (*rubiks)[U][2][2].color == Y || (*rubiks)[F][0][2].color != Y )){
                    quarterTurnRight(rubiks);
                    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);
                    printf("a\n");
                }
                if((*rubiks)[U][0][2].color != Y && (*rubiks)[U][2][2].color != Y) {
                    do {
                        RIGHT_clockwise(rubiks, 1);         //R
                        UP_clockwise(rubiks, 2);            //U2
                        RIGHT_anticlockwise(rubiks, 1);     //R'
                        UP_anticlockwise(rubiks, 1);        //U'
                        RIGHT_clockwise(rubiks, 1);         //R
                        UP_anticlockwise(rubiks, 1);        //U'
                        RIGHT_anticlockwise(rubiks, 1);     //R'
                        LEFT_anticlockwise(rubiks, 1);      //L'
                        UP_clockwise(rubiks, 2);            //U
                        LEFT_clockwise(rubiks, 1);          //L
                        UP_clockwise(rubiks, 1);            //U2
                        LEFT_anticlockwise(rubiks, 1);      //L'
                        UP_clockwise(rubiks, 1);            //U
                        LEFT_clockwise(rubiks, 1);          //L
                    } while ((*rubiks)[U][0][2].color != Y);
                }
                if(((*rubiks)[U][0][0].color != Y && (*rubiks)[U][2][2].color != Y) || ((*rubiks)[U][2][0].color != Y && (*rubiks)[U][0][2].color != Y)){
                    FRONT_clockwise(rubiks,1);
                    RIGHT_clockwise(rubiks,1);
                    UP_clockwise(rubiks,2);
                    RIGHT_anticlockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    RIGHT_clockwise(rubiks,1);
                    UP_anticlockwise(rubiks,1);
                    RIGHT_anticlockwise(rubiks,1);
                    LEFT_anticlockwise(rubiks,1);
                    UP_clockwise(rubiks,2);
                    LEFT_clockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    LEFT_anticlockwise(rubiks,1);
                    UP_clockwise(rubiks,1);
                    LEFT_clockwise(rubiks,1);
                    FRONT_anticlockwise(rubiks,1);
                }

                break;


        }

    }

    return 0;
}