#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1.一维数组

void test_yi()
{
	printf("test_一维数组：");
	/*
	数组的条件：
	1.元素一定是连续分配的
	2.所有元素书类型一定相同
	3.所有变量所占字节大小必须相等
	*/


	//求最大最小值
	//倒置
	//查找
	//插入
	//删除


}

void init_array()
{
	//初始化
	//1.完全初始化
	int a[5] = {1,2,3,4,5};
	//3.不完全初始化（未赋值的为0）
	int b[5] = {1,2,3};
	//3.不初始化(所有元素是垃圾值)
	int c[5];
	//4.清零
	int d[5]={0};
	
	//错误写法1：(只能在定义时候才能整体赋值，第二个是下标)
	//int e[5]; 
	//e[5]={1,2,3,4,5}
	
	//错误写法2：(索引[5]代表第六个位置，超出索引了)
	// e[5]=100;

	// 把一个数组a全部元素赋值给另外一个数组b
	//错误写法:(a代表数组第一个元素)  a=b;
	// 正确写法：for
	//for (int i=0;i<5;++i)
	//{
	//	b[i]=a[i];
	//}

	// 以为数组名，代表数组第一个元素的地址


}


void set_val()
{
// 赋值
	int a[5]={1,2};
	int i;

	printf("输入一个值：\n");
	scanf("%d", &a[1]);
	printf("a[0]=%d\n", a[0]);

	for(i=0; i<5; ++i)
	{
		printf("%d\n", a[i]);
	}

	getchar();

}


void rever_array()
{
	//倒置
	int a[7]={1,2,3,4,5,6,7};
	int i, j;
	int t;

	i=0;
	j=6;
	while (i < j)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		i++;
		j--;
	}

	// 输出
	for (i=0; i<7; i++)
	{
		printf("%d", a[i]);
	}

	getchar();
}









