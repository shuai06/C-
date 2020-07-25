#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 脏数据
// 申请的空间不释放：内存泄露
// 堆空间：一旦申请，一直占用，除非free
int main()
{ 

    int i;
    char *p;
    scanf("%d", &i);
    p = (char *)malloc(i);
    strcpy(p, "hello");   // p指向堆空间
    // p = "hellp";
    puts(p);
    free(p);  // 释放
    printf("free p ~~~~~~~~~~~");

	return 0;
}




