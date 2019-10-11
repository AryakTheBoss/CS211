#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 10000

typedef struct _LList {
    int val;
    struct _LList *next;
} LLnode;

LLnode *head;

void hashInsert(int key, LLnode* buckets[]);
void hashSearch(int key, LLnode* buckets[]);
void freeBuckets(int insertCount, LLnode * insertList[]);