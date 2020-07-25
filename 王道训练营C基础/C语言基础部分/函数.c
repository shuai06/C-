# include "func.h"
// 所有引用都放在了 func.h里面， 下面的c都引用这个文件即可，简洁
// 增量编译，提高效率
// 链接： func.obj里的函数的入口地址，替换main.obj


// 函数不能嵌套定义

// 声明
// int printstart(int);

int main()
{ 

    int a=5;
    printstart(a); // 调用

    printmsg();


    return 0;
}

























