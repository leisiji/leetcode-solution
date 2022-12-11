#include <algorithm>
#include <iostream>

#include "listnode.h"

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if (nullptr == list1 && nullptr == list2) {
        return nullptr;
    }

    ListNode *node1 = list1, *node2 = list2;
    ListNode* head;
    ListNode** res = &head;

    while (node1 != nullptr && node2 != nullptr) {
        *res = new ListNode();
        if (node1->val < node2->val) {
            (*res)->val = node1->val;
            node1 = node1->next;
        } else {
            (*res)->val = node2->val;
            node2 = node2->next;
        }
        res = &((*res)->next);
    }

    while (node1 != nullptr) {
        *res = new ListNode();
        (*res)->val = node1->val;
        node1 = node1->next;
        res = &((*res)->next);
    }
    while (node2 != nullptr) {
        *res = new ListNode();
        (*res)->val = node2->val;
        node2 = node2->next;
        res = &((*res)->next);
    }

    return head;
}

int main(int argc, char* argv[])
{
    Solution s;

    auto head1 = ListNode::vec_to_list({5, 6, 7, 8, 9});
    auto head2 = ListNode::vec_to_list({1, 2, 3, 4, 5});

    auto h2 = s.mergeTwoLists(head1, head2);

    std::cout << h2 << std::endl;

    return 0;
}
