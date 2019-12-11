#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct Array
{
    int *data;
    int size;
    int used;
}Array;

void InitArray(Array *a);
void CreateArray(Array *a, int size);
void Insert(Array *a, int value);
void Delete(Array *a, int index);
void Dump(Array *a);

#endif