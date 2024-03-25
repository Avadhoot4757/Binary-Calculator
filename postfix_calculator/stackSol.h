#include "../number/functions.h"

typedef struct StackNode {
    Number data;
    struct StackNode* next;
} StackNode;

// Stack structure using linked list
typedef struct StackSol {
    StackNode* top;
} StackSol;

void initStackSol(StackSol* stack);
int isEmptySol(StackSol stack);
void pushSol(StackSol* stack, Number num);
Number popSol(StackSol* stack);
Number peekSol(StackSol stack);
void displaySol(StackSol stack);