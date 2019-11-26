#include"list.h"

List::List()
{
    head->data = 0;
    head->next = nullptr;
}

List::~List()
{
    head->data = 0;
    head->next = nullptr;
}

void List::Add(int data)
{
    Node *last;
    last = head;
    while(last->next != nullptr)
    {
        last = last->next;
    }
    last->next = node;
}