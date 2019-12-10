#include<stdio.h>
#include<stdlib.h>
#include"list.h"


void InitLinkList(LinkList *l)
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
    l->head = head;
}

void InsertNode(LinkList *l, int num)
{
    struct Node *curNode = l->head;
    struct Node *insNode;

    insNode = (struct Node *)malloc(sizeof(struct Node));
    insNode->data = num;
    insNode->next = NULL;

    while(curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    curNode->next = insNode;
}

void PrintLinkList(LinkList *l)
{
    struct Node *curNode = l->head;
    while(curNode->next != NULL)
    {
        printf("%d->", curNode->data);
        curNode = curNode->next;
    }
    printf("NULL\n");

}
int main()
{
    LinkList *l;
    printf("1");
    InitLinkList(l);
    printf("2");
    InsertNode(l, 1);
    InsertNode(l, 2);
    InsertNode(l, 3);
    InsertNode(l, 4);
    InsertNode(l, 5);
    printf("3");
    PrintLinkList(l);
}