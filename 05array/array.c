#include<stdlib.h>
#include"array.h"

void CreateArray(Array *array, int len)
{
    array->data = (int *)malloc(len);
    array->len = len;
    memset(array->data, 0, array->len);
}

void Insert(Array *array, int value)
{
    int idx;
    int *dest;
    if(index > array->len)
    {
        return;
    }
    dest = array->data + index * sizeof(int);
    *dest = value;
}
void Delete(Array *array, int index);