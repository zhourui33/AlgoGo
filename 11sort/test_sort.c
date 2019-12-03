#include "sort.h"

#define ARRAY_SIZE (100)

void main()
{
    int a[ARRAY_SIZE];
    
    CreateRandomArray(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "Origin");
    QuickSort(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "QuickSort");
}