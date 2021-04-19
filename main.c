#include "rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    printf("Created\n");
    init_rubiks(&rubiks);
    printf("Inited\n");
    display_rubiks(rubiks);
    printf("Displayed\n");
    UP_clockwise(&rubiks);
    display_rubiks(rubiks);
    free_rubiks(&rubiks);
    printf("Free\n");
    return 0;
}
