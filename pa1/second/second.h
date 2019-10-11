#include <stdio.h>
#include <stdlib.h>

typedef struct _LList {
    int val;
    struct _LList *next;
} LList;

LList *head;

LList* llInsertInOrder(LList *head, int val);
LList* llDelete(LList *head, int val);
void printLL(LList *head);