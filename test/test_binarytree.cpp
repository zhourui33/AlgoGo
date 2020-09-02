#include <gtest/gtest.h>
#include "BinaryTree.h"
#include <string>

using namespace std;

TEST(test_binary_tree, test_traval)
{
    BinaryTree<string> bs;
    bs.insert("Piglet");
    bs.insert("Eeyore");
    bs.insert("Roo");
    bs.insert("Tigger");
    bs.insert("Chris");
    bs.insert("Pooh");
    bs.insert("Kanga");

    cout<<"Preorder traversal:\n";
    bs.preorder();
    bs.remove("Piglet");
    cout<<"\n\nPreorder traversal after Piglet removal:\n";
    bs.preorder();
    bs.remove("Eeyore");
    cout<<"\n\nPreorder traversal after Eeyore removal:\n";
    bs.preorder();
    cout<<"\nfunction output:\n"<<bs<<endl;
}