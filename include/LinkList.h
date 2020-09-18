/**

TODO: 
1.linklist 实现编译通过 ok
2.实现回文判断 palindrome ok
3.实现LRU缓存淘汰队列 ok
4.链表逆置 ok
5.链表中环的检测 ok
6.两个有序链表合并 ok
7.删除链表倒数第N个节点 ok
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
LinkNode<T>* copyNode(LinkNode<T>*);
template<typename T>
LinkNode<T>* MergeLinkList(LinkNode<T>*, LinkNode<T>*);
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
    LinkList(LinkNode<T>*);
    virtual ~LinkList();

    bool empty() const;
    void insert(const T&);
    void remove(LinkNode<T>*);
    void removeLastN(unsigned int);
    LinkList<T>& reverse();
    LinkNode<T>* getMidNode();
    bool isExistLoop();
    bool isPalindrome();
    LinkNode<T>* find(T data);
    bool operator==(const LinkList<T>&) const;

    void show() const;

    private:
    void destroy();
    LinkNode<T>* reverseNode(LinkNode<T>*);
    public:
    LinkNode<T> *_head;
};

template<typename T>
inline LinkList<T>::LinkList()
{
    _head = new LinkNode<T>;
    _head->next = nullptr;
}

template<typename T>
inline LinkList<T>::LinkList(LinkNode<T> *rhs)
{
    _head = new LinkNode<T>;
    _head->next = rhs;
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

template<typename T>
LinkNode<T>* LinkList<T>::find(T data)
{
    LinkNode<T> *node = _head->next;
    while(node)
    {
        if(node->data == data)
        {
            return node;
        }
        node = node->next;
    }
    return nullptr;
}

template<typename T>
void LinkList<T>::remove(LinkNode<T>* node)
{
    LinkNode<T> *loop = _head->next, 
                *prev = _head;
    while(loop)
    {
        if(loop == node)
        {
            prev->next = loop->next;
            delete node;
            node = nullptr;
            break;
        }
        prev = loop;
        loop = loop->next;
    }
}

template<typename T>
void LinkList<T>::removeLastN(unsigned int n)
{
    LinkNode<T> *fast = _head->next,
                *slow = _head->next;
    while(fast && (n > 0))
    {
        fast = fast->next;
        n--;
    }
    if(n > 0) exit(1);
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    remove(slow);
}

template<typename T>
LinkNode<T>* copyNode(LinkNode<T>* rhs)
{
    LinkNode<T> *temp = new LinkNode<T>;
    temp->data = rhs->data;
    temp->next = rhs->next;
    return temp;
}

template<typename T>
LinkNode<T>* MergeLinkList(LinkNode<T> *lhs, LinkNode<T> *rhs)
{
    LinkNode<T> *result = new LinkNode<T>;
    LinkNode<T> *p = result;
    while(lhs && rhs)
    {
        if(lhs->data <= rhs->data)
        {
            p->next = copyNode(lhs);
            lhs = lhs->next;
        }
        else
        {
            p->next = copyNode(rhs);
            rhs = rhs->next;
        }
        p = p->next;   
    }
    while(lhs)
    {
        p->next = copyNode(lhs);
        lhs = lhs->next;
    }
    while(rhs)
    {
        p->next = copyNode(rhs);
        rhs = rhs->next;
    }

    return result->next;
}

#endif