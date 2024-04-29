
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 6

typedef struct Node {
    int key;
    int value;
    struct Node *forward[MAX_LEVEL + 1];
} Node;

typedef struct SkipList {
    Node *header;
    int level;
} SkipList;

Node *createNode(int key, int value, int level) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    for (int i = 0; i <= level; i++) {
        newNode->forward[i] = NULL;
    }
    return newNode;
}

int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

SkipList *initializeSkipList() {
    SkipList *skipList = (SkipList *)malloc(sizeof(SkipList));
    skipList->header = createNode(INT_MIN, 0, MAX_LEVEL);
    skipList->level = 0;
    return skipList;
}

void insert(SkipList *skipList, int key, int value) {
    Node *update[MAX_LEVEL + 1];
    Node *current = skipList->header;
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || current->key != key) {
        int newLevel = randomLevel();
        if (newLevel > skipList->level) {
            for (int i = skipList->level + 1; i <= newLevel; i++) {
                update[i] = skipList->header;
            }
            skipList->level = newLevel;
        }
        Node *newNode = createNode(key, value, newLevel);
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void printSkipList(SkipList *skipList) {
    printf("Skip List:\n");
    for (int level = skipList->level; level >= 0; level--) {
        Node *node = skipList->header->forward[level];
        printf("Level %d: ", level);
        while (node != NULL) {
            printf("(%d, %d) ", node->key, node->value);
            node = node->forward[level];
        }
        printf("\n");
    }
}

//search operation
int search(SkipList *skiplist, int key){
    Node *current = skiplist->header;
    for(int i = skiplist->level; i>=0;i--){
        while(current->forward[i] != NULL && current->forward[i]->key < keyy){
            current = current->forward[i];
        }
    }
    current = current->forwardd[0];
    return (current != NULL && current -> key == key) ? current->value : -1;
}

void deleteNode(SkipList *skiplist, int key){
    Node *update[MAX_LEVEL + 1];
    Node *current = skiplist->header;

    for (int i = skiplist->level; i>=0;i--){
        while (current->forward[i] != NULL && current->forward[i]->key < key){
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
