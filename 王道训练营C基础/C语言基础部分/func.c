# include "func.h"


// 函数的定义
int printstart(int i)
{   
    printf("***************  \n");
    return i+3;
}



void printmsg()
{

    printf("printmsg func ... ...");
    printstart(10);
    return;
}