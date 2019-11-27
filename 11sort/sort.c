#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE (100)
#define TRUE  (1)
#define FALSE (0)
typedef int BOOL;


void CreateRandomArray(int a[], int size);
void PrintArray(int a[], int size, char* title);
void InsertSort(int a[], int size);
void BubbleSort(int a[], int size);
void SelectSort(int a[], int size);

void InsertSort(int a[], int size)
{
    int i,j, value;

    for(i = 1; i < size; i++)
    {
        value = a[i];
        for(j = i -1; j >= 0; j--)
        {
            if(a[j] > value)
                a[j+1] = a[j];
            else
                break;            
        }
        a[j+1] = value;
    }
}

void BubbleSort(int a[], int size)
{
    int i, j, temp;
    BOOL swap = FALSE;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < (size - 1 - i); j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap = TRUE;
            }
        }
        if(!swap) break;
    }
}

void SelectSort(int a[], int size)
{
    int i, j, temp;

    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void PrintArray(int a[], int size, char* title)
{
    int i;
    printf("%s:\n",title);
    for(i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void CreateRandomArray(int a[], int size)
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
    SelectSort(a, ARRAY_SIZE);    
    PrintArray(a, ARRAY_SIZE, "SelectSort");

    CreateRandomArray(a, ARRAY_SIZE);
    BubbleSort(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "BubbleSort");

    CreateRandomArray(a, ARRAY_SIZE);
    InsertSort(a, ARRAY_SIZE);
    PrintArray(a, ARRAY_SIZE, "InsertSort");
    
}