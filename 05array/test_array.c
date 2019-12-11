#include"array.h"

int main()
{
    Array arr;

    InitArray(&arr);
    CreateArray(&arr, 10);
    Insert(&arr, 1);
    Insert(&arr, 3);
    Insert(&arr, 5);
    Insert(&arr, 7);
    Insert(&arr, 9);
    Dump(&arr);
    Delete(&arr, 3);
    Dump(&arr);

    return 0;
}