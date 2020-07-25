#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�ļ�
void test_file()
{
	# define N 20

	FILE *fp;
    char c;
    char p;
    char ret;
    char buf[N] = {0};   // �ȳ�ʼ��
    // fp = fopen("file.txt", "r");
    fp = fopen("D:\Desktop\1.txt", "r+");    // argv[1] �Ǵ��ݵĵ�һ������
    if(fp == NULL)   // �жϴ��Ƿ�ɹ��� -> ʧ��
    {
        perror("fopen");   // ��λ����ִ�д���ԭ��ֻ�ܶ�λ�ո�ִ�еģ�
        goto error;

    }
    // fgetc   ��ȡ��һ�ζ�ȡһ���ֽ�
   while ((c = fgetc(fp)) != EOF)
   {
       printf("%c",c);
   }
   

    // fputs   д�룬һ��д��һ���ֽ�
    p = 'H';
    ret = fputc(p, fp);


	// printf(FILE *fp,const char *format, ...) ������д��һ���ַ���д�뵽�ļ���
	fprintf(fp, "This is testing for fprintf...\n");

    


    // fread:      bufû��\0
    ret = fread(buf, sizeof(char), N, fp);
    printf("%d, %s \n", ret, buf);

    // fwrite:
    strcpy(buf, "word");
    ret = fwrite(buf, sizeof(char), strlen(buf), fp);

    // ���buffer
    memset(buf,0,sizeof(buf));




    // fseek
    fseek(fp, 0, SEEK_SET);   //  �ƶ�����ͷ��	SEEK_SET,ƫ��������ʼ��:�ļ���ʼ��

    fseek(fp, -12, SEEK_CUR);   // ����ƫ��, �������ʵ�ʵ��ֽ�����Ӧ��	SEEK_CUT:�ļ���ǰλ�� 
							    // SEEK_END,ƫ��������ʼ�㣺SEEK_END


    // ftell      ��ȡ�ļ���дָ��ĵ�ǰλ��
	long last = ftell(fp);


    fclose(fp);  

    error:
        printf("error!!!");
        // fclose(fp);  // �ر��ļ�






}

//typedef
void test_typedef()
{


}

//NULL
void test_null()
{
	/*
	������ȫ��Ϊ0�ĺ��壺  
		1.��ֵΪ0
		2.�ַ���������Ƿ� '\0'
		3.��ָ��NULL
			NULL��ʾ���Ϊ0�ĵ�ַ
			NULL��ʾ�����㣬�������֣����Ǵ����ڴ浥Ԫ�ı��
			
			������涨�ˣ�����Ϊ��ŵĴ洢��Ԫ���ڴ治�ɶ�������д
	
	
	*/


}

void main()
{



}