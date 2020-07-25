#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{ 

    char *p = "hello";    // 是把字符串常量的首地址赋值给p
    char c[10]="hello";   // 等价与strcpy(c,"hello")

    c[0] = 'H';   // 改变了
    p[0] = 'H';    // 不可写

    printf("p=%s \n", p);
    printf("c=%s \n", c);

	return 0;
}




