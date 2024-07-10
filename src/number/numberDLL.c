#include <stdio.h>
#include <stdlib.h>
#include "numberDLL.h"
#include <limits.h>

void initDllNode(DllNode* m, int data){
    m->data = data;
    m->next = NULL;
    m->prev = NULL;
}

void initNumber(Number* n){
    n->length = 0;
    n->head = NULL;
    n->decimal = NULL;
    n->tail = NULL;

    return;
}

int findLength(DllNode* n1, DllNode* n2){
    if(n1 == NULL || n2 == NULL){
        return 0;
    }
    int count = 1;
    while(n1 != n2){
        count++;
        n1 = n1->next;
    }

    return count;
}

void append(Number* n, int data){
    DllNode* newnode = (DllNode* )malloc(sizeof(DllNode));
    initDllNode(newnode, data);

    if(n->head == NULL){
        n->length++;
        n->head = newnode;
        n->tail = newnode;
        return;
    }

    n->tail->next = newnode;
    newnode->prev = n->tail;
    n->tail = n->tail->next;
    n->length++;

    return;
}

void insertAtBeginning(Number* n, int data){
    DllNode* newnode = (DllNode* )malloc(sizeof(DllNode));
    initDllNode(newnode, data);

    if(n->head == NULL){
        n->length++;
        n->head = newnode;
        n->tail = newnode;
        return;
    }

    n->head->prev = newnode;
    newnode->next = n->head;
    n->head = n->head->prev;
    n->length++;

    return;
}

int removeFromBeginning(Number* n){
    if(n->head == NULL){
        return -1;
    }

    DllNode* temp = n->head;
    n->head = n->head->next;
    n->length--;
    int data = temp->data;
    free(temp);
    return data;
}


void freeNumber(Number* n) {
    DllNode* current = n->head;
    while (current != NULL) {
        DllNode* temp = current;
        current = current->next;
        free(temp);
    }
}

//returns 1 if first number is greater, 0 if 2nd is greater, -1 if both are equal
int isFirstGreater(Number n1, Number n2){
    int l1 = findLength(n1.head, n1.decimal);
    int l2 = findLength(n2.head, n2.decimal);
    if(n1.decimal == NULL){
        l1 = findLength(n1.head, n1.tail);
    }
    if(n2.decimal == NULL){
        l2 = findLength(n2.head, n2.tail);
    }

    if(l1 > l2){
        return 1;
    }
    else if(l2 > l1){
        return 0;
    }
    else{
        DllNode* h1 = n1.head;
        DllNode* h2 = n2.head;
        
        while(h1 != NULL && h2 != NULL && h1->data == h2->data){
            h1 = h1->next;
            h2 = h2->next;
        }

        if(h1 == NULL && h2 == NULL){
            return -1;
        }
        else if(h1 == NULL){
            while(h2 != NULL){
                if(h2->data > 0){
                    return 0;
                }
                h2 = h2->next;
            }
            return -1;
        }
        else if(h2 == NULL){
            while(h1 != NULL){
                if(h1->data > 0){
                    return 1;
                }
                h1 = h1->next;
            }
            return -1;
        }

        if(h1->data > h2->data){
            return 1;
        }
        else if(h2->data > h1->data){
            return 0;
        }
        else{
            return -1;
        }
    }
}

void displayNumber(Number n){
    DllNode* temp = n.head;
    while(temp != NULL){
        if(temp == n.decimal){
            printf(".");
        }
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
