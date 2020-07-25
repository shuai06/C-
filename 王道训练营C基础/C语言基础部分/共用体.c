#include "func.h"



// union 共用体name
// {
//     成员表列
// } 变量表列;

union data{
    int i;
    char c;
    float f;
}u1;
// 共用体的起始地址和每个成员的起始地址是相同的
// 一个时间内只能存取一个成员
    

// struct student{
//     int num;
//     char name[20];
//     float score;
// };

int main()
{
    union data d; // 现在最大的就是4
    d.i = 4;
    d.c='A';
    d.f = 99.9;

    



    return 0;
}





