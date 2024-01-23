#include "infix_to_postfix/infix_to_postfix.h"
#include "infix_to_postfix/stackSLL.h"
#include "postfix_calculator/postfix_calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* string = "922337203685477580845 + 9223372036854770058086425\0";
    char* ans = infixToPostfix(string);

    Number answer;
    initNumber(&answer);
    answer = calculatePostfix(ans);

    displayNumber(answer);

    return 0;
}
