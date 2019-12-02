#include "sort.h"

#define ARRAY_SIZE (100)

void main()
{
    int a[ARRAY_SIZE];

    CreateRandomArray(a, ARRAY_SIZE);
    SelectSort(a, ARRAY_SIZE);    
    PrintArray(a, ARRAY_SIZE, "SelectSort");

    CreateRandomArray(a, ARRAY_SIZE);
    BubbleSort(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "BubbleSort");

    CreateRandomArray(a, ARRAY_SIZE);
    InsertSort(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "InsertSort");

    CreateRandomArray(a, ARRAY_SIZE);
    MergeSort(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "MergeSort");
    
}