#include "func.h"

typedef struct 
{
    int num;
    char name[20];
    float score;
}stu;


# define N 1024
int main(int argc, char* argv[])    // main函数 参数是固定的
{
    FILE *fp;
    char c;
    char p;
    char ret;
    stu s;

    if (argc != 2)
    {
        printf("error args\n");
        goto error;
    }
    
    fp = fopen(argv[1], "r+");    // argv[1] 是传递的第一个参数
    if(fp == NULL)   // 判断打开是否成功， -> 失败
    {
        perror("fopen");   // 定位函数执行错误原因（只能定位刚刚执行的）
        goto error;

    }

    // fscanf(stdin, "%d%s%f",&s.num, s.name, &s.score);  // name 不需要取地址(数组), 标准输入
    // fprintf(stdout, "%d%s%f",s.num, s.name, s.score);

    fscanf(fp, "%d%s%f",&s.num, s.name, &s.score);  //从文件，格式化读取
    fseek(fp, 0, SEEK_CUR);
    fprintf(fp, "%d%s%f",s.num, s.name, s.score);
    fclose(fp);  



    // 循环读取
    while (fscanf(fp, "%d%s%f",&s.num, s.name, &s.score) != EOF)
    {
         printf("new = %d %s %5.2f \n",s.num, s.name, s.score);
    }
    

    error:
        printf("error!!!");
        // fclose(fp);  // 关闭文件




    return 0;
}