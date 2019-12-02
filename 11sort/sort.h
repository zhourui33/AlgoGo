#ifndef _SORT_H_
#define _SORT_H_

#define TRUE  (1)
#define FALSE (0)
typedef int BOOL;

void CreateRandomArray(int a[], int size);
void PrintArray(int a[], int size, char* title);
void InsertSort(int a[], int size);
void BubbleSort(int a[], int size);
void SelectSort(int a[], int size);
void MergeSort(int a[], int size);

#endif