#include <cstdio>
#include <iostream>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k);
};

ListNode *Solution::rotateRight(ListNode *head, int k)
{
    if (head == nullptr || k == 0) {
        return head;
    }

    ListNode *left = head;
    ListNode *right = head;
    int len = 0, i = k;

    while (right != nullptr && i > 0) {
        right = right->next;
        len++;
        i--;
    }

    if (right == nullptr && i >= 0) {
        i = k % len;
        if (i == 0) {
            return head;
        }
        right = head;
        while (right != nullptr && i > 0) {
            right = right->next;
            i--;
        }
    }

    ListNode *prev_right, *prev_left;
    while (right != nullptr) {
        prev_left = left;
        prev_right = right;
        left = left->next;
        right = right->next;
    }

    prev_right->next = head;
    prev_left->next = nullptr;

    return left;
}

int main(int argc, char *argv[])
{
    auto head1 = ListNode::vec_to_list({5, 6, 7, 8, 9});
    Solution s;
    cout << s.rotateRight(head1, 5) << endl;
    return 0;
}
