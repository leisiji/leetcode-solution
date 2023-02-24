#include <cstdlib>

#include "listnode.hpp"

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};

static inline ListNode *ltail(ListNode *head, int *len)
{
    ListNode *cur, *tail = nullptr;

    cur = head;
    while (cur != nullptr) {
        tail = cur;
        (*len)++;
        cur = cur->next;
    }

    return tail;
}

ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int len1 = 0, len2 = 0;
    ListNode *tail1 = ltail(headA, &len1), *tail2 = ltail(headB, &len2);

    if (tail1 != tail2) {
        return nullptr;
    }

    // cur1 始终是较长的那个链表
    ListNode *cur1, *cur2;
    if (len1 > len2) {
        cur1 = headA;
        cur2 = headB;
    } else {
        cur1 = headB;
        cur2 = headA;
    }

    int step = abs(len1 - len2);
    while (cur1 != nullptr && step > 0) {
        cur1 = cur1->next;
        step--;
    }

    while (cur1 != nullptr && (cur1 != cur2)) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    return cur1;
}
