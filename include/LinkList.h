/**

TODO: 
1.linklist 实现编译通过 ok
2.实现回文判断 palindrome ok
3.实现LRU缓存淘汰队列
4.链表逆置 ok
5.链表中环的检测 ok
6.两个有序链表合并
7.删除链表倒数第N个节点
8.求链表中间节点 ok

**/

#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <iostream>
template<typename T>
struct LinkNode;
template<typename T>
struct LinkList;

template<typename T>
struct LinkNode
{
    T data;
    LinkNode *next;
};

template<typename T>
struct LinkList
{
    LinkList();
    virtual ~LinkList();

    bool empty() const;
    void insert(const T&);
    LinkList<T>& reverse();
    LinkNode<T>* getMidNode();
    bool isExistLoop();
    bool isPalindrome();
    bool operator==(const LinkList<T>&) const;

    void show() const;

    private:
    void destroy();
    LinkNode<T>* reverseNode(LinkNode<T>*);
    private:
    LinkNode<T> *_head;
};

template<typename T>
inline LinkList<T>::LinkList()
{
    _head = new LinkNode<T>;
    _head->next = nullptr;
}

template<typename T>
inline LinkList<T>::~LinkList()
{
    destroy();
}

template<typename T>
inline void LinkList<T>::destroy()
{
    while(_head)
    {
        LinkNode<T> *temp = _head->next;
        delete _head;
        _head = temp;
    }
}

template<typename T>
void LinkList<T>::insert(const T &data)
{
    LinkNode<T> *node = new LinkNode<T>;
    node->data = data;
    node->next = _head->next;
    _head->next = node;
}

template<typename T>
void LinkList<T>::show() const
{
    LinkNode<T> *temp = _head->next;
    while(temp)
    {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

template<typename T>
LinkNode<T>* LinkList<T>::reverseNode(LinkNode<T>* node)
{
    LinkNode<T> *cur = node, 
                *prev = nullptr, 
                *next = nullptr;
    while(cur)
    {
        next = cur->next;   // 1. save next node
        cur->next= prev;    // 2. reverse cur node
        prev = cur;         // 3. move prev and cur ahead
        cur = next; 
    }
    return prev;
}

/*
    [head|next]->[A|next]->[B|next]->[C|null]
*/
template<typename T>
LinkList<T>& LinkList<T>::reverse()
{
    _head->next = reverseNode(_head->next);
    return *this;
}

template<typename T>
bool LinkList<T>::operator==(const LinkList<T>& rhs) const
{
    if(empty() || rhs.empty()) 
    {
        return false;
    }
    
    LinkNode<T> *rnode = _head->next, 
                *lnode = rhs._head->next;
    while(lnode && rnode)
    {
        if(lnode->data != rnode->data)
        {
            return false;
        }
        lnode = lnode->next;
        rnode = rnode->next;
    }
    if(lnode || rnode)
    {
        return false;
    }
    return true;
}

template<typename T>
bool LinkList<T>::empty() const
{
    return (_head->next == nullptr);
}

template<typename T>
bool LinkList<T>::isExistLoop()
{
    if(empty())
    {
        return false;
    }
        
    LinkNode<T> *fast = _head, *slow = _head;
    bool loopExist = false;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            loopExist = true;
            break;
        }
    }
    return loopExist;
}


template<typename T>
bool LinkList<T>::isPalindrome()
{
    if(empty())
    {
        return false;
    }

    LinkNode<T> *leftHalf = _head->next,
                *rightHalf = getMidNode(),                  // 1. find midnode in list
                *rightHalfReverse = reverseNode(rightHalf); // 2. reverse list after midnode
    LinkNode<T> *temp = rightHalfReverse;
    while(temp)
    {
        if(leftHalf->data != temp->data)                    //3. compare lefthalf and reversed righthalf list
        {
            break;
        }
        temp = temp->next;
        leftHalf = leftHalf->next;
    }
    rightHalf = reverseNode(rightHalfReverse);              //4. recover right half linklist to origin
    return (temp == nullptr);
}

template<typename T>
LinkNode<T>* LinkList<T>::getMidNode()
{
    if(empty() || isExistLoop())
    {
        exit(1);
    }
    LinkNode<T> *fast = _head->next, 
                *slow = _head->next;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;  // midnode position ==> (num/2)+1
}

#endif