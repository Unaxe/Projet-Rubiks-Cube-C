#include "rubiks.h"

int main() {
    Square *** rubiks = create_rubiks();
    init_rubiks(&rubiks);
    display_rubiks(rubiks);
    /*printf("Step1 : \n");
    Step1(&rubiks);
    display_rubiks(rubiks);
    printf("Step2 : \n");
    Step2(&rubiks);
    display_rubiks(rubiks);
    printf("Step3 : \n");
    Step3(&rubiks);
    display_rubiks(rubiks);
    printf("Step4 : \n");
    Step4(&rubiks);*/
    display_rubiks(rubiks);
    while(menu(&rubiks))
        display_rubiks(rubiks);
    free_rubiks(&rubiks);
    return 0;
}
