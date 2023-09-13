#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;
    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;
    return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, (p - 1));
        QuickSort(arr, (p + 1), e);
    }
}

int main()
{
    clock_t start, end;
    //int size = 0;
    printf("Enter Size of array: \n");
    //scanf("%d", &size);
    int myarray[1000];
    printf("Enter %d integers in any order: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &myarray[i]);
    }
    printf("Before Sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    start = clock();
    QuickSort(myarray, 0, (size - 1));
    end = clock();
    /* Get the time taken by program to execute in seconds */
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
     
    printf("Time taken to execute in seconds : %f\n", duration);
    printf("After Sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", myarray[i]);
    }
    return 0;
}
