#include "func.h"


# define N 20
int main(int argc, char* argv[])    // main函数 参数是固定的
{
    FILE *fp;
    char c;
    char p;
    char ret;
    char buf[N] = {0};   // 先初始化
    // fp = fopen("file.txt", "r");
    fp = fopen(argv[1], "r+");    // argv[1] 是传递的第一个参数
    if(fp == NULL)   // 判断打开是否成功， -> 失败
    {
        perror("fopen");   // 定位函数执行错误原因（只能定位刚刚执行的）
        goto error;

    }
    // fgetc   一次读取一个字节
   while ((c = fgetc(fp)) != EOF)
   {
       printf("%c",c);
   }
   

    // fputs   一次写入一个字节
    p = 'H';
    ret = fputc(fp, p);

    
    // fread:      buf没有\0
    ret = fread(buf, sizeof(char), N, fp);
    printf("%d, %s \n", ret, buf);

    // fwrite:
    strcpy(buf, "word");
    ret = fwrite(buf, sizeof(char), strlen(buf), fp);

    // 清空buffer
    memset(buf,0,sizeof(buf));


    // fseek
    fseek(fp, 0, SEEK_SET);   // 移动到开头

    fseek(fp, -12, SEEK_CUR);   // 往回偏移, 与磁盘上实际的字节数对应    


    // ftell





    


















    fclose(fp);  

    error:
        printf("error!!!");
        // fclose(fp);  // 关闭文件




    return 0;
}