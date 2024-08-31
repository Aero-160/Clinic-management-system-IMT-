#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

//Macros
#define NumderOfSlots 5

typedef struct Node Node;
struct Node{
u32 ID;
u8 Gender;
s32 Age;
s8 Name[30];

Node* Next;
};

void AddPatient();
void EditPatient();
void DeletePatient();
void printPatient();


typedef struct {
    u32 ID;
    u8 taken;
} Slot;

void AddReservation();
void CancelReservation();
void ViewReservation();

#endif