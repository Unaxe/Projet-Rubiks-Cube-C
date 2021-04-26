#include "rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    printf("Created\n");
    init_rubiks(&rubiks);
    printf("Inited\n");
    display_rubiks(rubiks);
    printf("Displayed\n");

    for (int i=0;i<2;i++){
        move_menu(&rubiks);
        display_rubiks(rubiks);
    }
    Step1(&rubiks);
    display_rubiks(rubiks);
    free_rubiks(&rubiks);
    printf("Free\n");
    return 0;
}
