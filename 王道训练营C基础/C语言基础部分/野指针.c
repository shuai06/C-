#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 什么是野指针：free以后的指针未被赋值为NULL  (指向了一个未知的空间)
int main()
{ 

    int *p, *p1, *p2, *p3;
    p = (int *)malloc(4);
    *p = 1;
    free(p);

    p = NULL;   // 赋值null以后，后面用的话会崩溃，能迅速找到问题

    p1 = (int *)malloc(4);  
    *p1 = 2;  // 没有free

    p2 = (int *)malloc(4);
    *p2 = 2;
    free(p1);

    p3 = (int *)malloc(4);
    *p3 = 3;
    *p1 = 20; // 以为p1free了，这里又赋值
    printf("p3 = %d", *p3);   //  20了    malloc有缓存机制


	return 0;
}




