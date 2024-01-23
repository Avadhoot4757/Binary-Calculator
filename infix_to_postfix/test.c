#include "stackSLL.h"
#include "infix_to_postfix.h"
#include <stdio.h>

int main(){
    Stack s;
    init(&s);
    display(s);

    printf("isEmpty: %d\n", isEmpty(s));

    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'c');
    push(&s, 'd');

    printf("isEmpty: %d\n", isEmpty(s));

    display(s);

    char popped = pop(&s);
    printf("Popped Char: %c\n", popped);

    display(s);

    printf("peek: %c\n", peek(s));

}
