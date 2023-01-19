#include "listnode.hpp"

class Solution
{
public:
    ListNode *partition(ListNode *head, int x);
};

ListNode *Solution::partition(ListNode *head, int x)
{
    ListNode lroot, rroot;
    ListNode *lnode = &lroot, *rnode = &rroot;
    ListNode *node = head;

    while (node != nullptr) {
        auto next = node->next;
        if (node->val < x) {
            lnode->next = node;
            lnode = node;
        } else {
            rnode->next = node;
            rnode = node;
        }
        node = next;
    }
    lnode->next = rroot.next;
    rnode->next = nullptr;

    return lroot.next;
}

int main(int argc, char *argv[])
{
    auto a = ListNode::vec_to_list({1,4,3,2,5,2});
    Solution s;
    std::cout << s.partition(a, 3) << std::endl;
    return 0;
}
