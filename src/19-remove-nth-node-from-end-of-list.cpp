#include <iostream>
#include <vector>
#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* removeNthFromEnd1(ListNode* head, int n);
    void printList(ListNode* head);
};

/* 使用一个数组保存 n 个节点，可以实现一次遍历就找到：空间复杂度 O(n)，时间复杂度 O(L) */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    vector<ListNode*> save(n + 1);
    ListNode* node = head;
    int loop = 0;

    while (node != nullptr) {
        save[loop % (n + 1)] = node;
        loop++;
        node = node->next;
    }

    ListNode* del = save[(loop + 1) % (n + 1)];
    if (del == head) {
        auto ret = head->next;
        delete head;
        return ret;
    }

    ListNode* prev = save[loop % (n + 1)];
    prev->next = del->next;
    delete del;

    return head;
}

/* 先让一个指针移动 n，再移动两个指针，一起移动直到第一个指针到达链表尾部，空间复杂度
 * 空间复杂度 O(1)，时间复杂度 O(L) */
ListNode* Solution::removeNthFromEnd1(ListNode* head, int n)
{
    ListNode *right = head;

    while ((n >= 0) && (right != nullptr)) {
        right = right->next;
        n--;
    }

    ListNode *left = head;
    while (right != nullptr) {
        left = left->next;
        right = right->next;
    }

    auto del = left->next;

    if (left == head) {
        if (del == nullptr) {
            delete head;
            return nullptr;
        } else {
            head = head->next;
        }
    }

    left->next = left->next->next;
    delete del;

    return head;
}

int main(int argc, char* argv[])
{
    auto head1 = ListNode::vec_to_list({1, 2, 3, 4, 5});

    Solution s;
    auto h1 = s.removeNthFromEnd(head1, 2);
    cout << h1 << endl;

    return 0;
}
