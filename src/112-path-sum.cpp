#include "listnode.hpp"

class Solution
{
private:
    int sum_, target_;
    bool ans_;
    void dfs(TreeNode *node);

public:
    bool hasPathSum(TreeNode *root, int targetSum);
};

void Solution::dfs(TreeNode *node)
{
    if (node == nullptr || ans_) {
        return;
    }

    sum_ += node->val;
    if (node->left == nullptr && node->right == nullptr) {
        if (sum_ == target_) {
            ans_ = true;
        }
    } else {
        dfs(node->left);
        dfs(node->right);
    }
    sum_ -= node->val;
}

bool Solution::hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr) {
        return false;
    }

    ans_ = false;
    sum_ = 0;
    target_ = targetSum;
    dfs(root);
    return ans_;
}
