//
// Created by pmher on 10/05/2021.
//

#include "../Headers/representationService.h"

Square *** create_rubiks(){
    int i,j;
    //Allouer de la place pour un tableau de double pointeurs de type Square de taille 6
    Square ***rubiks = (Square ***)malloc(6*sizeof(Square**));
    for(i = 0;i<6;i++){
        //Allouer de la place pour un tableau de pointeurs de type Square de taille 3
        rubiks[i] = (Square **)malloc(3*sizeof(Square*));
        for (j = 0;j<3;j++)
            //Allouer de la place pour un tableau de type Square de taille 3
            rubiks[i][j] = (Square *)malloc(3*sizeof(Square));
    }
    //retourner le rubiks
    return rubiks;
}

void free_rubiks(Square **** rubiks){
    int i,j;
    for(i = 0;i<6;i++){
        for (j = 0;j<3;j++)
            //libérer les tableaux de Square
            free((*rubiks)[i][j]);
        //libérer les tableaux de pointeurs de Square
        free((*rubiks)[i]);
    }
    //libérer le pointeur principal
    free(*rubiks);
}

void init_rubiks(Square **** rubiks){
    int i,j,k;
    for (i = 0;i<6;i++){
        for(j = 0;j<3;j++){
            for(k = 0;k<3;k++){
                //mettre sur chaque case un side et une couleur
                (*rubiks)[i][j][k].color = i;
                (*rubiks)[i][j][k].side = i;
            }
        }
    }
}

void fill_rubiks(Square ****rubiks){
    int cpt = 0,bol = 1;
    int i,j,k;
    int used[6] = {0};
    char face = '\0',color = '\0';
    int centers[6] = {0};
    T_COLOR c;
    for(i = 0;i<6;i++){
        for(j = 0;j<3;j++){
            for(k = 0;k<3;k++){
                if((*rubiks)[i][j][k].color!=LG){
                    cpt++;
                    used[(*rubiks)[i][j][k].color]++;
                }
            }
        }
    }
    while(cpt<54) {
        do{
            printf("Enter the face to fill :\n");
            fflush(stdin);
            scanf("%c", &face);
            i = side_to_index(face, *rubiks);
        } while (face != 'F' && face != 'B' && face != 'L' && face != 'R' && face != 'U' && face != 'D' );
        do{
            printf("Enter the line :\n");
            fflush(stdin);
            scanf("%d", &j);
            j--;
        }while (j<0||j>2);
        do{
            printf("Enter the column :\n");
            fflush(stdin);
            scanf("%d", &k);
            k--;
        }while(k<0||k>2);
        do{
            printf("Enter the color :\n");
            fflush(stdin);
            scanf("%c", &color);
        }while (color != 'B' && color != 'R' && color != 'W' && color != 'G' && color != 'O' && color != 'Y' && color != 'L' );
        if ((*rubiks)[i][j][k].color == LG)
            cpt++;
        else {
            used[(*rubiks)[i][j][k].color]--;
        }
        c = select_color(color);
        if(k == 1 && j == 1){
            if(!centers[c])
                centers[c]++;
            else {
                printf("This center is already placed\n");
                bol = 0;
            }
        }
        if (bol) {
            if (c==LG || used[c] < 9) {
                if(c != LG)
                    used[c]++;
                (*rubiks)[i][j][k].color = c;
            } else
                printf("This color is actualy fully used \n");
        }else
            bol = 1;
        display_rubiks(*rubiks);
    }
}

void color_display(int color){
    //Afficher en couleur
    switch (color) {
        //en fonction de color, changer la couleur du texte et afficher la lettre correspondante
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
    //remettre le texte en blanc
    c_textcolor(WHITE);
}

void display_rubiks(Square *** rubiks){
    int i,j,k;
    i = side_to_index('U',rubiks);
    //Afficher la face up
    for (j = 0; j < 3; j++) {
        printf("      ");
        for (k = 0; k < 3; k++) {
            printf(" ");
            color_display(rubiks[i][j][k].color);
        }
        printf("\n");
    }
    printf("\n");

    //Afficher ligne par ligne les face left,front,right,back
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

    //afficher la face down
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
    //pour chaque case, changer la couleur en LG
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
        //tirer un nombre au hasard
        hasard = (rand() % (MAX - MIN + 1)) + MIN;
        switch (hasard) {
            //en fonction du nombre, effectuer un mouvement dans la liste
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