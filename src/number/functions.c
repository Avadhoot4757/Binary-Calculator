#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

Number add(Number n1, Number n2) {
    Number answer;
    initNumber(&answer);

    int carry = 0;
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
            if(*t1 != NULL){
                (*t1)->data--;
            }   
        }
    }

    // if((*t1) != NULL){
    //     printf("yeah!!\n");
    // }
    while ((*t1) != NULL) {
        printf("%d\n", (*t1)->data);
        // displayNumber(*answer);
        insertAtBeginning(answer, (*t1)->data);
        *t1 = (*t1)->prev;
    }
    // displayNumber(*answer);
}

Number subtract(Number n1, Number n2) {
    displayNumber(n1);
    displayNumber(n2);
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
    if(d1 == NULL){
        printf("yeah\n");
    }

    // printf("%d %d\n", n1.head->data, n1.tail->data);
    // printf("%d %d\n", n2.head->data, n2.tail->data);
    subtractIntegers(&answer, &t1, &t2, d1);

    // printf("here\n");
    // displayNumber(answer);

    DllNode* temp = answer.head;
    while(temp != answer.tail && temp != NULL && temp != answer.decimal){
        if(answer.head->data == 0){
            removeFromBeginning(&answer);
            temp = answer.head;
        }else{
            temp = temp->next;
        }      
    }
    if(answer.head == answer.decimal){
        insertAtBeginning(&answer, 0);
    }
    // printf("there\n");
    // displayNumber(answer);

    return answer;
}

Number singleMultiply(Number n, int num, int stuffingZero){
    Number ans;
    initNumber(&ans);
    int product, carry = 0;

    DllNode* t = n.tail;
    while(t != NULL){
        int mul = (t->data * num) + carry;
        product = mul%10;
        carry = mul/10;
        insertAtBeginning(&ans, product);
        t = t->prev;
    }

    while(carry != 0){
        int temp = carry%10;
        insertAtBeginning(&ans, temp);
        carry = carry/10;
    }
    while(stuffingZero != 0){
        append(&ans, 0);
        stuffingZero--;
    }

    return ans;
}

Number multiply(Number n1, Number n2){
    Number answer;

    DllNode* t1 = n1.tail;
    DllNode* t2 = n2.tail;
    DllNode* d1 = n1.decimal;
    DllNode* d2 = n2.decimal;

    int l1 = findLength(d1, t1);
    int l2 = findLength(d2, t2);

    int num = t2->data;
    int stuffingZero = 0;
    answer = singleMultiply(n1, num, stuffingZero);
    stuffingZero++;
    t2 = t2->prev;

    while(t2 != NULL){
        num = (t2->data);
        Number temp = singleMultiply(n1, num, stuffingZero);
        stuffingZero++;
        answer = add(answer, temp);
        freeNumber(&temp);
        t2 = t2->prev;
    }

    int decNo = l1 + l2;
    if(decNo == 0){
        return answer;
    }
    else{
        DllNode* t = answer.tail;
        while(decNo != 1){
            t = t->prev;
            decNo--;
        }
        answer.decimal = t;

        return answer;
    }
    
}

void dividePrecise(Number n1, Number n2, Number* quotient, Number dividend, int precision){
    n1.decimal = NULL;
    // displayNumber(n1);
    paddingZeroes(&n1, precision*2);
    // printf("precise divide: \n");
    // displayNumber(dividend);
    // displayNumber(n2);
    int count = precision;
    while(precision != 0){
        // printf("bool->%d\n", isFirstGreater(dividend, n2));
        while(isFirstGreater(dividend, n2) == 0){
            append(&dividend, removeFromBeginning(&n1));
            // displayNumber(dividend);
        }
        int multiple = 1;
        Number diviser = n2;
        while(isFirstGreater(dividend, diviser) != 0){
            multiple++;
            diviser = add(diviser, n2);
            // displayNumber(diviser);
        }
        multiple--;
        // printf("%d\n", multiple);
        diviser = subtract(diviser, n2);
        // displayNumber(diviser);
        append(quotient, multiple);
        if(count == precision){
            quotient->decimal = quotient->tail;
        }
        // printf("%d\n", multiple);
        // displayNumber(dividend);
        // displayNumber(diviser);
        dividend = subtract(dividend, diviser);
        // displayNumber(dividend);
        // printf("%d\n", multiple);
        precision--;
    }
}

Number divide(Number n1, Number n2){
    DllNode* d1 = n1.decimal;
    DllNode* d2 = n2.decimal;
    DllNode* t1 = n1.tail;
    DllNode* t2 = n2.tail;
    Number dividend;
    initNumber(&dividend);
    Number quotient;
    initNumber(&quotient);
    Number remainder;
    initNumber(&remainder);

    if(isFirstGreater(n1, n2) == -1){
        append(&quotient, 1);
        return quotient;
    }

    int l1 = findLength(d1, t1);
    int l2 = findLength(d2, t2);
    int precision;
    if(l1>l2){
        precision = l1;
    }
    else if(l1 == 0 && l2 == 0){
        precision = 5;
    }
    else{
        precision = l2;
    }

    while(d1 != NULL && d2 != NULL){
        d1 = d1->next;
        d2 = d2->next;
    }
    while(d2 != NULL){
        d2 = d2->next;
        append(&n1, 0);
    }

    if(isFirstGreater(n1, n2) == 0){
        append(&quotient, 0);
        dividePrecise(n1, n2, &quotient, dividend, precision);
    }
    else{
        while(n1.head != n1.decimal){
            while(isFirstGreater(dividend, n2) == 0){
                append(&dividend, removeFromBeginning(&n1));
                // displayNumber(dividend);
            }
            int multiple = 1;
            Number diviser = n2;
            while(isFirstGreater(dividend, diviser) != 0){
                multiple++;
                diviser = add(diviser, n2);
                // displayNumber(diviser);
            }
            // printf("%d\n", multiple);
            multiple--;
            // displayNumber(diviser);
            diviser = subtract(diviser, n2);
            append(&quotient, multiple);
            // displayNumber(diviser);
            dividend = subtract(dividend, diviser);
            // displayNumber(dividend);
        }
        // printf("divide: ");
        // displayNumber(quotient);
        DllNode* temp = dividend.head;
        while(temp != NULL){
            if(temp->data != 0){
                dividePrecise(n1, n2, &quotient, dividend, precision);
                break;
            }
            temp = temp->next;
        }
        
    }

    return quotient;
}
