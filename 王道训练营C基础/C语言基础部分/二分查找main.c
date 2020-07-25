#include "func.h"


// 比较规则
int compare(const void*p1, const void*p2)
{
    int *pleft = (int*)p1;
    int *pright = (int*)p2;
    return *pleft - *pright;    // 大于，返回负
}


int doubleSearch(int *arr, int low, int high, int target)
{
    int mid;
    while (low<=high)
    {
        // mid = (low+high)/2;
        mid = low+high>>1; // 右移一位（先算+1）
        if(arr[mid]>target)
        {
            high = mid - 1;

        }else if(arr[mid]<target)
        {
            low = mid+1;
        }else
        {
            return mid;
        }
        
    }
    return -1;
    
}

int main()
{
    int arr[N];
    int i;
    int ret; 
    srand(time(NULL));   // 生成种子
    for(i=0; i<N; i++)
    {
        arr[i] = rand()%100;
    }
    qsort(arr,N,sizeof(int),compare);

    for(i=0; i<N; i++)
    {
        printf("%3d",arr[i]);
    }

    scanf("%d",&i);
    ret = doubleSearch(arr,0,9,i);


    return 0;
}