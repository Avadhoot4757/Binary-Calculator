// 45 54 + 3745 +
#include <stdio.h>
// #include <stdlib.h>
#include <ctype.h>
#include "numberDLL.h"

int main(){
    Number n;
    Number m;

    initNumber(&n);
    initNumber(&m);

    append(&n, 0);
    // insertAtBeginning(&n, 5);
    append(&n, 1);
    // append(&n, 2);
    // n.decimal = n.tail;
    // append(&n, 5);

    append(&m, 5);
    // insertAtBeginning(&m, 5);
    // append(&m, 8);
    // append(&m, 2);
    // m.decimal = m.tail;
    // append(&m, 5);
    // append(&m, 0);

    displayNumber(m);
    displayNumber(n);

    printf("%d\n", isFirstGreater(m, n));
    // Number k = add(n, m);

    // displayNumber(k);
    // char* postfix = "45 54 + 3745 + \0";
    // int i = 0;

    // while(postfix[i] != '\0'){
    //     // if(isdigit(postfix[i])){
    //     //     printf("%c ", postfix[i]);
    //     // } 
    //     // i++;

    //     if(postfix[i] == ' ' || postfix[i] == '+'){
    //         i++;
    //     }
    //     else if(isdigit(postfix[i])){
    //         Number n;
    //         initNumber(&n);
    //         while(postfix[i] != ' ' && postfix[i] != '\0'){
    //             int data = postfix[i] - '0';
    //             append(&n, data);
    //             i++;
    //         }
    //         displayNumber(n);
    //         freeNumber(&n);
    //         i++;
    //     }
    // }

}