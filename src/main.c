#include <stdio.h>
#include "../utilities/std_types.h"
#include "log_message.h"
#include "mode_functions.h"

//Password is :1234

void main (void) {
    static s16 choice;
    while (1) {
        Header();
        MainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AdminMode();
                break;
            case 2:
                UserMode();
                break;
            case 3:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid Choice try again\n");
                break;
            }
    }
}