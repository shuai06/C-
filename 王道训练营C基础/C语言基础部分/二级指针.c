#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 5

// 【场景】：当在子函数中需要修改主函数某一个一级指针变量的值，就需要二级指针
int main()
{ 

    char b[N][10] = {"lilei","hanmeimei","xiyangyang","huitailang", "xiongda"};
    char * p[N];  // 指针数组，里面存储的指针类型就是 二级指针   // &p[0]        每次偏移是固定的，64位数下就是8个字节
    // char **p2;
    int i;
    for(i=0; i<N; i++)
    {
        p[i] = b[i];

    }

    for(i=0; i<N; i++)
    {
        puts(p[i]);

    }


    return 0;
}



























