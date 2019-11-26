#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE (100)

void PrintArray(int a[], int size, char* title);
void BubbleSort(int a[], int size);

void SelectSort(int a[], int size)
{

}

void BubbleSort(int a[], int size)
{
    unsigned char i,j;
    int temp;
    for(i = 0; i < size; i++)
    {
        for(j = i; j < size; j++)
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
    printf("%s:",title);
    for(i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void main()
{
    int index, a[ARRAY_SIZE];
    for(index = 0; index < ARRAY_SIZE; index++)
    {
        a[index] = rand() % 100;
    }
    PrintArray(a, ARRAY_SIZE, "Origin");
    BubbleSort(a, ARRAY_SIZE);    
    PrintArray(a, ARRAY_SIZE, "BubbleSort");
}