#include "func.h"



int main()
{
    // 一个枚举
    enum weekday{sun=1, mon, tue, wed,thu=6, fri, sat};   // 定义了一个【类型】， 里面是【枚举常量】，默认会自动递增(从赋值的地方往后)

    enum weekday workday;   // 定义了 【枚举变量】
    workday = mon;       // 赋值给他枚举常量

    printf("sun=%d\n", workday);  // mon  




    



    return 0;
}





