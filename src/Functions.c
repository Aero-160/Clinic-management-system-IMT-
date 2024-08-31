#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utilities/std_types.h"
#include "Functions.h"


//linkedlist intialization
Node* First = NULL;
Node* Last = NULL;

//patient functions
u8 IsIDExist(u32 ID) {
    Node* temp = First;
    while(temp != NULL) {
        if (temp->ID == ID) {
            return 1;
        }
        temp = temp->Next;
    }
    return 0;
}

void AddPatient() {
    u32 c;
    u16 loopIterator = 0;
    Node* newNode = (Node*)malloc(sizeof(Node));
    s8 temp_name[30];
    u8 flag = 0;

    printf("Enter Patient ID : ");
    scanf(" %d", &(newNode->ID));

    if (IsIDExist(newNode->ID) == 1) {
        printf("ID Already Exists. Log Failed\n");
        free(newNode);
        return;
    }

    //////////////////////////// TAke string input from user //////////////////////////////////////////
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter Patient Name : ");
    fgets(temp_name, sizeof(temp_name), stdin);
    temp_name[strcspn(temp_name, "\n")] = '\0';
    strcpy(newNode->Name, temp_name);                                                                    
    ///////////////////////////////////////////////////////////////////////////////////////////////////

    do{
    printf("Enter Patient Gender (M/F): ");
    scanf(" %c", &(newNode->Gender));
    if (newNode->Gender == 'M' || newNode->Gender == 'F') {
        flag = 1;
    } else if (newNode->Gender == 'm' || newNode->Gender == 'f') {
        newNode->Gender = newNode->Gender - ' ';
        flag = 1;
    } else {
        printf("Invalid Gender\n");
    }
    }while(flag != 1);

    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter Patient Age : ");
    scanf("%d", &newNode->Age);

    if (First == NULL) {
        First = newNode;
        Last = newNode;
    } else {
        Last->Next = newNode;
        Last = newNode;
        Last->Next = NULL;
    }    
}

void EditPatient() {
    Node* temp = First;
    u32 ID;
    s32 c;
    s8 temp_name[30];
    u8 flag = 0;
    printf("Enter Patient ID : ");
    scanf(" %d", &ID);
    while(temp != NULL) {
        if (temp->ID == ID) {
            printf("Enter Patient Name : ");
            //////////////////////////// TAke string input from user //////////////////////////////////////////
            while ((c = getchar()) != '\n' && c != EOF);
            fgets(temp_name, sizeof(temp_name), stdin);
            temp_name[strcspn(temp_name, "\n")] = '\0';

            strcpy(temp->Name, temp_name);
            ///////////////////////////////////////////////////////////////////////////////////////////////////
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Enter Patient Age : ");
            scanf("%d", &temp->Age);
            

            do{
            printf("Enter Patient Gender (M/F): ");
            scanf(" %c", &(temp->Gender));
            if (temp->Gender == 'M' || temp->Gender == 'F') {
                flag = 1;
            } else if (temp->Gender == 'm' || temp->Gender == 'f') {
                temp->Gender = temp->Gender - ' ';
                flag = 1;
            } else {
                printf("Invalid Gender\n");
            }
            }while(flag != 1);

            return;
        }
        temp = temp->Next;
    }
}

void DeletePatient() {
    Node* temp = First;
    u32 ID;
    printf("Enter Patient ID : ");
    scanf("%d", &ID);
    if (temp->ID == ID) {
        First = temp->Next;
        free(temp);
        return;
    }
    while(temp->Next != NULL) {
        if (temp->Next->ID == ID) {
            temp->Next = temp->Next->Next;
            free(temp->Next);
            return;
        }
        temp = temp->Next;
    }
    printf("Patient Not Found\n");
}

void printPatient() {
    Node* temp = First;
    u32 ID;
    printf("Enter Patient ID : ");
    scanf(" %d", &ID);
    while(temp != NULL) {
        if (temp->ID == ID) {
            printf("\tID : %d\n\tName : %s\n\tAge : %d\n\tGender : %c\n", temp->ID, temp->Name, temp->Age, temp->Gender);
            return;
        }
        temp = temp->Next;
    }
    printf("Patient Not Found\n");
}

//Slots initialization
Slot slots[NumderOfSlots] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

//reservation functions
void AddReservation() {
    Node* temp = First;
    u8 flag = 0;
    u32 ID;
    u8 temp_Slot;
    u8 i;

    for (i = 0; i < NumderOfSlots; i++) {
        if (slots[i].taken == 0) {
            printf("%d. Slot : empty\n", i + 1, slots[i].ID);
        }
    }

    printf("\n------------\n");
    printf("Enter Patient ID : ");
    scanf(" %d", &ID);

    while(temp != NULL) {
        if (temp->ID == ID) {
            flag = 1;
            break;
        }
        temp = temp->Next;
    }

    if (flag == 0) {
        printf("Patient Not Found\n");
        return;
    }
   
    printf("Enter Slot Number : ");
    scanf(" %c", &temp_Slot);
    
    if (temp_Slot < '1' || temp_Slot > '5') {
        printf("Invalid Slot Number. Reservation Failed\n");
        return;
    } else if (slots[temp_Slot - '0' - 1].taken == 1) {
        printf("Slot Already Taken. Reservation Failed\n");
        return;
    }

    slots[temp_Slot - '0' - 1].ID = ID;
    slots[temp_Slot - '0' - 1].taken = 1;
    printf("Reservation Successful\n");
}

void CancelReservation() {
    u32 IDt;
    u8 i;
    printf("Enter Patient ID : ");
    scanf(" %d", &IDt);

    for (i = 0; i < NumderOfSlots; i++) {
        if (slots[i].ID == IDt) {
            slots[i].ID = 0;
            slots[i].taken = 0;
            printf("Reservation Canceled\n");
            return;
        }
    }
    if(IsIDExist(IDt) == 0) {
        printf("Patient Not Found\n");
    } else {
        printf("Reservation Not Found\n");
    }

}

void ViewReservation() {
    printf("1. %s : %d\n",((slots[0].taken == 0)? "Free" : "taken"), slots[0].ID);
    printf("2. %s : %d\n",((slots[1].taken == 0)? "Free" : "taken"), slots[1].ID);
    printf("3. %s : %d\n",((slots[2].taken == 0)? "Free" : "taken"), slots[2].ID);
    printf("4. %s : %d\n",((slots[3].taken == 0)? "Free" : "taken"), slots[3].ID);
    printf("5. %s : %d\n",((slots[4].taken == 0)? "Free" : "taken"), slots[4].ID);
}