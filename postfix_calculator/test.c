// #include "postfix_calculator.h"
// #include <stdio.h>

// int main(){
//     char* postfix = "45 54 + 3745 +";
//     Number ans = calculatePostfix(postfix);
//     displayNumber(ans);
// }


#include "postfix_calculator.h"
#include <stdio.h>

int main() {
    // char postfixExpression[100];  // Adjust the size as needed
    // printf("Enter a postfix expression: ");
    // scanf("%s", postfixExpression);

    char* postfixExpression = "45 54 + 3745 +";

    Number result = calculatePostfix(postfixExpression);

    // Display the result
    printf("Result: ");
    displayNumber(result);

    // Free any dynamically allocated memory
    freeNumber(&result);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include "stackSol.h"

// int main() {
//     // Initialize a stack
//     StackSol stack;
//     initStackSol(&stack);

//     // Push some Numbers onto the stack
//     Number num1, num2, num3;
//     initNumber(&num1);
//     initNumber(&num2);
//     initNumber(&num3);

//     append(&num1, 1);
//     append(&num1, 2);
//     append(&num1, 3);

//     append(&num2, 4);
//     append(&num2, 5);
//     append(&num2, 6);
//     insertAtBeginning(&num2, 7);

//     append(&num3, 7);
//     append(&num3, 8);
//     append(&num3, 9);

//     pushSol(&stack, num1);
//     pushSol(&stack, num2);
//     pushSol(&stack, num3);

//     // Display the stack
//     printf("Initial Stack:\n");
//     displaySol(stack);

//     // Peek at the top of the stack
//     printf("Peek at the top of the stack:\n");
//     Number topNum = peekSol(stack);
//     displayNumber(topNum);

//     // Pop elements off the stack
//     printf("Popping elements off the stack:\n");
//     Number poppedNum1 = popSol(&stack);
//     Number poppedNum2 = popSol(&stack);
//     Number poppedNum3 = popSol(&stack);

//     // Display popped Numbers
//     printf("Popped Numbers:\n");
//     displayNumber(poppedNum1);
//     displayNumber(poppedNum2);
//     displayNumber(poppedNum3);

//     // Display the updated stack
//     printf("Updated Stack:\n");
//     displaySol(stack);

//     return 0;
// }
