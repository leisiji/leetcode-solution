#include <iostream>

#include "listnode.h"

using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head);
};

// 把所有重复数字的节点删掉
ListNode *Solution::deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode h;
    ListNode *cur = &h, *node = head;
    int prev_val = head->val;

    while (node != nullptr) {
        // 跳过所有的相同数字
        auto next = node->next;
        if (next != nullptr && next->val == node->val) {
            next = next->next;
            while (next != nullptr && next->val == node->val) {
                next = next->next;
            }
            cur->next = nullptr;
            node = next;
            continue;
        }
        cur->next = node;
        cur = node;
        node = next;
    }

    return h.next;
}

int main(int argc, char *argv[])
{
    auto a = ListNode::vec_to_list({1, 2, 3, 3, 4, 4, 5});
    auto b = ListNode::vec_to_list({1, 2, 2});
    Solution s;
    cout << s.deleteDuplicates(a) << endl;
    cout << s.deleteDuplicates(b) << endl;
    return 0;
}
