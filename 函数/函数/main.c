#include "func.h"


void before_func()
{
	printf("我是函数测试，在主函数之前定义的。");
	getchar();
}


void main()
{

// 函数定义写在主函数之前的时候，那么就无需在主函数里面声明这个函数，只需要把函数体写在主函数前即可
//否则，需要先声明.

	// 此函数定义在主函数之前，直接调用即可，无须声明
	//before_func();

	//在主函数之后定义的，需要先声明才能调用。
	//1.声明(要放在main外面，我放在了自定义的头文件里面)
	//2.调用
	//after_func();

	// 求最大值
	//int i,j;
	//i=5;j=10;
	//get_max(i, j);
	int i;
	for(i=0;i<20;++i)
	{
		get_max(i,i+1);
	}
	getchar();

}


int after_func()
{
	printf("我是函数测试，在主函数之后定义的，需要先声明才能调用。");
	getchar();

	return 0;
}


//求最大值
void get_max(int a, int b)
{

	int max_val = a>b?a:b;

	printf("%d和%d比较，最大值为: %d \n", a,b,max_val);

}


/*
return和break的区别：
1.break:循环、switch
2.return终止函数

*/



/*
函数的分类：
1.有参函数和无参函数
2.有返回值和无返回值
3.库函数和用户自定义函数
4.普通函数和主函数(main)：一个程序只能有一个主函数，主函数既是程序的入口，也是程序的出口
主函数能调用主函数，其他函数不能调用main函数，普通函数可以相互调用
5.值传递和引用传递(其实这样说是不对的)

*/




/*
如何在软件开发中，合理的设计函数来解决实际问题：
功能划分的详细一些，提高利用率

函数是C语言的基本单位，类是Java，C#等的基本单位

*/



/*
常用的系统函数:
1. doulbe sqrt(double x)           求x的平方根

2. int abs(int x)				   求整数的绝对值

3. double fabs(double x)	       			



推荐书籍：
机械工业出版社：《turboc2.0使用大全》

*/


/*

递归：
栈：先进先出

*/



/*

变量的作用于和存储方式：
1.按作用域分：全局变量，局部变量（函数内部定义的变量/函数的形参）
2.按变量的存储方式：静态变量，自动变量，寄存器变量

*/

int k=99;

void test_var()
{
	//局部变量与全局变量命名相同：局部变量会屏蔽掉全局变量



}



