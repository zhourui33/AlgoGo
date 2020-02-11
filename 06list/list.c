#include "list.h"

void LIST_CREATE(LIST_HANDLE handle)
{
    handle->next = handle;
    handle->prev = handle->next;
}

void LIST_INSERT_HEAD(LIST_HANDLE handle, LIST_ELEM *elem)
{
    elem->next = handle;
    elem->prev = handle->prev;
    handle->prev->next = elem;
    handle->prev = elem;
}

void LIST_INSERT_TAIL(LIST_HANDLE handle, LIST_ELEM *elem)
{
    elem->next = handle->next;
    elem->prev = handle;
    handle->next->prev = elem;
    handle->next = elem;
}

LIST_ELEM* LIST_GET_TAIL(LIST_HANDLE handle)
{
    
}