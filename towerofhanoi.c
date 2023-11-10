//main

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main() {
    int numDisks = 3; //  number of disks
    struct Stack* source = createStack(numDisks);
    struct Stack* auxiliary = createStack(numDisks);
    struct Stack* destination = createStack(numDisks);
    for (int i = numDisks; i >= 1; i--) {
        push(source, i);
    }
    char sourcePole = 'A';
    char auxiliaryPole = 'B';
    char destinationPole = 'C';
    towerOfHanoi(numDisks, source, auxiliary, destination, sourcePole, auxiliaryPole, destinationPole);
    free(source->array);
    free(auxiliary->array);
    free(destination->array);
    free(source);
    free(auxiliary);
    free(destination);
    return 0;
}

//stack.h file
#ifndef STACK_H
#define STACK_H
// Structure to represent a stack
struct Stack {
    int capacity;
    int top;
    int* array;
};
// Function declarations
struct Stack* createStack(int capacity);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
void moveDisk(char fromPole, char toPole, int disk);
void towerOfHanoi(int n, struct Stack* source, struct Stack* auxiliary, struct Stack* destination, char sourcePole, char auxiliaryPole, char destinationPole);

#endif


//stack.c file
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
// Function to create a stack with a given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top = stack->top + 1;
    stack->array[stack->top] = item;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Assuming -1 represents an error or sentinel value
    }
    return stack->array[stack->top--];
}
// Function to move a disk from one pole to another
void moveDisk(char fromPole, char toPole, int disk) {
    printf("Move disk %d from pole %c to pole %c\n", disk, fromPole, toPole);
}
//  Tower of Hanoi
void towerOfHanoi(int n, struct Stack* source, struct Stack* auxiliary, struct Stack* destination, char sourcePole, char auxiliaryPole, char destinationPole) {
    if (n == 1) {
        int disk = pop(source);
        push(destination, disk);
        moveDisk(sourcePole, destinationPole, disk);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary, sourcePole, destinationPole, auxiliaryPole);
    int disk = pop(source);
    push(destination, disk);
    moveDisk(sourcePole, destinationPole, disk);
    towerOfHanoi(n - 1, auxiliary, source, destination, auxiliaryPole, sourcePole, destinationPole);
}