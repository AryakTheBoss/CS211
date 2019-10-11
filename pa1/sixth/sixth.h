#include <stdio.h>
#include <stdlib.h>

typedef struct _BSTnode {
    int val;
    struct _BSTnode * left, * right;
} BSTnode;

BSTnode * newNode(int val);
BSTnode * insertInOrder(BSTnode * root, int val);
void printInOrder(BSTnode * root);
void freeInOrder(BSTnode *root);