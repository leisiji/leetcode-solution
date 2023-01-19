#include <iostream>
#include <vector>

#include "listnode.hpp"

class Solution
{
public:
    ListNode *reverseList(ListNode *head);
};

ListNode *Solution::reverseList(ListNode *head)
{
    ListNode *next;
    ListNode *cur = head;
    ListNode *prev = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

void test(std::vector<int> &a)
{
    auto l = ListNode::vec_to_list(a);
    Solution s;
    auto o = s.reverseList(l);
    std::cout << o << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {1};

    test(a);
    test(b);

    return 0;
}
