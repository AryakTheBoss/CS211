#include "second.h"

int numOfNodes = 0;

int main(int argc, char** argv) {

    head = NULL;

    FILE *input;
    input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("error");
        return 0;
    }

    char llMethod; //read char from line
    int val; // value at current line

    while (!feof(input)) {

        fscanf(input, "%c\t%d\n", &llMethod, &val);

        if (llMethod == 'i') {
            head = llInsertInOrder(head, val);
        } else if (llMethod == 'd') {
            head = llDelete(head, val);
        }

    }

    fclose(input);
    printLL(head);
    printf("\n");

    return 0;

}

LList* llInsertInOrder(LList *head, int val) {

    ++numOfNodes;

    //node needs to go at the start
    if (head == NULL) {
        head = (LList *) malloc(sizeof(LList));
        head->val = val;
    }
    //node needs to go in middle 
    else {
        
        LList *temp = (LList *) malloc(sizeof(LList));
        temp->val = val;
        LList *currentNode = head;
        LList *previousNode = NULL;

        while (currentNode != NULL) {
            if (currentNode->val >= val) {
                
                
                if (currentNode == head) {
                    temp->next = head;
                    head = temp; // move the val in front of the head
                    break;
                } else if (previousNode->val <= val) {  
                    temp->next = currentNode;
                    previousNode->next = temp;  
                    break;
                }
            }
            previousNode = currentNode;
            currentNode = currentNode->next; 
        }
        
        if (!currentNode && previousNode->val <= val) {
            previousNode->next = temp;
        }

    }
    return head;
}

LList* llDelete(LList *head, int val) {

    if (head != NULL) {
        LList *currentNode = head; 
        LList *previousNode = NULL;
        while (currentNode != NULL) {
            if (currentNode->val == val) {
                if (!currentNode->next && !previousNode) { 
                    free(currentNode); 
                    head = NULL;
                } else if (!currentNode->next && previousNode) { 
                    previousNode->next = NULL;
                    free(currentNode);
                } else if (currentNode->next && !previousNode) { 
                    head = currentNode->next; 
                    free(currentNode);
                } else if (currentNode->next && previousNode) { 
                    previousNode->next = currentNode->next;
                    free(currentNode);
                }
                --numOfNodes;
                break;
            }
            previousNode = currentNode;
            currentNode = currentNode->next; //move up
        }
    }
    return head;
}

void printLL(LList *head) {
    printf("%d\n", numOfNodes);
    if (head != NULL) {
        LList *currentNode = head;
        LList *previousNode = NULL;
        while (currentNode != NULL) {
            if (!previousNode || (previousNode->val != currentNode->val)) { 
                printf("%d", currentNode->val); 
                if (currentNode->next) { 
                    printf("\t");
                } 
            }
            previousNode = currentNode;
            currentNode = currentNode->next; // move forward
        }
    }
}
