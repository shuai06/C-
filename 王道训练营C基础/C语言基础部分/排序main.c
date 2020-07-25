#include "func.h"


int main()
{
    int *arr = (int*)calloc(N, sizeof(int));
    // int arr[N]; // zhan
    // int *arr = calloc(N, sizeof(int));   // 放到堆空间
    int i;
    // 随机数
    time_t begin, end;
    srand(time(NULL)); // 种子
    for (i = 0; i < N; i++)
    {
        arr[i] = rand()%100;
        
    }
    print_arr(arr);

    // printf("排序后：\n");
    select_sort_arr(arr);

    insert_sort_arr(arr);


    begin=time(NULL);
    quick_sort_arr(arr,0, N-1);
    end = time(NULL);
    printf("use time = %d\n", end-begin);

    qsort(arr,N,sizeof(int), compare);   // 非递归方式，不会爆栈
    
    arr_heap(arr);
    


    return 0;
}