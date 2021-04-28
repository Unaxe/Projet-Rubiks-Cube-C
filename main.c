#include "rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    printf("Created\n");
    init_rubiks(&rubiks);
    printf("Inited\n");
    display_rubiks(rubiks);
    scramble_rubiks(&rubiks);
    for(int i = 0;i<10;i++){
        move_menu(&rubiks);
        display_rubiks(rubiks);
    }
    if(Step1(&rubiks));
    display_rubiks(rubiks);
    free_rubiks(&rubiks);
    printf("Free\n");
    return 0;
}
