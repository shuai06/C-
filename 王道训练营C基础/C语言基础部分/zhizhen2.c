#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change(int *j)   // 
{
    *j = 8;  // 改变了


}

int main()
{
    int i = 10;
    printf("before change i=%d\n",  i);
    change(&i); // 把地址传递过去。 值传递
    printf("after change i=%d\n",  i);

	return 0;

}




