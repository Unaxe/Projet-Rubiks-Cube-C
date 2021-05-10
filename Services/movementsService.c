//
// Created by pmher on 10/05/2021.
//

#include "../Headers/movementsService.h"


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
    if (DEBUG_MOVEMENTS)
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
    if (DEBUG_MOVEMENTS)
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
    if(DEBUG_MOVEMENTS)
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
    if(DEBUG_MOVEMENTS)
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
    if(DEBUG_MOVEMENTS)
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
    if(DEBUG_MOVEMENTS)
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
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][2][0]));
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][2][2]));
        exchangeColors(&((*rubiks)[F][0][0]), &((*rubiks)[F][0][2]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][1][0]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][2][1]));
        exchangeColors(&((*rubiks)[F][0][1]), &((*rubiks)[F][1][2]));
    }
    if(DEBUG_MOVEMENTS)
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
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][2][0]));
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][2][2]));
        exchangeColors(&((*rubiks)[B][0][0]), &((*rubiks)[B][0][2]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][1][0]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][2][1]));
        exchangeColors(&((*rubiks)[B][0][1]), &((*rubiks)[B][1][2]));
    }
    if(DEBUG_MOVEMENTS)
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
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][0]));
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][2]));
        exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][0][2]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][0]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][2][1]));
        exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][2]));
    }
    if(DEBUG_MOVEMENTS)
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
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][0]));
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][2]));
        exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][0][2]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][0]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][2][1]));
        exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][2]));
    }
    if(DEBUG_MOVEMENTS)
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
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][2][0]));
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][2][2]));
        exchangeColors(&((*rubiks)[R][0][0]), &((*rubiks)[R][0][2]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][1][0]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][2][1]));
        exchangeColors(&((*rubiks)[R][0][1]), &((*rubiks)[R][1][2]));
    }
    if(DEBUG_MOVEMENTS)
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
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][2][0]));
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][2][2]));
        exchangeColors(&((*rubiks)[L][0][0]), &((*rubiks)[L][0][2]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][1][0]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][2][1]));
        exchangeColors(&((*rubiks)[L][0][1]), &((*rubiks)[L][1][2]));
    }
    if(DEBUG_MOVEMENTS)
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

    reverseFace(&((*rubiks)[U]));
    reverseFace(&((*rubiks)[D]));

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
    if(DEBUG_MOVEMENTS)
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

    reverseFace(&((*rubiks)[B]));
    reverseFace(&((*rubiks)[F]));
    reverseFace(&((*rubiks)[L]));
    reverseFace(&((*rubiks)[R]));

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
            (*rubiks)[F][i][j].side = BACK;
        }
    }

    for(i = 0;i<3;i++){
        for(j=0;j<3;j++){
            (*rubiks)[B][i][j].side = FRONT;
        }
    }
    if(DEBUG_MOVEMENTS)
        printf("Vertical-Rotation\n");

}

void exchangeColors(Square * first,Square * second){
    int stock;
    stock = first->color;
    first->color = second->color;
    second->color = stock;
}

void quarterTurnRight(Square **** rubiks){
    int D,B,L,U,F,R,i,j;
    editFaces(&D,&B,&L,&U,&F,&R,*rubiks);

    for(i = 0;i<3;i++){
        for(j = 0;j<3;j++){
            (*rubiks)[F][i][j].side = LEFT;
        }
    }

    for(i = 0;i<3;i++){
        for(j = 0;j<3;j++){
            (*rubiks)[R][i][j].side = FRONT;
        }
    }

    for(i = 0;i<3;i++){
        for(j = 0;j<3;j++){
            (*rubiks)[B][i][j].side = RIGHT;
        }
    }

    for(i = 0;i<3;i++){
        for(j = 0;j<3;j++){
            (*rubiks)[L][i][j].side = BACK;
        }
    }

    //tourner la face up dans le sens horaire
    exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][0][2]));
    exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][2]));
    exchangeColors(&((*rubiks)[U][0][0]), &((*rubiks)[U][2][0]));
    exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][2]));
    exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][2][1]));
    exchangeColors(&((*rubiks)[U][0][1]), &((*rubiks)[U][1][0]));

    //tourner la face down dans le sens antihoraire
    exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][0]));
    exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][2][2]));
    exchangeColors(&((*rubiks)[D][0][0]), &((*rubiks)[D][0][2]));
    exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][0]));
    exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][2][1]));
    exchangeColors(&((*rubiks)[D][0][1]), &((*rubiks)[D][1][2]));


}

void editFaces(int* D,int* B,int* L,int* U,int* F,int* R,Square *** rubiks){
    (*D) = side_to_index('D', rubiks);
    (*B) = side_to_index('B', rubiks);
    (*L) = side_to_index('L', rubiks);
    (*U) = side_to_index('U', rubiks);
    (*F) = side_to_index('F', rubiks);
    (*R) = side_to_index('R', rubiks);
}