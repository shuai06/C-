#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 5    //后门不能加分号

int main()
{
    
    int a[N]={1,2,3,4,5};
    int *p;
    int i;
    p = &a[4];  // 指向a最后一个元素

    for(i=0; i<N; i++)     // 指针偏移
    {
        printf("%3d", *(p-i));     // p +sizeof(int)
    }
    printf("\n");




	return 0;

}




