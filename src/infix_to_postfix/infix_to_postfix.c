#include "stackSLL.h"
#include "infix_to_postfix.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;  //'(' has the lowest precedence
}

char* infixToPostfix(char* infix) {
    // Allocate memory for the postfix expression
    int infixLength = strlen(infix);
    char* postfix = (char*)malloc((infixLength + 1) * sizeof(char));
    if (!postfix) {
        printf("Memory allocation for postfix failed\n");
    }

    // Initialize stack
    Stack s;
    initStack(&s);

    int postfixIndex = 0;

    // Process each character in the infix expression
    for (int i = 0; i < infixLength; ++i) {
        char currentChar = infix[i];
        if(currentChar == ' '){
            continue;
        }
        else if (isalnum(currentChar)) {
            while (isalnum(infix[i]) || infix[i]=='.') {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';  // Add space as a separator
            --i;
        } else if (currentChar == '(') {
            push(&s, currentChar);
        } else if (currentChar == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[postfixIndex++] = pop(&s);
                postfix[postfixIndex++] = ' ';
            }
            if(!isEmpty(s)){
                pop(&s);  // Pop the open parenthesis
            }
        } else if (isOperator(currentChar)) {
            while (!isEmpty(s) && getPrecedence(peek(s)) >= getPrecedence(currentChar)) {
                postfix[postfixIndex++] = pop(&s);
                postfix[postfixIndex++] = ' ';
            }
            push(&s, currentChar);
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (!isEmpty(s)) {
        postfix[postfixIndex++] = pop(&s);
        postfix[postfixIndex++] = ' ';
    }

    // Null-terminate the postfix expression
    postfix[postfixIndex] = '\0';

    return postfix;
}
 
