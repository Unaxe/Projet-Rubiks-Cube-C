#include "../Headers/rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    init_rubiks(&rubiks);
    display_rubiks(rubiks);
    while(menu(&rubiks))
        display_rubiks(rubiks);
    free_rubiks(&rubiks);
    return 0;
}
