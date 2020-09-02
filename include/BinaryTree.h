#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include<iostream>
using namespace std;

template<typename elemtype>
struct BinaryTree;

template<typename vartype>
struct BTnode
{
    friend struct BinaryTree<vartype>;
    BTnode(const vartype&);
    ~BTnode();
    void insert_value(const vartype&);
    void remove_value(const vartype&, BTnode*&);
    static void lchild_leaf(BTnode*, BTnode*);
    void preorder(BTnode*, ostream&) const;
    void inorder(BTnode*, ostream&) const;
    void postorder(BTnode*, ostream&) const;

    private:
    void assign_child(BTnode*&, vartype);
    ostream& display_value(vartype, ostream&) const;
    private:
    vartype _value;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};

template<typename vartype>
inline BTnode<vartype>::BTnode(const vartype &value) : _value(value),_cnt(1),_lchild(0),_rchild(0)
{

}

template<typename vartype>
inline BTnode<vartype>::~BTnode()
{
    
}

template<typename vartype>
void BTnode<vartype>::assign_child(BTnode*& child, vartype value)
{
    if(!child)
        child = new BTnode<vartype>(value);
    else
        child->insert_value(value); 
}

template<typename vartype>
void BTnode<vartype>::insert_value(const vartype &value)
{
    if(value == _value)
    {
        _cnt++;
        return;
    }
    if(value < _value)
    {
        assign_child(_lchild, value);
    }
    else
    {
        assign_child(_rchild, value);
    }    
}

template<typename vartype>
void BTnode<vartype>::lchild_leaf(BTnode *leaf, BTnode *subtree)
{
    while(subtree->_lchild)
    {
        subtree = subtree->_lchild;
    }
    subtree->_lchild = leaf;
}

template<typename vartype>
void BTnode<vartype>::remove_value(const vartype& value, BTnode*& prev)
{
    if(value > _value)
    {
        if(!_rchild)
            return;
        else
            _rchild->remove_value(value, _rchild);
    }
    else if(value < _value)
    {
        if(!_lchild)
            return;
        else
            _lchild->remove_value(value, _lchild);     
    }
    else
    {
        //找到了这个节点，重置节点，删除拆下来的节点
        if(_rchild)
        {
            prev = _rchild;
            if(_lchild)
            {
                if(!prev->_lchild)
                    prev->_lchild = _lchild;
                else
                    BTnode<vartype>::lchild_leaf(_lchild, prev->_lchild);              
            }
        }
        else
            prev = _lchild;
        delete this;
    }    
}

template<typename vartype>
void BTnode<vartype>::preorder(BTnode *node, ostream &os) const
{
    if(node)
    {
        display_value(node->_value, os);
        preorder(node->_lchild, os);
        preorder(node->_rchild, os);
    }
}

template<typename vartype>
void BTnode<vartype>::inorder(BTnode *node, ostream &os) const
{
    if(node)
    {
        inorder(node->_lchild, os);
        display_value(node->_value, os);
        inorder(node->_rchild, os);
    }
}

template<typename vartype>
void BTnode<vartype>::postorder(BTnode *node, ostream &os) const
{
    if(node)
    {
        postorder(node->_lchild, os);
        postorder(node->_rchild, os);
        display_value(node->_value, os);
    }
}

template<typename vartype>
ostream& BTnode<vartype>::display_value(vartype value, ostream &os) const
{
    os<< value<<" ";
    return os;
}

//**********************************************************//
template<typename elemtype>
inline ostream& operator<<(ostream &os, const BinaryTree<elemtype> &bt)
{
    os<<"Tree: "<<endl;
    bt.print(os);
    return os;
}

template<typename elemtype>
struct BinaryTree
{
    template<typename T>
    friend ostream& operator<<(ostream&, const BinaryTree<T>&);
    BinaryTree();
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);

    bool empty();
    void clear();
    void insert(const elemtype&);
    void remove(const elemtype&);
    void preorder();
    void inorder();
    void postorder();

    private:
    void copy(BTnode<elemtype>*tar, BTnode<elemtype>*src);
    void remove_root();
    void clear(BTnode<elemtype>*);
    void print(ostream&) const;

    private:
    BTnode<elemtype> *_root;
};

template<typename elemtype>
inline BinaryTree<elemtype>::BinaryTree() : _root(0)
{

}

template<typename elemtype>
inline BinaryTree<elemtype>::BinaryTree(const BinaryTree &rhs)
{
    copy(_root, rhs._root);
}

template<typename elemtype>
inline BinaryTree<elemtype>::~BinaryTree()
{
    clear();
}

template<typename elemtype>
inline BinaryTree<elemtype>& BinaryTree<elemtype>::operator=(const BinaryTree &rhs)
{
    if(this != &rhs)
    {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}

template<typename elemtype>
inline void BinaryTree<elemtype>::copy(BTnode<elemtype>*tar, BTnode<elemtype>*src)
{
    if(src)
    {
        tar = new BTnode<elemtype>(src->_value);
        if(src->lchild) copy(tar->lchild, src->lchild);
        if(src->rchild) copy(tar->rchild, src->rchild);
    }
}

template<typename elemtype>
inline bool BinaryTree<elemtype>::empty()
{
    return 0 == _root;
}

template<typename elemtype>
inline void BinaryTree<elemtype>::clear()
{
    if(_root)
    {
        clear(_root);
        _root = 0;
    }
}

template<typename elemtype>
inline void BinaryTree<elemtype>::clear(BTnode<elemtype>* node)
{
    if(node)
    {
        clear(node->_lchild);
        clear(node->_rchild);
        delete node;
    }
}

template<typename elemtype>
inline void BinaryTree<elemtype>::insert(const elemtype &elem)
{
    if(!_root)
        _root = new BTnode<elemtype>(elem);
    else
        _root->insert_value(elem);    
}

template<typename elemtype>
inline void BinaryTree<elemtype>::remove(const elemtype &elem)
{
    if(_root)
    {
        if(_root->_value == elem)
            remove_root();
        else
            _root->remove_value(elem, _root);        
    }    
}

template<typename elemtype>
inline void BinaryTree<elemtype>::remove_root()
{
    if(!_root) return;
    BTnode<elemtype> *tmp = _root;
    if(_root->_rchild)
    {
        _root = _root->_rchild;
        if(!_root->_lchild)
            //右子树没有左子树，直接将根节点左子树挂上
            _root->_lchild = tmp->_lchild;
        else
            //右子树有左子树，遍历寻找左子树中为空的左子节点，挂上
            BTnode<elemtype>::lchild_leaf(tmp->_lchild, _root->_lchild);
    }
    else
        _root = _root->_lchild;
    delete tmp;
}

template<typename elemtype>
inline void BinaryTree<elemtype>::preorder()
{
    _root->preorder(_root, cout);
}

template<typename elemtype>
inline void BinaryTree<elemtype>::inorder()
{
    _root->inorder(_root, cout);
}

template<typename elemtype>
inline void BinaryTree<elemtype>::postorder()
{
    _root->postorder(_root, cout);
}

template<typename elemtype>
inline void BinaryTree<elemtype>::print(ostream &os) const
{
    _root->preorder(_root, os);
}

#endif