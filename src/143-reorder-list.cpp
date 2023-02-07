#include "listnode.hpp"

#include <iostream>

using namespace std;

class Solution
{
public:
    void reorderList(ListNode *head);
};

void Solution::reorderList(ListNode *head)
{
    // 找到链表的中间节点
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 反转链表
    ListNode *middle = slow;
    ListNode *node2 = middle;
    ListNode *prev = nullptr;

    while (node2 != nullptr) {
        auto next = node2->next;
        node2->next = prev;
        prev = node2;
        node2 = next;
    }

    // 合并链表
    ListNode *node1 = head;
    node2 = prev;
    while (node1 != middle) {
        auto next1 = node1->next;
        auto next2 = node2->next;
        node1->next = node2;
        node2->next = next1;
        node1 = next1;
        node2 = next2;
    }

    if (middle != nullptr) {
        middle->next = nullptr;
    }
}

int main (int argc, char *argv[])
{
    ListNode *node = ListNode::vec_to_list({1,2,3,4,5,6,7,8});
    Solution s;
    s.reorderList(node);
    cout << node << endl;
    return 0;
}
