#include "infix_to_postfix/infix_to_postfix.h"
#include "infix_to_postfix/stackSLL.h"
#include "postfix_calculator/postfix_calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* string = "7184781148754548.84844741814 + 418787146.484848481481 - 484816464884.848484681 + 4145848484844418484.846844684 - 7745147.565684684846";
    char* ans = infixToPostfix(string);

    Number answer;
    initNumber(&answer);
    answer = calculatePostfix(ans);

    displayNumber(answer);

    return 0;
}
