#include <stdio.h>
#include "infix_to_postfix.h"
#include "stackSLL.h"

int main(){
    // char* string = "45 + 54 - 689 * 18 / 3745";
    char* string = "45 + 54 + 3745";
    char* ans = infixToPostfix(string);

    for(int i = 0; ans[i] != '\0'; i++){
        printf("%c", ans[i]);
    }

    printf("\n");

    return 0;
}