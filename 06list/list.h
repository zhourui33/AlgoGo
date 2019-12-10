#ifndef _LIST_H_
#define _LIST_H_

struct Node
{
    int data;
    struct Node *next;
};

typedef struct LinkList
{
    struct Node *head;
}LinkList;

void InitLinkList(LinkList *l);
void InsertNode(LinkList *l, int num);
void PrintLinkList(LinkList *l);

#endif