#include "func.h"

#define N 1

int main()
{
    char c[N+1] = "ABCDRFGHIJK";  // 用char比较简单这里
    int i, j;
    pNode p[N];
    pNode tree;  // 树根
    for ( i = 0; i < N; i++)
    {
        p[i] = (pNode)calloc(1, sizeof(Node));
        p[i]->c = c[i];
    }
    
    // push
    tree = p[0];
    for (i = 0; i < N; i++) // 外层控制进入树的元素
    {
        if(p[j]->left == NULL)
        {
            p[j]->left = p[i];
        }else if(p[j]->right == NULL)
        {
            p[j]->right = p[i];
            j++;
        }
        
    }
    
    printf("**********\n");
    // 调用
    proOrder(tree);
    printf("**********\n");
    midOrder(tree);
    printf("**********\n");
    afterOrder(tree);
    printf("**********\n");
    







    return 0;
}









