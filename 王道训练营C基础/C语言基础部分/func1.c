#include "func.h"



// 头插法
void list_head_insert(pstu *pphead, stu **pptail, int i)
{
    pstu pnew = (pstu)malloc(sizeof(stu));  // 申请一个结构体空间的大小
    memset(pnew,0, sizeof(stu)); //指向的空间 赋0
    pnew -> num = i;
    // pnew -> pnext = NULL;

    if(*pphead ==NULL)  // 链表为空
    {
        *pphead = pnew;
        *pptail = pnew;

    }else{  // 链表不为空

        pnew ->pnext = *pphead;  // 原来的链表给新节点pnext
        *pphead = pnew;       // 新节点变为链表头
    }


}


// 尾插法 新建链表
void list_tail_insert(pstu *pphead, pstu *pptail, int i)
{
    pstu pnew = (pstu)calloc(1, sizeof(stu));   // calloc 申请的空间是指定的，自己把申请的空间初始化填充为0不用mset
    pnew -> num = i;

    if(*pphead==NULL)
    {
        *pphead = pnew;
        *pptail = pnew;

    }else{
        (*pptail)->pnext = pnew;
        *pptail = pnew;
    }

}


// 有序插入 新建链表
// 1.如果比头节点小, 插入到头部
// 2.如果比头节点大,
void list_sort_insert(pstu *pphead, pstu *pptail, int i)
{
    pstu pcur, ppre;
    pstu pnew = (pstu)calloc(1, sizeof(stu));   // calloc 申请的空间是指定的，自己把申请的空间初始化填充为0不用mset
    pnew -> num = i;
    pcur = ppre = *pphead;   //

    if(pcur==NULL)
    {
        *pphead = pnew;
        *pptail = pnew;

    }else if(i<pcur->num){ // 插入在开头
    // 头插法
    pnew->pnext = *pphead;
    *pphead = pnew;
    }else  // 插入到中间 或者尾部
    {
        while (pcur)  //  != NULL
        {
            if(i < pcur->num)
            {
                pnew->pnext = pcur;
                ppre->pnext = pnew;
                break;
            }
            ppre = pcur;   // 注意！！！大哥与小弟
            pcur = pcur -> pnext;
        }
        if(pcur == NULL) // 没插入进去
        {
            // 尾插法 
            (*pptail)->pnext = pnew;
            *pptail = pnew;
        }       
    }
}


// 有序插入2
void list_sort_insert2(pstu *pphead, pstu *pptail, int i)
{

    pstu pcur;
    pstu pnew = (pstu)calloc(1, sizeof(stu));   // calloc 申请的空间是指定的，自己把申请的空间初始化填充为0不用mset
    pnew -> num = i;
    pcur = *pphead;   //

    if(pcur==NULL)
    {
        *pphead = pnew;
        *pptail = pnew;

    }else if(i<pcur->num){ // 插入在头部
        // 头插法
        pnew->pnext = *pphead;
        *pphead = pnew;
    }else  // 插入到中间 或者尾部
    {
        while (pcur->pnext)
        {
            
            pnew->pnext = pcur->pnext;
            pcur->pnext = pnew;
            break;
        }
        pcur = pcur->pnext;
        
    }
    if(pcur->pnext == NULL) // 插入到尾部
    {
        (*pptail)->pnext = pnew;
        *pptail = pnew;

    }
}



// 打印
void list_print(pstu phead)
{
    while(phead != NULL)
    {
        printf("%3d", phead->num);
        phead = phead ->pnext;

    }
    printf("\n");
}


// 删除
void delete_list(pstu *pphead, pstu *pptail, int i)
{

    pstu pcur, ppre;
    pcur = *pphead;
    ppre = *pphead;
    if(pcur == NULL)
    {
        printf("list is empty \n");
        return;
    }else if(i==pcur->num) // 删除的是头结点
    {
        *pphead = pcur->pnext;
        free(pcur);
        pcur = NULL;  // 防止是野指针
        if(*pphead==NULL) //if删除后链表为空
        {
            *pptail = NULL;
        }
    }else  // 删除的不是头结点
    {
        pcur = pcur->pnext;
        while (pcur)   //
        {
            if(i==pcur->num)
            {
                ppre->pnext = pcur->pnext;
                free(pcur);
                break;

            }
            ppre = pcur;
            pcur = pcur->pnext;
        }
        if(pcur == *pptail)  // 因为删除的是尾部，所以该表pptail
        {
            *pptail = ppre;
        }
        if(pcur == NULL)
        {
            printf("no this value \n");
        }
        
    }

}


// 查询
void search_list(pstu phead, int i)
{
    while(phead)
    {
        if(phead->num == i)
        {
            printf("find a value= %d \n", phead->num);
            break;
        }
        phead = phead->pnext;
    }
    if(phead == NULL)
    {
        printf("Not find this value \n");
    }

}


// 修改
void list_modify(pstu phead, int num, float score)
{
    while(phead)
    {
        if(phead->num == num)
        {
            phead->score = num;
            break;
        }
        phead = phead->pnext;
    }
    if(phead == NULL)
    {
        printf("Not find this num \n");
    }


}






