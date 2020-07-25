#include "jiegouti.h"

void main()
{


}



void test()
{       
		/*
		为什么需要结构体？
			为了表示一些复杂的事物，而普通的数据类型无法满足实际需求


		结构体：
			把一些基本类型组合到一起，形成的一个新的符合数据类型


		大小：
			结构体：总大小一般情况下等于各成员大小之和(先不考虑内存对齐)
			共用体：大小等于成员中最大的那个大小。（通常和结构体一起使用）
		

		如何定义(推荐第一种)：
			1. 推荐（这只是定义了一个新的数据类型，并没有定义变量）
			 struct student{
				int num;
				char name[20];
				int age;
			 };

			2. 这样只能定义一次
			 struct student{
				int num;
				char name[20];
				int age;
			 } st1;

			 3. 类型都没写...
			 struct {
				int num;
				char name[20];
				int age;
			 } st1;

			 //赋值和初始化(定义同时可以整体赋值,定义完之后只能单个赋值)
				 定义同时初始化： struct student s1 = {1,'xxx',18};
				 先定义，后赋值：
								  struct student s2;
								  s2.num=1;
								  s2.name='yyy';
								  s2.age=19;


			 //取出结构体变量中每一个成员【重点】
				1.结构体指针变量名.成员名
				2.指针变量名->成员名    （第二种更常用）
							struct student *p = &s;  //注意是&
							p->name; //第一种方式(指针变量->成员变量名,在计算机内部会被转换为(*指针变量名).成员名)
							(*p).name; //第二种方式，与 s.name; 等价


			//结构体变量的运算
				结构体变量不能相加，相减，也不能相互乘除。
				但结构体变量可以相互赋值

			//结构体变量和结构体变量指针作为函数参数传递的问题

			//动态构造结构体数组

			//链表
		
		*/

		int num;

	    struct student{
			int num;
			char name[20];
			char gender;
			int age;
			float score;
			char addr[30];
		} ss={1,'xx','nan',20,99.9,'hhh'};   // ss就是变量 可以直接在这里初始化

		//赋值和初始化
		struct student ss2 = {2,'yy','bei',20,99.9,'zzz'};
		struct student s = {100,'lala','M',20,99.5, 'beij'};




		// 结构体数组
		struct student sArr[3];

		for (int i = 0; i < 3; i++)
		{
			scanf("%d%s %c%d%f%s", &sArr[i].num, sArr[i].name, &sArr[i].gender, &sArr[i].age,&sArr[i].score, &sArr[i].addr); // %c 忽略空格
		}


		// 结构体指针

		struct student *p = &s;  //注意是&
		//p = &s;
		// 获取成员

		p->name; //第一种方式(指针变量->成员变量名,在计算机内部会被转换为(*指针变量名).成员名)
		(*p).name; //第二种方式，与 s.name; 等价

		// p->name的含义：p所指向的那个结构体变量中的name这个成员


		num = p->num++;   // num = p->num, num=p->num+1;   //优先级
		// 第一时间去掉++
		num = p++->num;    // 没问题, num=p->num,  p=p+1


		//浮点型默认在C语言中是double，如果要定义成float，则在后面加f或F， 但是不能准确存储

}

///////////////////////////////////////////

struct Student{
	int num;
	char name[20];
	int age;
};

// 通过函数完成对结构体变量的输入和输出
void struc_func()
{

	struct Student st;

	InputStudent(&st);  //对结构体变量输入
	OutputStudent(st);  //对结构体变量输出
	OutputStudent2(&st);  //对结构体变量输出


}


void InputStudent(struct Student * pstu) //pstu只占4个字节
{
	(*pstu).num=1;
	strcpy(pstu->name, "xxx");  
	pstu->age=18;

};

/*  这是无法改变主函数的值的
void InputStudent(struct Student stu)
{
	stu.num=1;
	strcpy(stu.name, "xxx");  
	stu.age=18;

};*/


////应该发送内容还是传送地址？
//如果传递的是内容，内存消耗大
void OutputStudent(struct Student stu)
{
	printf("%d, %s %d", stu.num,stu.name, stu.age);
}

// 如果传递的是地址，可能不安全，但是提高了速度，节省了内存（推荐这种方法）
void OutputStudent2(struct Student *pstu)
{
	printf("%d, %s %d", pstu->num,pstu->name, pstu->age);
}



/*
【指针优点大总结：】

快速的传递数据，较少了内存的消耗 【重点】
使函数返回一个以上的值  【重点】
能直接访问硬件
能方便的处理字符串


**/


//共用体
void test_union()
{
	//共用体：大小等于成员中最大的那个大小（通常和结构体一起使用）

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

	union data d; // 现在最大的就是4
	d.i = 4;
	d.c='A';
	d.f = 99.9;


}

