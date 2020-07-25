#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 


    struct student{
        int num;
        char name[20];
        char gender;
        int age;
        float score;
        char addr[30];
    };
    

    struct student{
        int num;
        char name[20];
        char gender;
        int age;
        float score;
        char addr[30];
    } ss={1,'xx','nan',20,99.9,'hhh'};   // ss就是变量 可以直接在这里初始化

    int num;

    struct student s = {100,,"lala",'M',20,99.5, "BeiJing"};
    struct student sarr[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d%s %c%d%f%s", &sArr[i].num, sArr[i].name, &sArr[i].gender, &sArr[i].age,&sArr[i].score, &sArr[i].addr); // %c 忽略空格
    }

    struct student *p;
    p = &s;
    // 结构体指针
    // 获取成员
    //  p->name,    (*p).name


    num = p->num++;   // num = p->num, num=p->num+1;   优先级
    // 第一时间去掉++
    num = p++->num;    // 没问题 num=p->num,  p=p+1






    // typedef  编译的时候进行
    typedef struct student   // student也可以省略
    {
        int num;
        char name[20];
        char gender;
        int age;
        float score;
        char addr[30];
    }stu, *pstu;   // 类型的别名。   pstu  <==> struct student*
    stu s={1,'xx','nan',20,99.9,'hhh'}};
    puts p;
    p = &s;
    printf("%d", p->num);

    typedef int INTEGER; //与#define的顺序相反


    


    return 0;
}

























