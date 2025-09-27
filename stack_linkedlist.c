
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5
#define STACK_EMPTY INT_MIN


struct Node {
    int value;
    struct Node *nextNode;
};

struct Node* head = NULL;


bool push(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->nextNode = head;
    head = newNode;
    return true;
}

int pop() {
    if (head == NULL) return STACK_EMPTY;
    int value = head->value;
    struct Node *tmp = head;
    head = head->nextNode;
    free(tmp);
    return value;
}


int main() {
    push(2);
    push(17);
    push(6);
    push(6);
    push(6);
    push(6);
    int number;
    while((number = pop()) != STACK_EMPTY) {
        printf("%d\n", number);
    }
    return 1;
}