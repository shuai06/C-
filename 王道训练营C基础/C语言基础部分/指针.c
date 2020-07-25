#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // 一级指针
    // 指针的本质： 存地址，间接访问
    // 指针使用场景：
    int i = 3;  // 直接访问
    int *p = &i;  // 初始化只能是取地址。

    printf("i=%d\n", i);
    printf("*p=%d\n",*p);   // * （取值）  间接访问

    // & 取地址操作符/引用
    // * 取值操作符/解引用

    // *&a  :





	return 0;

}




