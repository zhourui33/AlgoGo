#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"array.h"

void InitArray(Array *a)
{
    a->data = NULL;
    a->size = 0;
    a->used = 0;
}

void CreateArray(Array *a, int size)
{
    a->data = (int *)malloc(size * sizeof(int));
    a->size = size;
    a->used = 0;
    memset(a->data, 0, a->size);
}

void Insert(Array *a, int value)
{
    if(a->used >= a->size)
        return;
    a->data[a->used] = value;
    a->used++;
}

void Delete(Array *a, int index)
{
    if(index >= a->used)
        return;
    for(int i = index+1; i < a->used; i++)
    {
        a->data[i-1] = a->data[i];
    }
    a->used--;
}

void Dump(Array *a)
{
    for(int i = 0; i < a->used; i++)
    {
        printf("%d:", a->data[i]);
    }
    printf("\n");
}