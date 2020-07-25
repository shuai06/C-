#include "test.h"


void main()
{

	//base_pointer();

	exchange_two();

}


void test1()
{
	int j=3;
	int * q; // q是变量名, int *表示q变量存放的是int类型变量的地址（int * 是数据类型）
	// 错误写法：q=55;   后面不能是值，只能跟地址
	q=&j;   //*q与j是等同的
	/*
	1.q保存了j的地址，引起：q指向j。
	2.q不是j，j不是q。修改q的值不会影响j,修改j的值也不会影响q的值
	3.如果一个指针变量指向一个普通变量，则*指针变量完全等同于普通变量
	
	*/


	/*
	指针：就是地址，地址就是指针
	指针变量：存放地址的变量
	两者不是一个概念
	但是，通常在叙述中，会把指针变量简称为指针
	*/




	// 一级指针
    // 指针的本质： 存地址(内存单元的编号)，间接访问
    // 指针使用场景：

    // & 取地址操作符/【引用】
    // * 取值操作符/【解引用】

}

void test2()
{
	/*
	指针的重要性;
	表示一些复杂的数据结构;
	快速的传递数据
	使函数返回一个以上的值
	能直接访问硬件
	能方便的处理字符串
	是理解面向对象语言中引用的基础
	
	*/


	//地址：
	/*
		内存单元的编号
		从零开始的非负整数
		范围：
	
	*/


	//指针：
	/*
	指针就是地址，地址就是指针
	指针变量就是存放内存单元的变量，
	两者不是一个概念
	但是，通常在叙述中，会把指针变量简称为指针
	指针的本质就是一个操作受限的非负整数
	
	*/

	//指针的分类：
	/*
	1.基本类型的指针
	int *p;
	int i=10;
	int j;
	p = &i;
	i=*p;
	printf("%d",j);
	
	例子，见函数base_pointer
	
	*/


}

void base_pointer()
{
	int *p;
	int *q;
	int i=5;

	//*p = i; //【错误】，*p代表的是p指向的地址的变量的值，p现在指向的垃圾值(还没有初始化)
	//应该这样
	p = &i;

	//*q=p;  //【错误】，有语法错误，*q是整形，p是int*类型
	//*q = *p; //【错误】,语法没错，但是q指向垃圾值（没初始化）
	//应该这样：
	//p=q;  // 【错误】，q赋给p，p也变成垃圾值
	//printf("%d\n", *p);  // q的空间是属于本程序的，所以本程序可以读写q的内容，但是如果q的内部是垃圾值，则本程序不能读写*p的内容,因为*q所代表的的内存单元的控制权限并没有分配给本程序
	//


	// 指针变量的运算：
	// 指针变量不能相加、相乘、相除（能相减：如果两个指针变量指向的是【同一块连续空间中的不同存储单元】）
	/*
		p = &a[1];
		q = &a[3];
		printf("%d", q-p);
	
	*/

	getchar();

}


//指针的偏移
void test3()
{
    int a[N]={1,2,3,4,5};
    int *p;
    int i;
    p = &a[4];  // 指向a最后一个元素

    for(i=0; i<N; i++)     // 指针偏移
    {
        printf("%3d", *(p-i));     // p + sizeof(int)
    }
    printf("\n");

	getchar();
}


//指针与自增
void test4()
{
    int a[3]={2,7,8};
    int *p;
    int j;

    p = a;
    j = *p++;     // j = *p; p=p+1。     
    printf("a[0]=%d, j=%d, *p=%d \n", a[0], j, *p);  // 2,2,7


    j = p[0]++; // j=p[0],  p[0] = p[0] +1
    printf("a[0]=%d, j=%d, *p=%d \n", a[0], j, *p);  // 2,7,8  ？？？  

	getchar();
}

//野指针: free以后的指针未被赋值为NULL  (指向了一个未知的空间)
void test5()
{
	
    int *p, *p1, *p2, *p3;
    p = (int *)malloc(4);
    *p = 1;
    free(p);

    p = NULL;   // 赋值null以后，后面用的话会崩溃，能迅速找到问题

    p1 = (int *)malloc(4);  
    *p1 = 2;  // 没有free

    p2 = (int *)malloc(4);
    *p2 = 2;
    free(p1);

    p3 = (int *)malloc(4);
    *p3 = 3;
    *p1 = 20; // 以为p1free了，这里又赋值
    printf("p3 = %d", *p3);   //  20了    malloc有缓存机制


}



// 经典程序：互换两个数字
void exchange_two()
{
	int a=3;
	int b=5;
	//int t;

	//之前的做法
	//t=a;
	//a=b;
	//b=t;

	// 现在要求调用一个函数实现
	test_exchange3(&a, &b);

	printf("a=%d,b=%d",a,b);

	getchar();

}

// 不能完成互换功能
void test_exchange1(int a, int b)
{
	int t;

	t=a;
	a=b;
	b=t;
}


// 不能完成互换功能，只是把q和p的值换了，a和b并没有互换
void test_exchange2(int *p, int *q)
{
	int *t; // 如果要互换，变量类型必须一致	
	t = p; 
	p = q;
	q = t;

	// 形参的改变，不会改变实参的值
}


// 可以完成互换: p是a的地址，*p就是a
void test_exchange3(int *p, int *q)
{
	int t; // 如果要互换，变量类型必须一致	
	t = *p;  // *p是int，p是int* 
	*p = *q;
	*q = t;
}


// *的含义
void test6()
{
	//1.乘法
	//2.定义指针变量 
	int *p;  //定义了一个叫p的变，int * 表示p只能存放地址
	//3.指针运算符：取地址的逆运算/间接访问
	// 放在已经定义好的指针变量的前面，取改指针的值
	//*p 表示以p的内容为地址的变量

	//写法：下面三种是等价的
	//int * p;
	//int *p;
	//int* p;

}

void free_test()
{
/*
脏数据
申请的空间不释放：内存泄露
堆空间：一旦申请，一直占用，除非free

*/
    int i;
    char *p;
    scanf("%d", &i);
    p = (char *)malloc(i);
    strcpy(p, "hello");   // p指向堆空间
    // p = "hellp";
    puts(p);
    free(p);  // 释放
    printf("free p ~~~~~~~~~~~");

}


void test7()
{
	// 一个指针变量到底占几个字节？
	/*
	指向不同类型，是不同的，比如int 一般是4个字节, char就是1个。     sizeof()可以查看：sizeof(double)
	p,q,r所占的字节数是一样的
	【总结：】一个指针变量，无论他指向的变量占几个字节，该指针变量只占【四个字节】。
	一个变量的地址使用该变量首字节的地址来表示
	
	*/

}




//动态内存分配（重点）
void test8()
{
	/*
	1.传统数组的缺点
		a.数组长度必须事先制定，且只能是长整数，不能是变量（int len=5; int a[len]; 这样是错误的）
		b.传统形式定义的数组，该数组的内存，程序员无法手动释放（一旦定义，该分配空间一直存在，直到数组所在的函数运行结束，数组的空间才会被系统释放）
		c.数组的长度不能再函数运行过程中动态扩充或缩小(长度一旦定义，其长度就不能再更改)
		d.A函数定义的数组，在A函数运行期间可以被其他函数使用；但A函数执行完毕后，A函数中的数组将无法再被其他函数使用
		传统数组也叫静态数组
			

	2.为什么需要动态分配内存
		解决了传统数组的4个缺陷


	3.动态内存分配举例_  动态数组的构造


	4.静态内存和动态内存的比较


	5.跨函数使用内存的问题
	
	*/

}

void dynami_memo1()
{
	// malloc 是memory(内存) allocate(分配)的缩写

	int i = 5;
    char *p;
    p = (char *)malloc(i);  
	/*
	
		1.要使用malloc，必须添加malloc.h或stdlib.h头文件
		2.malloc只有一个形参，且形参必须是整数类型
		3.上面，表示请求系统为本程序分配5个字节
		4.malloc函数只能返回第一个字节的地址，所以前面要把地址强制转换为int*
		5.p本身的内存是静态分配的，p所指向的内存是动态分配的
	*/

    strcpy(p, "hello");   // p指向堆空间
    // p = h e l l o \o;
    puts(p);
    free(p);  // 释放p所指向的内存 （p本身的内存是静态的，不能由程序员手动释放）
    printf("free p ~~~~~~~~~~~");


// 脏数据
// 申请的空间不释放：内存泄露
// 堆空间：一旦申请，一直占用，除非free
}


void f(int *q)
{
	// *p = 200; // error
	// q = 20   //error
	// q是p的一份拷贝(副本)
	// **q=200  // error
	*q=200;
}

void dynami_memo2()
{
	//int *arr = (int*)malloc(20);
 //   int *p;
 //   arr[0] = 1;
 //   arr[1] = 1;
 //   arr[2] = 1;
 //   arr[3] = 1;

 //   p = (int*)realloc(arr, 40);    // 扩展
 //   p[4] = 6;

	int *p = (int *)malloc(sizeof(int));
	*p = 10;

	printf("%d\n", *p); //10
	f(p);
	printf("%d\n", *p); //200

}


//动态内存分配举例 动态一维数组的构造
void dynami_memo3()
{
	int len;
	int *pArr;
	int i;

	printf("请输出要存放元素的个数：");
	scanf("%d", &len); // 5
	pArr = (int *)malloc(4*len);  // 数组长度为len； 5*4=20,（默认pArr指向第一个字节，但是由于进行了int强转，所以pArr指向前四个字节,pArr指向后面4个字节）
	//类似于 int pArr[len];

	//赋值
	for (i=0; i<len; ++i)
	{
		scanf("%d", &pArr[i]);
	}
	
	//输出
	printf("一维数组的内容是: \n");
	for (i=0; i<len; ++i)
	{
		printf("%d, ", pArr[i]);
	}


	realloc(pArr, 40);    // 扩展

	//释放数组
	free(pArr);


}


//动态内存和静态内存的比较
void dynami_memo4()
{
	/*
	静态内存是由系统自动分配，由系统自动释放，是在栈分配的

	动态内存是由程序员手动分配，手动释放，是由堆分配的

	malloc是堆分配的

	栈是存储结构，堆是排序方式
	
	*/



}



void multi_test(int **pp)
{
	int j=300;
	//  pp是p的地址，那*pp 就是p
	*pp = &j;   // 修改
	**pp = 200; // 修改

}
//多级指针（意义：跨函数使用内存）
void two_pointer()
{
	// 【场景】：当在子函数中需要修改主函数某一个一级指针变量的值，就需要二级指针
    //char b[N][10] = {"lilei","hanmeimei","xiyangyang","huitailang", "xiongda"};
    //char * p[N];  // 指针数组，里面存储的指针类型就是 二级指针   // &p[0]        每次偏移是固定的，64位数下就是8个字节
    //// char **p2;
    //int i;
    //for(i=0; i<N; i++)
    //{
    //    p[i] = b[i];

    //}

    //for(i=0; i<N; i++)
    //{
    //    puts(p[i]);

    //}

	int i = 10;
	int *p = &i;
	int **q = &p;
	int ***r = &q;

	//r = &p;   // 错误，因为r是int**类型，r只能存放int**类型变量的地址
	printf("%d",***r); // r的值

	//在另一个函数内部改变变量值
	multi_test(&p);  // p是int *, 那么 &p是int**
}


void f1(int **q)
{
	int i=5;
	//*q等价于p，q和**q都不等价于p
	// *q=i // error
	*q = &i;  // p=&i
	//**q=i;

}

//静态变量不能跨函数使用
void dynami_memo5()
{
	int *p;

	f1(&p);
	printf("%d", *p);  // 本语句语法没有问题，但逻辑上有问题（因为f函数中i的静态分配的，f结束，i的空间就释放了）



}


void f2(int **q)
{
	*q = (int *)malloc(sizeof(int));
	// 等价于p = (int *)malloc(sizeof(int));
	//q=5;  // error
	//*q=5; // p=5   error
	**q=5; // *p=5


}

//动态内存可以跨函数使用（重点）
void dynami_memo6()
{

		int *p;

	f2(&p);
	printf("%d", *p); // 能改变。p指向的是上面堆里面分配的空间

}
