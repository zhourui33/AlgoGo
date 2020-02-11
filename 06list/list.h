#ifndef _LIST_H_
#define _LIST_H_

#ifdef __cplusplus_
extern "C"{
#endif

typedef struct LIST_ELEM
{
    struct LIST_ELEM *next;
    struct LIST_ELEM *prev;
}LIST_ELEM, *LIST_HANDLE;

#define LIST_REMOVE(handle) LIST_CREATE(handle)

void LIST_CREATE(LIST_HANDLE handle);
void LIST_INSERT_HEAD(LIST_HANDLE handle, LIST_ELEM *elem);
void LIST_INSERT_TAIL(LIST_HANDLE handle, LIST_ELEM *elem);
LIST_ELEM* LIST_GET_TAIL(LIST_HANDLE handle);

#ifdef _cplusplus_
}
#endif

#endif