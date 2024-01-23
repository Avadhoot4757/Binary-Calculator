#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "postfix_calculator.h"

Number calculatePostfix(char* postfix) {
    StackSol s;
    initStackSol(&s);

    int i = 0;

    while(postfix[i] != '\0'){
        if(postfix[i] == ' '){
            i++;
        }
        else if(isdigit(postfix[i])){
            Number n;
            initNumber(&n);
            while(postfix[i] != ' ' && postfix[i] != '\0'){
                int data = postfix[i] - '0';
                append(&n, data);
                i++;
            }
            pushSol(&s, n);
            i++;
        }
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            Number n2 = popSol(&s);
            Number n1 = popSol(&s);
            char operator = postfix[i];
            Number newnumber;

            if(operator == '+'){
                newnumber = add(n1, n2);
            }
            // else if(operator == '-'){
            //     newnumber = subtract(n1, n2);
            // }
            // else if(operator == '*'){
            //     newnumber = multiply(n1, n2);
            // }
            // else if(operator == '/'){
            //     newnumber = divide(n1, n2);
            // }
            pushSol(&s, newnumber);
            i++;
        }
    }

    Number answer = popSol(&s);

    return answer;
}
