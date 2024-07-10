#include "infix_to_postfix/infix_to_postfix.h"
#include "infix_to_postfix/stackSLL.h"
#include "postfix_calculator/postfix_calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* string = "82468442.4984498 * 498428999.8498846846";
    char* ans = infixToPostfix(string);

    Number answer;
    initNumber(&answer);
    answer = calculatePostfix(ans);
    displayNumber(answer);

    return 0;
}
