//
// Created by pmher on 19/04/2021.
//

#include "../Headers/rubiks.h"


void move_menu(Square **** rubiks){
    int choice;
    //Afficher le menu
    do{
        printf("---------------------------------------------------------------------------\n"
               "1.F    2.F'    3.B    4.B'    5.R    6.R'    7.L    8.L'    9.U    10.U'   \n"
               "11.D        12.D'        13.horizontal rotation        14.vertical rotation\n"
               "---------------------------------------------------------------------------\n");
        fflush(stdin);
        //Demander à l'utilisateur de faire un choix
        scanf("%d", &choice);
    }while(choice<1||choice>14);
    switch (choice) {
        //en fonction du choix : effectuer l'action correspondante
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
        case 15:
            if (Step1(rubiks))
                if(Step2(rubiks));
        default:
            printf("Erreur\n");
}
}

int menu(Square **** rubiks){
    int choice;
    //Afficher le menu
    do {
        printf("---------------------------------------------------------------------------\n"
               "1 : Scramble    2:Reset    3:Blank    4:Play    5:Fill    6:Solve    7:Exit\n"
               "---------------------------------------------------------------------------\n");
        fflush(stdin);
        scanf("%d", &choice);

    }while(choice<1||choice>7);    //Demander son choix à l'utilisateur
    switch(choice){
        //En fonction du choix de l'utilisateur, effectuer l'action souhaitée
        case 1:
            scramble_rubiks(rubiks,100);
            break;
        case 2:
            init_rubiks(rubiks);
            break;
        case 3:
            blank_rubiks(rubiks);
            break;
        case 4:
            //renvoie vers le menu de mouvement
            move_menu(rubiks);
            break;
        case 5:
            //fillRubiks
            break;
        case 6:
            //Si l'action est déjà validée, passer à la suivante
            if (Step1(rubiks))
                if (Step2(rubiks))
                    if(Step3(rubiks))
                        if(Step4(rubiks)) {
                            if (Step5(rubiks))
                                if (Step6(rubiks))
                                    printf("Rubiks Already Solved\n");
                        }
            break;
        case 7:
            return 0;
        default:
            printf("Error\n");
    }
    return 1;
}

