#include <stdio.h>
#include <stdlib.h>
#include "stackSol.h"


void initStackSol(StackSol* stack) {
    stack->top = NULL;
}

int isEmptySol(StackSol stack) {
    return stack.top == NULL;
}

void pushSol(StackSol* stack, Number num) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory allocation for stack node failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = num;
    newNode->next = stack->top;

    stack->top = newNode;
}

Number popSol(StackSol* stack) {
    if (isEmptySol(*stack)) {
        printf("Stack empty\n");
        exit(EXIT_FAILURE);
    }

    StackNode* temp = stack->top;
    Number data = temp->data;

    stack->top = temp->next;

    free(temp);

    return data;
}

Number peekSol(StackSol stack) {
    if (isEmptySol(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return stack.top->data;
}

void displaySol(StackSol stack) {
    if (isEmptySol(stack)) {
        printf("Stack is empty\n");
        return;
    }

    StackNode* current = stack.top;
    printf("Stack: ");
    while (current) {
        printf("%p ", (void*)&current->data);
        current = current->next;
    }
    printf("\n");
}