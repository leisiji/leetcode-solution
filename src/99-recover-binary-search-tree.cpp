#include <algorithm>
#include <vector>
#include "listnode.hpp"

class Solution {
public:
    void recoverTree1(TreeNode* root);
    void recoverTree(TreeNode* root);
};

/* 最朴素的解法：遍历 2 次 + 排序一次；时间是 O(nlog(n))，空间是 O(n) */
void Solution::recoverTree1(TreeNode *root)
{
    TreeNode *node = root;
    std::vector<TreeNode*> stack;
    std::vector<int> tmp;
    int prev;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        stack.pop_back();
        tmp.push_back(node->val);
        node = node->right;
    }

    std::sort(tmp.begin(), tmp.end());
    node = root;
    int i = 0;
    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        stack.pop_back();
        node->val = tmp[i++];
        node = node->right;
    }
}

/* 会发现一个规律：
 * 1. 先找到前一个节点大于后一个节点的，这里选前一个节点
 * 2. 之后也是找到前一个大于后一个的，但是选后一个节点 */
void Solution::recoverTree(TreeNode *root)
{
    TreeNode *node = root, *a = nullptr, *b = nullptr, *prevn;
    std::vector<TreeNode*> stack;
    int prev;
    bool first = true;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        stack.pop_back();
        auto val = node->val;
        if (first) {
            first = false;
            prev = val;
        } else {
            b = node; // 应对交换的 2 个节点刚好相邻的情况
            if (prev > val) {
                if (a == nullptr) {
                    a = prevn;
                } else {
                    break;
                }
            }
        }
        prev = val;
        prevn = node;
        node = node->right;
    }

    std::swap(a->val, b->val);
}
