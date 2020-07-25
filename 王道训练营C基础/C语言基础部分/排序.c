#include "func.h"


// 打印数组
void print_arr(int *arr)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
    
}


// 选择排序（对冒泡的一种优化）
// 内层一轮只交换一次(降低了交换) 时间复杂度为n^2
void select_sort_arr(int *arr)
{
    int i,j,max_pos;
    for (i = N; i >0; i--)
    {
        max_pos = 0;   // 记录最大值的下标
        for (j=1; j<i; j++)
        {
            if (arr[j]>arr[max_pos])
            {
                max_pos = j;
                
            }
            
        }
        SWAP(arr[max_pos],arr[i-1]);  // 用宏来实现
        

    }
    

}


// 插入排序  （还是有使用前景的）
// 优势：
//要插入 的元素的数目
void insert_sort_arr(int *arr)
{
    int i,j,k, insert_val;
    for(i=1;i<N;i++)  // 要插入的元素
    {
        for(j=0;j<i;j++) // 有序数的数目
        {
            if(arr[i]<arr[j])
            {
                insert_val = arr[i];
                // 后移
                for(k=i-1; k>j; k--)
                {
                    arr[k+1] = arr[k];
                }
                arr[j] = insert_val;
                break;
            }
        }
    }
}



// 分割函数
int partition(int *arr, int left, int right)
{
    int i, k;
    for(i=left,k=left; i<right; i++)
    {
        if(arr[i]<arr[right])
        {
            SWAP(arr[i], arr[k]);
            k++;
        }
    }
    SWAP(arr[k], arr[right]);
    return k;

}





// 快排  （用的比较多）  --- 递归用的比较多   时间确实快
void quick_sort_arr(int *arr, int left, int right) // 左边界、右边界
{
    int pivot; // 分割点
    if(left<right)
    {
        pivot = partition(arr, left, right);  // 分割，返回分割点的位置
        quick_sort_arr(arr, left, pivot-1);
        quick_sort_arr(arr,pivot+1, right);
    }

}


// windows下的stack只有1MB


// 非递归的快排

int compare(const void *p1, const void *p2)  // *p 指向数组中任意两个元素的地址值
{
    int *pleft = (int *)p1;
    int *pright = (int *)p2;

    return *pleft - *pright;
}


// 堆排序  
// 大顶堆（每个单元，父元素大于自己的孩子）
/*
最后一个父亲节点的位置：n/2

dad = N2-1;
son = 2*dad + 1;


*/

//
void adjust_max_heap(int *a, int start, int len)
{
    int dad = start;
    int son = 2*dad+1;
    while (son<len)
    {
        if(son+1 < len &&a[son]<a[son+1])       // >
        {
            son++;
        }
        if(a[dad]<a[son])     // >
        {
            SWAP(a[dad], a[son]);
            dad = son;
        }else
        {
            break;
        }
        
    }
    
}

// 从小到大，堆排序
void arr_heap(int *arr)
{
    // 将数组调整为大根堆
    int i;
    for(i=N/2-1; i<=0; i--)
    {
        adjust_max_heap(arr, i, N);
    }
    SWAP(arr[0], arr[N-1]);
    for(i=N-1; i>0; i--)
    {
         adjust_max_heap(arr, 0, i);
         SWAP(arr[0], arr[i-1]);

    }
}






