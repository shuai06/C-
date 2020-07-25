#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//文件
void test_file()
{
	# define N 20

	FILE *fp;
    char c;
    char p;
    char ret;
    char buf[N] = {0};   // 先初始化
    // fp = fopen("file.txt", "r");
    fp = fopen("D:\Desktop\1.txt", "r+");    // argv[1] 是传递的第一个参数
    if(fp == NULL)   // 判断打开是否成功， -> 失败
    {
        perror("fopen");   // 定位函数执行错误原因（只能定位刚刚执行的）
        goto error;

    }
    // fgetc   读取，一次读取一个字节
   while ((c = fgetc(fp)) != EOF)
   {
       printf("%c",c);
   }
   

    // fputs   写入，一次写入一个字节
    p = 'H';
    ret = fputc(p, fp);


	// printf(FILE *fp,const char *format, ...) 函数来写把一个字符串写入到文件中
	fprintf(fp, "This is testing for fprintf...\n");

    


    // fread:      buf没有\0
    ret = fread(buf, sizeof(char), N, fp);
    printf("%d, %s \n", ret, buf);

    // fwrite:
    strcpy(buf, "word");
    ret = fwrite(buf, sizeof(char), strlen(buf), fp);

    // 清空buffer
    memset(buf,0,sizeof(buf));




    // fseek
    fseek(fp, 0, SEEK_SET);   //  移动到开头。	SEEK_SET,偏移量的起始点:文件开始处

    fseek(fp, -12, SEEK_CUR);   // 往回偏移, 与磁盘上实际的字节数对应。	SEEK_CUT:文件当前位置 
							    // SEEK_END,偏移量的起始点：SEEK_END


    // ftell      获取文件读写指针的当前位置
	long last = ftell(fp);


    fclose(fp);  

    error:
        printf("error!!!");
        // fclose(fp);  // 关闭文件






}

//typedef
void test_typedef()
{


}

//NULL
void test_null()
{
	/*
	二进制全部为0的含义：  
		1.数值为0
		2.字符串结束标记符 '\0'
		3.空指针NULL
			NULL表示编号为0的地址
			NULL表示的是零，不是数字，而是代表内存单元的编号
			
			计算机规定了，以零为编号的存储单元的内存不可读、不可写
	
	
	*/


}

void main()
{



}