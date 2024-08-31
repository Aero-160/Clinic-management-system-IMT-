#include <stdio.h>
#include "../utilities/std_types.h"
#include "Functions.h"


#define defaultPASSWORD 1234


u8 Password() {
    u32 password;
    u8 i = 2;
    printf("Enter Password : ");
    scanf("%d", &password);
    while(i--) {
        if(password != defaultPASSWORD) {        
            printf("Wrong Password. Try Again : ");
            scanf("%d", &password);
        }
    }
    return (password == defaultPASSWORD);
}

void AdminMode() {
    s16 choice;
    if(Password() == 1) {
        while(1) {
            printf("\n------------ Admin Mode ------------\n");
            printf("\t1. LOG New Patient\n");
            printf("\t2. Edit Patient Info\n");
            printf("\t3. View Patient Data\n");
            printf("\t4. Reserve Appointment Slot\n");
            printf("\t5. Cancel Appointment\n");
            printf("\t6. View Reservation List\n");
            printf("\t7. Back to Main Menu\n\n");
            printf("Enter Your Choice : ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    AddPatient();
                    break;
                case 2:
                    EditPatient();
                    break;
                case 3:
                    printPatient();
                    break;
                case 4:
                    AddReservation();
                    break;
                case 5:
                    CancelReservation();
                    break;
                case 6:
                    ViewReservation();
                    break;
                case 7:
                    return;
                default:
                    printf("Invalid Choice\n");
            }
        }
    }
}

void UserMode() {
    s32 choice;
    while (1) {
        printf("\n------------ User Mode ------------\n");
        printf("\t1. View Patient Info\n");
        printf("\t2. View Reservation List\n");
        printf("\t3. Back to Main Menu\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printPatient();
                break;
            case 2:
                ViewReservation();
                break;
            case 3:
                return;
            default:
                printf("Invalid Choice\n");
        }
    }
}