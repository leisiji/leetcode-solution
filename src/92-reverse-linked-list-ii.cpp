#include <cstdlib>
#include <iostream>
#include <vector>

#include "listnode.hpp"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right);
};

/* 1 <= left <= right <= n */
ListNode *Solution::reverseBetween(ListNode *head, int left, int right)
{
    if (left == right) {
        return head;
    }

    ListNode dummy(0, head);
    ListNode *p0 = &dummy;

    for (int i = 0; i < (left - 1); i++) {
        p0 = p0->next;
    }

    ListNode *cur = p0->next;
    ListNode *prev = p0, *next, *tail = cur;

    for (int i = 0; i < (right - left + 1); i++) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    p0->next = prev;
    tail->next = cur;

    return dummy.next;
}

void test(std::vector<int> &a, int left, int right)
{
    Solution s;
    auto *head = ListNode::vec_to_list(a);
    auto ret = s.reverseBetween(head, left, right);
    std::cout << ret << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    test(a, 2, 6);
    test(a, 1, a.size());
    test(a, 2, 2);
    return 0;
}
