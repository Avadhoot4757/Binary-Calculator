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

void removeFromBeginning(Number* n){
    if(n->head == NULL){
        return;
    }

    DllNode* temp = n->head;
    n->head = n->head->next;
    n->length--;
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


// Number add(Number n1, Number n2) {
//     Number answer;
//     initNumber(&answer);

//     int sum, carry = 0;
//     DllNode* t1 = n1.tail;
//     DllNode* t2 = n2.tail;
//     DllNode* d1 = n1.decimal;
//     DllNode* d2 = n2.decimal;
//     DllNode* h1 = n1.head;
//     DllNode* h2 = n2.head;
    
//     if(d1 == NULL && d2 == NULL){
//         while (t1 != NULL && t2 != NULL) {
//             int temp = t1->data + t2->data + carry;
//             sum = temp % 10;
//             carry = temp / 10;

//             insertAtBeginning(&answer, sum);
//             t1 = t1->prev;
//             t2 = t2->prev;
//         }

//         while (t1 != NULL) {
//             int temp = t1->data + carry;
//             sum = temp % 10;
//             carry = temp / 10;
//             insertAtBeginning(&answer, sum);
//             t1 = t1->prev;
//         }

//         while (t2 != NULL) {
//             int temp = t2->data + carry;
//             sum = temp % 10;
//             carry = temp / 10;
//             insertAtBeginning(&answer, sum);
//             t2 = t2->prev;
//         }

//         // If there is a final carry, add it as a new digit
//         if (carry > 0) {
//             insertAtBeginning(&answer, carry);
//         }

//         return answer;
//     }
//     else if(d1 == NULL && d2 != NULL){
//         while(t2 != d2->prev){
//             int temp = t2->data + carry;
//             sum = temp % 10;
//             carry = temp / 10;

//             insertAtBeginning(&answer, sum);
//             t2 = t2->prev;
//         }
//         answer.decimal = answer.head;

//         while (t1 != NULL && t2 != NULL) {
//             int temp = t1->data + t2->data + carry;
//             sum = temp % 10;
//             carry = temp / 10;

//             insertAtBeginning(&answer, sum);
//             t1 = t1->prev;
//             t2 = t2->prev;
//         }

//         while (t1 != NULL) {
//             int temp = t1->data + carry;
//             sum = temp % 10;
//             carry = temp / 10;
//             insertAtBeginning(&answer, sum);
//             t1 = t1->prev;
//         }

//         while (t2 != NULL) {
//             int temp = t2->data + carry;
//             sum = temp % 10;
//             carry = temp / 10;
//             insertAtBeginning(&answer, sum);
//             t2 = t2->prev;
//         }

//         // If there is a final carry, add it as a new digit
//         if (carry > 0) {
//             insertAtBeginning(&answer, carry);
//         }

//         return answer;
//     }
//     else if(d1 != NULL && d2 == NULL){
//         return add(n2, n1);
//     }
//     else{
//         int l1 = findLength(n1.decimal, n1.tail);
//         int l2 = findLength(n2.decimal, n2.tail);
//         if(l1 == l2){
//             while (t1 != NULL && t2 != NULL) {
//                 int temp = t1->data + t2->data + carry;
//                 sum = temp % 10;
//                 carry = temp / 10;

//                 insertAtBeginning(&answer, sum);
//                 if(t1 == d1){
//                     answer.decimal = answer.head;
//                 }
//                 t1 = t1->prev;
//                 t2 = t2->prev;
//             }

//             while (t1 != NULL) {
//                 int temp = t1->data + carry;
//                 sum = temp % 10;
//                 carry = temp / 10;
//                 insertAtBeginning(&answer, sum);
//                 t1 = t1->prev;
//             }

//             while (t2 != NULL) {
//                 int temp = t2->data + carry;
//                 sum = temp % 10;
//                 carry = temp / 10;
//                 insertAtBeginning(&answer, sum);
//                 t2 = t2->prev;
//             }

//             // If there is a final carry, add it as a new digit
//             if (carry > 0) {
//                 insertAtBeginning(&answer, carry);
//             }

//             return answer;
//         }
//         else if(l1>l2){
//             while(l1>l2){
//                 int temp = t1->data + carry;
//                 sum = temp % 10;
//                 carry = temp / 10;
//                 insertAtBeginning(&answer, sum);
//                 t1 = t1->prev;
//                 l1--;
//             }
//             while (t1 != NULL && t2 != NULL) {
//                 int temp = t1->data + t2->data + carry;
//                 sum = temp % 10;
//                 carry = temp / 10;

//                 insertAtBeginning(&answer, sum);
//                 if(t1 == d1){
//                     answer.decimal = answer.head;
//                 }
//                 t1 = t1->prev;
//                 t2 = t2->prev;
//             }

//             while (t1 != NULL) {
//                 int temp = t1->data + carry;
//                 sum = temp % 10;
//                 carry = temp / 10;
//                 insertAtBeginning(&answer, sum);
//                 t1 = t1->prev;
//             }

//             while (t2 != NULL) {
//                 int temp = t2->data + carry;
//                 sum = temp % 10;
//                 carry = temp / 10;
//                 insertAtBeginning(&answer, sum);
//                 t2 = t2->prev;
//             }

//             // If there is a final carry, add it as a new digit
//             if (carry > 0) {
//                 insertAtBeginning(&answer, carry);
//             }

//             return answer;
//         }
//         else{
//             return add(n2, n1);
//         }
//     }
    
// }

Number add(Number n1, Number n2) {
    Number answer;
    initNumber(&answer);

    int sum, carry = 0;
    DllNode *t1 = n1.tail;
    DllNode *t2 = n2.tail;
    DllNode *d1 = n1.decimal;
    DllNode *d2 = n2.decimal;

    if (d1 == NULL && d2 == NULL) {
        addIntegers(&answer, &t1, &t2, &carry, NULL);
    } else if (d1 == NULL && d2 != NULL) {
        addTrailingDigits(&answer, &t2, &carry, findLength(d2, n2.tail));
        answer.decimal = answer.head;
        addIntegers(&answer, &t1, &t2, &carry, NULL);
    } else if (d1 != NULL && d2 == NULL) {
        return add(n2, n1);
    } else {
        int l1 = findLength(n1.decimal, n1.tail);
        int l2 = findLength(n2.decimal, n2.tail);

        if (l1 == l2) {
            addIntegers(&answer, &t1, &t2, &carry, d1);
        } else if (l1 > l2) {
            addTrailingDigits(&answer, &t1, &carry, l1 - l2);
            addIntegers(&answer, &t1, &t2, &carry, d1);
        } else {
            return add(n2, n1);  // Swap for easier handling
        }
    }

    // Add final carry if exists
    if (carry > 0) {
        insertAtBeginning(&answer, carry);
    }

    return answer;
}

// Function to add integer parts of numbers
void addIntegers(Number *answer, DllNode **t1, DllNode **t2, int *carry, DllNode *d) {
    int sum;
    while (*t1 != NULL && *t2 != NULL) {
        int temp = (*t1)->data + (*t2)->data + *carry;
        sum = temp % 10;
        *carry = temp / 10;
        insertAtBeginning(answer, sum);
        if(*t1 == d){
            answer->decimal = answer->head;
        }
        *t1 = (*t1)->prev;
        *t2 = (*t2)->prev;
    }

    // Use addTrailingDigits to handle remaining digits
    addTrailingDigits(answer, t1, carry, INT_MAX);  // Add all remaining digits from t1
    addTrailingDigits(answer, t2, carry, INT_MAX);  // Add all remaining digits from t2
}


// Function to add trailing digits after the decimal point
void addDecimalTrailingDigits(Number *answer, DllNode **t, int *carry) {
    int sum;
    while (*t != NULL) {
        int temp = (*t)->data + *carry;
        sum = temp % 10;
        *carry = temp / 10;
        insertAtBeginning(answer, sum);
        *t = (*t)->prev;
    }
}

//Function to add 
void addTrailingDigits(Number *answer, DllNode **t, int *carry, int count) {
    int sum;
    while (*t != NULL && count > 0) {
        int temp = (*t)->data + *carry;
        sum = temp % 10;
        *carry = temp / 10;
        insertAtBeginning(answer, sum);
        *t = (*t)->prev;
        count--;
    }
}

void paddingZeroes(Number* n, int count){
    while(count != 0){
        append(n, 0);
        count--;
    }
}

// void subtractIntegers(Number* answer, DllNode** t1, DllNode** t2, DllNode* d){
//     int diff, borrow = 0;
//     while(*t1 != NULL && *t2 != NULL){
//         if((*t1)->data >= (*t2)->data){
//             diff = (*t1)->data - (*t2)->data;
//             insertAtBeginning(answer, diff);
//             if(*t1 == d){
//                 answer->decimal = answer->head;
//             }
//             *t1 = (*t1)->prev;
//             *t2 = (*t2)->prev;
//         }
//         else if((*t1)->data < (*t2)->data){
//             diff = (*t1)->data + 10 - (*t2)->data;
//             insertAtBeginning(answer, diff);
//             if(*t1 == d){
//                 answer->decimal = answer->head;
//             }
//             *t1 = (*t1)->prev;
//             *t2 = (*t2)->prev;
//             (*t1)->data--;
//         }
//     }
//     while((*t1) != NULL){
//         insertAtBeginning(answer, (*t1)->data);
//         *t1 = (*t1)->prev;
//     }

//     if(answer->head->data == 0){
//         removeFromBeginning(answer);
//     }
// }

// //assuming that n1 is always greater than n2
// Number subtract(Number n1, Number n2){
//     Number answer;
//     initNumber(&answer);

//     int diff, borrow = 0;
//     DllNode* t1 = n1.tail;
//     DllNode* t2 = n2.tail;
//     DllNode* d1 = n1.decimal;
//     DllNode* d2 = n2.decimal;

//     if(d1 == NULL && d2 == NULL){
//         subtractIntegers(&answer, &t1, &t2, NULL);
//     }
//     else{
//         int l1 = findLength(n1.decimal, n1.tail);
//         int l2 = findLength(n2.decimal, n2.tail);
        
//         if(l1 == l2){
//             subtractIntegers(&answer, &t1, &t2, d1);
//         }
//         else if(l1 > l2){
//             paddingZeroes(&n2, l1-l2);
//             subtractIntegers(&answer, &t1, &t2, d1);
//         }
//         else if(l2 > l1){
//             paddingZeroes(&n1, l2-l1);
//             subtractIntegers(&answer, &t1, &t2, d1);
//         }
//     }
    
//     return answer;
// }

void subtractIntegers(Number* answer, DllNode** t1, DllNode** t2, DllNode* d) {
    int diff;
    while (*t1 != NULL && *t2 != NULL) {
        if ((*t1)->data >= (*t2)->data) {
            diff = (*t1)->data - (*t2)->data;
            insertAtBeginning(answer, diff);
            if(*t1 == d){
                answer->decimal = answer->head;
            }
            *t1 = (*t1)->prev;
            *t2 = (*t2)->prev;
        } else {
            diff = (*t1)->data + 10 - (*t2)->data;
            insertAtBeginning(answer, diff);
            if(*t1 == d){
                answer->decimal = answer->head;
            }
            *t1 = (*t1)->prev;
            *t2 = (*t2)->prev;
            (*t1)->data--;
        }
    }

    while ((*t1) != NULL) {
        insertAtBeginning(answer, (*t1)->data);
        *t1 = (*t1)->prev;
    }
}

Number subtract(Number n1, Number n2) {
    Number answer;
    initNumber(&answer);

    int l1 = findLength(n1.decimal, n1.tail);
    int l2 = findLength(n2.decimal, n2.tail);

    if (l1 > l2) {
        paddingZeroes(&n2, l1 - l2);
    } else if (l2 > l1) {
        paddingZeroes(&n1, l2 - l1);
    }

    DllNode* t1 = n1.tail;
    DllNode* t2 = n2.tail;
    DllNode* d1 = n1.decimal;

    subtractIntegers(&answer, &t1, &t2, d1);


    return answer;
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
