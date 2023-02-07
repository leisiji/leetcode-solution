#include "listnode.hpp"

class Solution {
public:
    ListNode *detectCycle(ListNode *head);
};

ListNode *Solution::detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    do {
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}
