#include "func.h"


// 前序遍历
void proOrder(pNode p)
{
    if(p)
    {
        putchar(p->c);          // %c
        proOrder(p->left);
        proOrder(p->right);
    }
}


// 中序遍历
void midOrder(pNode p)
{
    if(p)
    {
        midOrder(p->left);
        putchar(p->c);          // %c
        midOrder(p->right);
    }
}


// 后序遍历
void afterOrder(pNode p)
{
    if(p)
    {
        midOrder(p->left);
        midOrder(p->right);
        putchar(p->c);          // %c
    }
}

// 深度优先遍历




// 广度优先遍历














