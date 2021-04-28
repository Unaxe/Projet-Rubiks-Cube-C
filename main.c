#include "rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    printf("Created\n");
    init_rubiks(&rubiks);
    printf("Inited\n");

    scramble_rubiks(&rubiks);
    display_rubiks(rubiks);
    /*for(int i = 0;i<100;i++){
        display_rubiks(rubiks);
        move_menu(&rubiks);
    }*/
    if (Step1(&rubiks));
    Step2(&rubiks);
    display_rubiks(rubiks);
    free_rubiks(&rubiks);
    printf("Free\n");
    return 0;
}
