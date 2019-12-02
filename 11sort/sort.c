#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

static void DoMergeSort(int a[], int start, int end);
static void Merge(int a[], int start, int mid, int end);


static void Merge(int a[], int start, int mid, int end)
{
    int result[end-start+1];
    int j = start, k = mid+1, i = 0;
    int p,q;
    while((j <= mid) && (k <= end))
    {
        if(a[j]<=a[k])
            result[i++] = a[j++];
        else
            result[i++] = a[k++];
    }
    p = j;
    q = mid;
    if(k <= end)
    {
        p = k;
        q = end;
    }
    while(p<=q)
    {
        result[i++] = a[p++];
    }
    for(i = 0;i <= end -start; i++)
    {
        a[start+i] = result[i];
    }
}
static void DoMergeSort(int a[], int start, int end)
{
    int mid = start + (end - start) / 2;

    if(start >= end) return;
    DoMergeSort(a, start, mid);
    DoMergeSort(a, mid+1, end);
    Merge(a, start, mid, end);
}

void MergeSort(int a[], int size)
{
    DoMergeSort(a, 0, size-1);
}

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