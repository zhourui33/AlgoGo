#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct Array
{
    int *data;
    int len;
    int usedSize;
}Array;

void CreateArray(Array *array, int len);
void InsertAfter(Array *array, int index);
void DeleteAfter(Array *array, int index);

#endif