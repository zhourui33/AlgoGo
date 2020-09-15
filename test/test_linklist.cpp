#include <gtest/gtest.h>
#include "LinkList.h"
#include <string>

using namespace std;

TEST(test_link_list, should_link_list_int_insert_as_expect)
{
    LinkList<int> mon;
    mon.insert(1);

    ASSERT_FALSE(mon.empty());
}

TEST(test_link_list, should_link_list_string_insert_as_expect)
{
    LinkList<string> mon;
    mon.insert("january");
    
    ASSERT_FALSE(mon.empty());
}

TEST(test_link_list, should_same_link_list_cmp_equal)
{
    LinkList<int> left, right;
    left.insert(1);
    right.insert(1);

    ASSERT_TRUE(left == right);
}

TEST(test_link_list, should_link_list_reverse_as_expect)
{
    LinkList<int> origin, reverse;
    origin.insert(1);
    origin.insert(2);
    origin.insert(3);

    reverse.insert(3);
    reverse.insert(2);
    reverse.insert(1);
    ASSERT_TRUE(origin.reverse() == reverse);
}

TEST(test_link_list, should_detect_loop_when_link_list_exist_loop)
{
    LinkList<int> noloop;
    noloop.insert(1);
    noloop.insert(2);

    ASSERT_FALSE(noloop.isExistLoop());
}

TEST(test_link_list, should_get_mid_node_when_list_has_odd_nodes)
{
    LinkList<string> oddnodes;
    oddnodes.insert("one");
    oddnodes.insert("two");
    oddnodes.insert("three");
    oddnodes.insert("four");
    oddnodes.insert("five");

    LinkNode<string> *midnode = oddnodes.getMidNode();
    ASSERT_TRUE(midnode->data == "three");
}

TEST(test_link_list, should_get_mid_node_when_list_has_even_nodes)
{
    LinkList<string> evennodes;
    evennodes.insert("one");
    evennodes.insert("two");
    evennodes.insert("three");
    evennodes.insert("four");
    evennodes.insert("five");
    evennodes.insert("six");

    LinkNode<string> *midnode = evennodes.getMidNode();
    ASSERT_TRUE(midnode->data == "three");
}

TEST(test_link_list, should_detect_link_list_even_nodes_is_palindrome)
{
    LinkList<string> palindrome;
    palindrome.insert("did");
    palindrome.insert("anna");
    palindrome.insert("say");
    palindrome.insert("say");
    palindrome.insert("anna");
    palindrome.insert("did");
    
    ASSERT_TRUE(palindrome.isPalindrome());
}

TEST(test_link_list, should_detect_link_list_odd_nodes_is_palindrome)
{
    LinkList<string> palindrome;
    palindrome.insert("so");
    palindrome.insert("do");
    palindrome.insert("I");
    palindrome.insert("do");
    palindrome.insert("so");
    
    ASSERT_TRUE(palindrome.isPalindrome());
}

TEST(test_link_list, should_detect_link_list_is_not_palindrome)
{
    LinkList<string> palindrome;
    palindrome.insert("i");
    palindrome.insert("am");
    palindrome.insert("not");
    palindrome.insert("palindrome");
    
    ASSERT_FALSE(palindrome.isPalindrome());
    palindrome.show();
}
