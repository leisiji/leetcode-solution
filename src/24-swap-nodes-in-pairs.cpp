#include "listnode.hpp"

#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 */

class Solution
{
public:
    ListNode* swapPairs(ListNode* head);
};

ListNode* Solution::swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* node1 = head;
    ListNode* node2 = head;
    ListNode* node3;
    ListNode* new_head = head->next;

    while (node2 != nullptr) {
        node3 = node2->next;
        if (node3 != nullptr) {
            node1->next = node3;
            node2->next = node3->next;
            node3->next = node2;
            node1 = node2;
        }
        node2 = node2->next;
    }

    return new_head;
}

void test(vector<int> vec)
{
    Solution s;
    auto head = ListNode::vec_to_list(vec);
    auto ans = s.swapPairs(head);
    cout << ans << endl;
}

int main(int argc, char* argv[])
{
    test({1, 2, 3, 4});
    test({1, 2, 3, 4, 5});
    test({1, 2, 3, 4, 5, 6});
    return 0;
}
