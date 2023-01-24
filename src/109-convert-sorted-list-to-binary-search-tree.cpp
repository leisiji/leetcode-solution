#include "listnode.hpp"

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head);
};

/* 区间 [start, end) */
TreeNode *construct(ListNode *start, ListNode *end)
{
    if (start == end) {
        return nullptr;
    }
    ListNode *slow = start, *fast = start;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(slow->val);
    root->left = construct(start, slow);
    root->right = construct(slow->next, end);
    return root;
}

/* 比较简单的做法是链表转为数组，之后按 leetcode 108 的解法
 * 但是上述方法的核心是找到中位数，对于排序链表的中位数，刚好也是中间的那个数，
 * 这里使用快慢指针找到中间的节点，快指针移动 2 个节点，慢指针移动一个节点，
 * 快指针到达尾部时，慢指针就到中间位置 */
TreeNode *Solution::sortedListToBST(ListNode *head)
{
    return construct(head, nullptr);
}
