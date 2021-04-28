#include "rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    printf("Created\n");
    init_rubiks(&rubiks);
    printf("Inited\n");
    for(int i = 0;i<100;i++){
        scramble_rubiks(&rubiks);
        /*for(int i = 0;i<100;i++){
            display_rubiks(rubiks);
            move_menu(&rubiks);
        }*/
        if (Step1(&rubiks));
    }
    display_rubiks(rubiks);
    free_rubiks(&rubiks);
    printf("Free\n");
    return 0;
}
