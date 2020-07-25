#include "func.h"


# define N 1024
int main(int argc, char* argv[])    // main函数 参数是固定的
{
    int *arr = (int*)malloc(20);
    int *p;
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    p = (int*)realloc(arr, 40);    // 扩展
    p[4] = 6;
    
  

    return 0;
}