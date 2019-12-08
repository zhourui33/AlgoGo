#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linear_sort.h"

#define ARRAY_SIZE (100)

static void PrintArray(int a[], int size, char* title)
{
    int i;
    printf("%s:\n",title);
    for(i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

static void CreateRandomArray(int a[], int size)
{
    int loop;
    srand((unsigned)time(NULL));
    for(loop = 0; loop < size; loop++)
    {
        a[loop] = rand() % 100;
    }
}

void main()
{
    int a[ARRAY_SIZE];
    
    CreateRandomArray(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "Origin:");
    CountingSort(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "AfterSort:");
}