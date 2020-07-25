#include "func.h"


// 初始化
void init_stack(pStack p)
{

    p->head = NULL;
    p->size = 0;
}


void push_stack(pStack p, int val)
{
    // 头插法
    pNode pnew = calloc(1, sizeof(Node));
    pnew ->m_val = val;
    p->head = pnew;

    pnew->pnext = p->head;
    p->head = pnew;
    p->size++;

    

}

void pop_stack(pStack p)
{
    pNode pcur;
    if(!p->head)
    {
        printf("栈 空");
        return;
    }
    // 头删法
    pcur = p->head;
    p->head = pcur->pnext;
    free(pcur);
    pcur = NULL;
    p->size --;

}


int top_stack(pStack p)
{
    return p->head->m_val;
}

// 判断栈是否为空
int empty_stack(pStack p)
{
    return !p->size;  // 空的话:1
}








































