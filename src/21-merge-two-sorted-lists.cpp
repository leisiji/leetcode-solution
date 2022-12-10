#include <algorithm>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

    ListNode head1(5);
    head1.next = new ListNode(6);
    head1.next->next = new ListNode(7);
    head1.next->next->next = new ListNode(8);
    head1.next->next->next->next = new ListNode(9);

    ListNode head2(1);
    head2.next = new ListNode(2);
    head2.next->next = new ListNode(3);
    head2.next->next->next = new ListNode(4);
    head2.next->next->next->next = new ListNode(5);

    auto h2 = s.mergeTwoLists(&head1, &head2);

    std::cout << "[";
    while (h2 != nullptr) {
        std::cout << h2->val << ",";
        h2 = h2->next;
    }
    std::cout << "]" << std::endl;

    return 0;
}
