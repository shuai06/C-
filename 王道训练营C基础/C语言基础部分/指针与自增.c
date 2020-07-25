#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{ 
    int a[3]={2,7,8};
    int *p;
    int j;
    p = a;
    j = *p++;     // j = *p; p=p+1。     ++的优先级高
    printf("a[0]=%d, j=%d, *p=%d \n", a[0], j, *p);  // 2,2,7


    j = p[0]++; // j=p[0],  p[0] = p[0] +1
    printf("a[0]=%d, j=%d, *p=%d \n", a[0], j, *p);  // 2,7,8    ??????


	return 0;
}




