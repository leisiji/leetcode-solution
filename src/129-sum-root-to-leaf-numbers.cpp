#include "listnode.hpp"

class Solution
{
private:
    int num_, sum_;
    void dfs(TreeNode *node);

public:
    int sumNumbers(TreeNode *root);
};

void Solution::dfs(TreeNode *node)
{
    int prev = num_;

    num_ = 10 * num_ + node->val;

    auto *left = node->left, *right = node->right;
    if (left == nullptr && right == nullptr) {
        sum_ += num_;
        return;
    }

    if (left != nullptr) {
        dfs(left);
    }

    if (right != nullptr) {
        dfs(right);
    }

    num_ = prev;
}

int Solution::sumNumbers(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }

    num_ = 0;
    sum_ = 0;

    dfs(root);

    return sum_;
}
