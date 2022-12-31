#include <iostream>
#include <iterator>
#include <vector>

#include "listnode.h"

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k);
};

ListNode *Solution::reverseKGroup(ListNode *head, int k)
{
    ListNode *cur = head;
    int len = 0;

    while (cur != nullptr) {
        len++;
        cur = cur->next;
    }

    /* 翻转的区域是 [p0->next, tail] */
    ListNode dummy(0, head);
    ListNode *prev = &dummy, *next, *p0 = &dummy, *tail = head;

    cur = p0->next;

    while (len >= k) {
        len -= k;

        for (int i = 0; i < k; i++) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        p0->next = prev;
        tail->next = cur;
        p0 = tail;
        tail = cur;
    }

    return dummy.next;
}

void test(std::vector<int> &a)
{
    auto *l = ListNode::vec_to_list(a);
    Solution s;
    auto ret = s.reverseKGroup(l, 2);

    std::cout << ret << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    test(a);
    std::vector<int> b = {1, 2, 3, 4, 5, 6, 7};
    test(b);
    return 0;
}
