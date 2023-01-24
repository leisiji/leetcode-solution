#include "../src/listnode.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head);
};

ListNode* Solution::reverseList(ListNode* head)
{
    ListNode *node = head;
    ListNode *prev = nullptr;

    while (node != nullptr) {
        auto next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }

    return prev;
}

