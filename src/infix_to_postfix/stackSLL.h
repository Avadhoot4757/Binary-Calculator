#ifndef STACK_SLL_H
#define STACK_SLL_H

typedef struct SllNode{
    char data;
    struct SllNode* next;
}SllNode;

typedef struct Stack{
    SllNode* top;
}Stack;

void initStack(Stack* s);
int isEmpty(Stack s);
void push(Stack* s, char data);
char pop(Stack* s);
char peek(Stack s);
void display(Stack s);

#endif  // STACK_SLL_H