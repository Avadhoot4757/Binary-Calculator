#include <stdio.h>
#include <stdlib.h>
#include "numberDLL.h"

void initDllNode(DllNode* m, int data){
    m->data = data;
    m->next = NULL;
    m->prev = NULL;
}

void initNumber(Number* n){
    n->length = 0;
    n->head = NULL;
    n->tail = NULL;

    return;
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

void removeFromBeginning(Number* n){
    if(n->head == NULL){
        return;
    }

    DllNode* temp = n->head;
    n->head = n->head->next;
    free(temp);
}


void freeNumber(Number* n) {
    DllNode* current = n->head;
    while (current != NULL) {
        DllNode* temp = current;
        current = current->next;
        free(temp);
    }
}


Number add(Number n1, Number n2) {
    Number answer;
    initNumber(&answer);

    int sum, carry = 0;
    DllNode* p1 = n1.tail;
    DllNode* p2 = n2.tail;

    while (p1 != NULL && p2 != NULL) {
        int temp = p1->data + p2->data + carry;
        sum = temp % 10;
        carry = temp / 10;

        insertAtBeginning(&answer, sum);
        p1 = p1->prev;
        p2 = p2->prev;
    }

    while (p1 != NULL) {
        int temp = p1->data + carry;
        sum = temp % 10;
        carry = temp / 10;
        insertAtBeginning(&answer, sum);
        p1 = p1->prev;
    }

    while (p2 != NULL) {
        int temp = p2->data + carry;
        sum = temp % 10;
        carry = temp / 10;
        insertAtBeginning(&answer, sum);
        p2 = p2->prev;
    }

    // If there is a final carry, add it as a new digit
    if (carry > 0) {
        insertAtBeginning(&answer, carry);
    }

    return answer;
}


//assuming that n1 is always greater than n2
Number subtract(Number n1, Number n2){
    Number answer;
    initNumber(&answer);

    int diff, borrow = 0;
    DllNode* p1 = n1.tail;
    DllNode* p2 = n2.tail;

    while(p1 != NULL && p2 != NULL){
        if(p1->data >= p2->data){
            diff = p1->data - p2->data;
            insertAtBeginning(&answer, diff);
            p1 = p1->prev;
            p2 = p2->prev;
        }
        else if(p1->data < p2->data){
            diff = p1->data + 10 - p2->data;
            insertAtBeginning(&answer, diff);
            p1 = p1->prev;
            p2 = p2->prev;
            p1->data--;
        }
    }
    while(p1 != NULL){
        insertAtBeginning(&answer, p1->data);
        p1 = p1->prev;
    }

    if(answer.head->data == 0){
        removeFromBeginning(&answer);
    }
    return answer;
}

void displayNumber(Number n){
    DllNode* temp = n.head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
