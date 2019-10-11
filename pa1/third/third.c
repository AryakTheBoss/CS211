#include "third.h"

int collisionCount = 0;
int successfulSearchCount = 0; 
LLnode* nodesToBeFreed[BUCKET_SIZE + 1];
int insertCount = 0;

int main(int argc, char** argv) {

    FILE *input;
    input = fopen(argv[1], "r");

    if (input == NULL) {
        printf("error");
        return 0;
    }

    char hashMethod;
    int key;
    LLnode* buckets[BUCKET_SIZE + 1]; 

    int i;
    for (i = 0; i < BUCKET_SIZE; i++) { // clear array
    	buckets[i] = NULL;
    }

    while (!feof(input)) {

        fscanf(input, "%c\t%d\n", &hashMethod, &key);

        if (hashMethod == 'i') {
            hashInsert(key, buckets);
            ++insertCount;
        } else if (hashMethod == 's') {
            hashSearch(key, buckets);
        }
    }

    fclose(input);

    printf("%d\n", collisionCount);
    printf("%d", successfulSearchCount);
    freeBuckets(insertCount, nodesToBeFreed);

    return 0;
}

void hashInsert(int key, LLnode* buckets[]) {
    int hashValue = key % BUCKET_SIZE;
    if (hashValue < 0) { 
        hashValue += 10000;
    }
    if (hashValue > BUCKET_SIZE) { 
        return;
    }

    LLnode* hashedNode = (LLnode *) malloc(sizeof(LLnode));
    hashedNode->val = key;

    if (buckets[hashValue] != NULL) { // a collision has occured
        ++collisionCount; 
        LLnode* head = buckets[hashValue]; 

        while (head) {
            if (head->val == key) { // already in list
                free(hashedNode); 
                return;
            } 
            if (!(head->next)) { // reached the end, no duplicates
                head->next = hashedNode; 
                nodesToBeFreed[insertCount] = hashedNode;
                return;
            }
            head = head->next;
        }
    } else { // no collision
        hashedNode->next = NULL;
        buckets[hashValue] = hashedNode;
        nodesToBeFreed[insertCount] = hashedNode;
    }
}

void hashSearch(int key, LLnode* buckets[]) {
    int hashValue = key % BUCKET_SIZE;

    if (hashValue < 0) {
        hashValue += 10000;
    }
    if (hashValue > BUCKET_SIZE) { 
        return;
    }
    
    if (buckets[hashValue]) {
        LLnode* head = buckets[hashValue];
        while (head != NULL) {
            if (head->val == key) {
                ++successfulSearchCount;
            }
            head = head->next;
        }
    }

}

void freeBuckets(int insertCount, LLnode * nodesToBeFreed[]) {
    int i;

    for (i = 0; i < insertCount; i++) {
        if (nodesToBeFreed[i] != NULL) {
            free(nodesToBeFreed[i]);
        }
    } 
}
