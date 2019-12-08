#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linear_sort.h"

void CountingSort(int a[], int size)
{
    int max = a[0];
    int *res = NULL;
    int *count = NULL;

    for(int i = 0; i < size; i++)
    {
        if(a[i]>max)
            max = a[i];
    }

    count = (int *)malloc(sizeof(int) * (max+1));
    memset(count, 0, sizeof(int) * (max+1));
    for(int i = 0; i < size; i++)
    {
        count[a[i]]++;
    }

    for(int i = 1; i < max+1; i++)
    {
        count[i] += count[i-1];
        printf("count[%d]:%d\t", i, count[i]);
    }
    printf("\n");
    res = (int *)malloc(sizeof(int) * size);
    memset(res, 0, sizeof(int) * size);
    for(int i = 0; i < size; i++)
    {
        res[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    for(int i = 0; i < size; i++)
    {
        a[i] = res[i];
    }
    return;
}