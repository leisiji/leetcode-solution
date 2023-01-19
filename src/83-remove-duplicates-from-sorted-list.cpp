#include "listnode.hpp"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head);
};

ListNode *Solution::deleteDuplicates(ListNode *head)
{
    ListNode root;
    ListNode *cur = &root;
    ListNode *node = head;

    while (node != nullptr) {
        auto next = node->next;
        if (next != nullptr && next->val == node->val) {
            node = next;
            continue;
        }
        cur->next = node;
        cur = node;
        node = node->next;
    }

    return root.next;
}

int main(int argc, char *argv[])
{
    auto root = ListNode::vec_to_list({1, 1, 2, 3, 3});
    Solution s;
    std::cout << s.deleteDuplicates(root) << std::endl;
    return 0;
}
