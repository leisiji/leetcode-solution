#include "listnode.hpp"

class Solution
{
public:
    ListNode *middleNode(ListNode *head);
};

ListNode *Solution::middleNode(ListNode *head)
{
    ListNode *fast = head, *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
