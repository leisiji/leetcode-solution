#include "listnode.hpp"

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head);
};

ListNode *Solution::insertionSortList(ListNode *head)
{
    if (head == nullptr) {
        return nullptr;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode *cur = head->next;
    ListNode *sorted = head;

    while (cur != nullptr) {
        auto val = cur->val;
        if (val >= sorted->val) {
            sorted = sorted->next;
        } else {
            ListNode *prev = &dummy;
            while (val >= prev->next->val) {
                prev = prev->next;
            }
            sorted->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
        }
        cur = sorted->next;
    }

    return dummy.next;
}

int main(int argc, char *argv[])
{
    auto tmp = ListNode::vec_to_list({-1, 5, 3, 4, 0});
    Solution s;
    std::cout << s.insertionSortList(tmp) << std::endl;
    return 0;
}
