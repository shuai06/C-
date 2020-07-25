#include "func.h"



int main()
{
    Stack s;    

    // 入栈
    push_stack(&s, 10);
    printf("the top of the stack val is = %d\n", top_stack(&s));
    // 出栈
    pop_stack(&s);
    printf("the top of the stack val is = %d\n", top_stack(&s));

    printf("stack is empty? =%c \n", empty_stack(&s)?'Y':'N');

    return 0;
}
















