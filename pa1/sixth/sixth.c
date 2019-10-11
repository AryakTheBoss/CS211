#include "sixth.h"

int main(int argc, char ** argv) {

    FILE * input;
    input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("error");
        return 0;
    }

    int valueToInsert;
    BSTnode * root = NULL;

    while (!feof(input)) {
        fscanf(input, "i\t%d\n", &valueToInsert);
        root = insertInOrder(root, valueToInsert);
    }    

    fclose(input);

    printInOrder(root);
    freeInOrder(root);

    return 0;
}

BSTnode * newNode(int val) {
    BSTnode * temp = (BSTnode *) malloc(sizeof(BSTnode)); 
    temp->val = val; 
    temp->left = NULL;
    temp->right = NULL; 
    return temp; 
}

BSTnode * insertInOrder(BSTnode *root, int val) {
    if (!root) { // the tree is empty
        return newNode(val);
    } 
    if (val == root->val) { // already in tree
        return root;
    }
    //a bit of recursion :(
    if (val < root->val) {
        root->left = insertInOrder(root->left, val);
    } else if (val > root->val) {
        root->right = insertInOrder(root->right, val);
    }

    // return the root
    return root; 
}

void printInOrder(BSTnode *root) {
    if (root) { // in order traversal of all the nodes
        printInOrder(root->left); 
        printf("%d\t", root->val);
        printInOrder(root->right); 
    } 
}

void freeInOrder(BSTnode *root) {//free all used memory
    if (root) { // in order traversal of all the nodes
        freeInOrder(root->left); 
        freeInOrder(root->right); 
        free(root);
    } 
}
