#include "../Headers/rubiks.h"

int main() {
    //Créer le rubiks cube
    Square *** rubiks = create_rubiks();
    //L'initialiser
    init_rubiks(&rubiks);
    //L'afficher
    display_rubiks(rubiks);
    //Tant que l'utilisateur n'a pas choisi de quitter le programme, afficher le menu
    while(menu(&rubiks))
        display_rubiks(rubiks);
    //Libérer l'espace que prends l tableau rubiks
    free_rubiks(&rubiks);
    return 0;
}
