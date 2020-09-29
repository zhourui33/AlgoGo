#ifndef SKIP_LIST_HPP
#define SKIP_LIST_HPP

#include <random>
#include <iostream>
#include <ctime>

const int MAX_LEVEL = 6;


struct Node
{
    Node()
    {
        data = -1;
        maxLevel = 1;
        for(int i = 0; i < MAX_LEVEL; ++i)
        {
            forward[i] = nullptr;
        }
    }
    int data;
    int maxLevel;
    Node* forward[MAX_LEVEL];
};

struct SkipList
{
    SkipList()
    {
        countLevel = 1;
        head = new Node();
    }
    Node* find(int value);
    void insert(int value);
    void erase(int value);
    void print();

    private:
    int randomLevel();
    private:
    int countLevel;
    Node* head;
};

Node* SkipList::find(int value)
{
    Node * p = head;
    for(int i = countLevel - 1; i >= 0; i--)
    {
        while(p->forward[i] && p->forward[i]->data < value)
        {
            p = p->forward[i];
        }
    }
    p = p->forward[0];
    if(p && p->data == value)
    {
        return p;
    }
    else
    {
        return nullptr;
    }
    
}

void SkipList::insert(int value)
{
    Node *newNode = new Node();
    newNode->maxLevel = randomLevel();
    newNode->data = value;
    Node* update[MAX_LEVEL] = {head};

    Node* p = head;
    // find path nodes, save to update[]
    for(int i = newNode->maxLevel -1; i >= 0; --i)
    {
        while(p->forward[i] && p->forward[i]->data < value)
        {
            p = p->forward[i];
        }
        update[i] = p;
    }
    // insert newnode after update
    for(int i = 0; i < newNode->maxLevel; ++i)
    {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;

    }

    if(countLevel < newNode->maxLevel)
    {
        countLevel = newNode->maxLevel;
    }
}

void SkipList::erase(int value)
{
    Node* update[MAX_LEVEL];
    Node *p = head;

    for(int i = countLevel-1; i >= 0; --i)
    {
        while(p->forward[i] && p->forward[i]->data < value)
        {
            p = p->forward[i];
        }
        update[i] = p;
    }

    if(p->forward[0] && p->forward[0]->data == value)
    {
        Node* todel = nullptr;
        for(int i = countLevel-1; i >= 0; --i)
        {
            if(update[i]->forward[i] && update[i]->forward[i]->data == value)
            {
                todel = update[i]->forward[i];
                update[i]->forward[i] = update[i]->forward[i]->forward[i];
            }
        }
        if(todel)
        {
            delete todel;
        }
    }

    while(countLevel > 1 && head->forward[countLevel] == nullptr)
    {
        countLevel--;
    }
}

int SkipList::randomLevel()
{
    int level = 0;
    static int cnt = 100;
    std::default_random_engine e(time(nullptr)+cnt);
    std::uniform_int_distribution<int> dirtribution(1, 100);

    for(int i = 0; i < MAX_LEVEL; ++i)
    {
        if(dirtribution(e)%2 == 1)
        {
            level++;
        } 
    }
    cnt+=98;
    return level;
}

void SkipList::print()
{
    std::cout<<"*****"<<std::endl;
    for(int i = 0; i < countLevel; ++i)
    {
        Node *p = head->forward[i];
        std::cout<<"level["<<i<<"] :";
        while(p)
        {
            std::cout<< p->data <<" ";
            p = p->forward[i];
        }
        std::cout<<std::endl;
    }
}

#endif