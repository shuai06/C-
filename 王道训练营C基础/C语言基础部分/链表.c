#include "func.h"

int main()
{ 

    pstu phead=NULL, ptail=NULL; // 定义了一个链表
    int i;
    float score;
    while(scanf("%d", &i) != EOF)
    {

        // 头插法
        list_head_insert(&phead, &ptail, i);

    }
     // 打印
    list_print(phead);
    



    // 删除
    while(printf("输入删除的value"), scanf("%d", &i) != EOF)
    {
        delete_list(&phead, &ptail, i);
        list_print(phead);

        search_list(phead, i);
    }

    // 修改
    while(printf("输入删修改的value"), scanf("%d", &i) != EOF)
    {
        list_modify(phead, i, score);
        list_print(phead);
    }
    return 0;
}

























