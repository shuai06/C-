#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[20] = "hello";   // 大小固定，cat之后会越界
	
	for(int i=0; i<10; i++)
	{
		printf("%d \n", i);
	}

	printf("str系列函数：\n");
	puts(a);
	strcat(a, " world");
	puts(a);

	

	return 0;

}




