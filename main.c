#include "infix_to_postfix/infix_to_postfix.h"
#include "infix_to_postfix/stackSLL.h"
#include "postfix_calculator/postfix_calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char* string = "38126737.145272272 + 8978671817.87678471541 + 46818848668.718484166";
    char* ans = infixToPostfix(string);

    Number answer;
    initNumber(&answer);
    answer = calculatePostfix(ans);

    displayNumber(answer);

    return 0;
}
