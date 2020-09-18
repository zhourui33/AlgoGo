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
}

TEST(test_link_list, should_remove_last_n_as_expect)
{
    LinkList<string> month, expect;
    month.insert("2000");
    month.insert("2001");
    month.insert("2002");
    month.insert("2003");
    month.insert("2004");
    month.insert("2005");
    month.insert("2006");
    month.removeLastN(2);

    expect.insert("2000");
    expect.insert("2002");
    expect.insert("2003");
    expect.insert("2004");
    expect.insert("2005");
    expect.insert("2006");
    
    // before:2006 -> 2005 -> 2004 -> 2003 -> 2002 -> 2001 -> 2000
    // after: 2006 -> 2005 -> 2004 -> 2003 -> 2002 -> 2000
    ASSERT_TRUE(month == expect);
}

TEST(test_link_list, should_do_nothing_when_remove_last_0)
{
    LinkList<string> month, expect;
    month.insert("2000");
    month.insert("2001");
    month.insert("2002");
    month.insert("2003");
    month.insert("2004");
    month.insert("2005");
    month.insert("2006");
    month.removeLastN(0);

    expect.insert("2000");
    expect.insert("2001");
    expect.insert("2002");
    expect.insert("2003");
    expect.insert("2004");
    expect.insert("2005");
    expect.insert("2006");
    
    ASSERT_TRUE(month == expect);
}

TEST(test_link_list, should_merge_two_linklist_by_increase_order)
{
    LinkList<int> first, second;
    first.insert(9);
    first.insert(7);
    first.insert(5);
    first.insert(3);
    first.insert(1);
    second.insert(10);
    second.insert(8);
    second.insert(6);
    second.insert(4);
    second.insert(2);

    LinkList<int> expect; // expect 1->2->3->4->5->6->7->8->9->10
    expect.insert(10);
    expect.insert(9);
    expect.insert(8);
    expect.insert(7);
    expect.insert(6);
    expect.insert(5);
    expect.insert(4);
    expect.insert(3);
    expect.insert(2);
    expect.insert(1);

    LinkNode<int> *merge = MergeLinkList(first._head->next, second._head->next);
    LinkList<int> result(merge);

    ASSERT_TRUE(result == expect);
}
