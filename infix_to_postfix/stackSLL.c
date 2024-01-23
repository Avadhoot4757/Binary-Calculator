#include "stackSLL.h"
#include <stdlib.h>
#include <stdio.h>


void initStack(Stack* s){
    s->top = NULL;
    return;
}

int isEmpty(Stack s){
    if(s.top == NULL){
        return 1;
    }

    return 0;
}

void push(Stack* s, char data){
    SllNode* newnode = (SllNode* )malloc(sizeof(SllNode));

    if(!newnode){
        printf("failed to create new SllNode\n");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;

    if(isEmpty(*s)){
        s->top = newnode;
        return;
    }

    newnode->next = s->top;
    s->top = newnode;

    return;
}

char pop(Stack* s){
    if(isEmpty(*s)){
        return '\0';
    }

    SllNode* temp = s->top;
    char data = temp->data;
    s->top = temp->next;
    free(temp);

    return data;
}

char peek(Stack s){
    if(isEmpty(s)){
        return '\0';
    }

    return s.top->data;
}

void display(Stack s){
    if(isEmpty(s)){
        printf("Empty Stack\n");
        return;
    }

    SllNode* temp = s.top;
    printf("Stack: ");
    while(temp){
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\nStack Over \n\n");

    return;
}
