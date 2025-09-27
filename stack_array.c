
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#define STACK_SIZE 5
#define STACK_EMPTY INT_MIN

int mystack[STACK_SIZE];
int stack_level = 0;


bool push(int value) {
    if (stack_level == STACK_SIZE) return false;
    mystack[stack_level] = value;
    stack_level ++;
    return true;
}

int pop() {
    if (stack_level > 0) {
        stack_level--;
        return mystack[stack_level];
    }
    return STACK_EMPTY;
}


int main() {
    push(2);
    push(17);
    push(6);
    push(6);
    push(6);
    push(6);
    while(stack_level > 0) {
        int val = pop();
        printf("%d\n", val);
    }
    return 1;
}