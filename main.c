#include "rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    printf("Created\n");
    init_rubiks(&rubiks);
    printf("Inited\n");
    display_rubiks(rubiks);
    printf("Displayed\n");
    LEFT_clockwise(&rubiks,1);
    display_rubiks(rubiks);
    LEFT_anticlockwise(&rubiks,1);
    display_rubiks(rubiks);
    free_rubiks(&rubiks);
    printf("Free\n");
    return 0;
}
