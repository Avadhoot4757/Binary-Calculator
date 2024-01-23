#include "infix_to_postfix/infix_to_postfix.h"
#include "infix_to_postfix/stackSLL.h"
#include "postfix_calculator/postfix_calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* string = "528452548184184 + 89848187861181628716 -894268979676971 +8461887118761 -782987961";
    char* ans = infixToPostfix(string);

    Number answer;
    initNumber(&answer);
    answer = calculatePostfix(ans);

    displayNumber(answer);

    return 0;
}
