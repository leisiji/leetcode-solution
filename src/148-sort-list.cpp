#include "listnode.hpp"

class Solution
{
public:
    ListNode *sortList(ListNode *head);
};

static ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode dummy;
    ListNode *node = &dummy, *node1 = l1, *node2 = l2;

    while (node1 != nullptr && node2 != nullptr) {
        if (node1->val <= node2->val) {
            node->next = node1;
            node1 = node1->next;
        } else {
            node->next = node2;
            node2 = node2->next;
        }
        node = node->next;
    }

    if (node1 != nullptr) {
        node->next = node1;
    } else if (node2 != nullptr) {
        node->next = node2;
    }

    return dummy.next;
}

static ListNode *sortList(ListNode *head, ListNode *tail)
{
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }

    // 通过快慢指针找到链表中点
    ListNode *slow = head, *fast = head;
    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *l1 = sortList(head, slow), *l2 = sortList(slow, tail);
    return merge(l1, l2);
}

static ListNode *sortList1(ListNode *head)
{
    if (head == nullptr) {
        return nullptr;
    }

    ListNode dummy;
    dummy.next = head;
    ListNode *cur = head, *prev;
    int len = 0;

    while (cur != nullptr) {
        len++;
        cur = cur->next;
    }

    for (int sublen = 1; sublen < len; sublen = sublen << 1) {
        prev = &dummy, cur = dummy.next;

        while (cur != nullptr) {
            ListNode *head1 = cur;
            for (int i = 1; i < sublen && cur->next != nullptr; i++) {
                cur = cur->next;
            }

            ListNode *head2 = cur->next;
            cur->next = nullptr;  // 将 head1 链表摘除
            cur = head2;
            // 注意 2 个跨越 sublen 的判断条件不同，第一个循环保证 head2 至少有一个节点
            for (int i = 1; i < sublen && cur != nullptr; i++) {
                cur = cur->next;
            }

            ListNode *next = nullptr;
            if (cur != nullptr) {
                next = cur->next;
                cur->next = nullptr;  // 将 head2 链表摘除
            }

            ListNode *merged = merge(head1, head2);
            prev->next = merged;
            while (prev->next != nullptr) {
                prev = prev->next;
            }
            cur = next;
        }
    }
    return dummy.next;
}

ListNode *Solution::sortList(ListNode *head)
{
    return ::sortList(head, nullptr);
}

int main(int argc, char *argv[])
{
    auto a = ListNode::vec_to_list({-1, 5, 3, 4, 0});
    Solution s;
    a = s.sortList(a);
    // std::cout << a << std::endl;
    std::cout << sortList1(a) << std::endl;
    return 0;
}
