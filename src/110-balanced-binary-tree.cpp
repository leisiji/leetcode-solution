#include <algorithm>
#include <cmath>

#include "listnode.hpp"

class Solution
{
private:
    bool ans_;
    int dfs(TreeNode *root);

public:
    bool isBalanced(TreeNode *root);
};

int Solution::dfs(TreeNode *root)
{
    if (root == nullptr || !ans_) {
        return 0;
    }

    auto lh = dfs(root->left) + 1;
    auto rh = dfs(root->right) + 1;

    if (std::abs(lh - rh) > 1) {
        ans_ = false;
    }

    return std::max(lh, rh);
}

bool Solution::isBalanced(TreeNode *root)
{
    ans_ = true;
    dfs(root);
    return ans_;
}
