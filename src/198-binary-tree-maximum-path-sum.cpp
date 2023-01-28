#include <algorithm>

#include "listnode.hpp"

class Solution
{
public:
    int maxPathSum(TreeNode *root);
};

static int ans;

// 非空节点的最大贡献值等于节点值与其子节点中的最大贡献值之和
int max_sum(TreeNode *node)
{
    if (node == nullptr) {
        return 0;
    }

    auto l = max_sum(node->left);
    auto r = max_sum(node->right);
    l = l > 0 ? l : 0;
    r = r > 0 ? r : 0;

    // 这里注意计算节点和与返回值的计算不同
    // 1. 最大节点和是左右节点的最大贡献，形成一个完整路径
    // 2. 返回值则是路径的一部分
    int sum = node->val + l + r;
    ans = std::max(ans, sum);
    return node->val + std::max(l, r);
}

// dfs：并且在每个根节点去更新答案
int Solution::maxPathSum(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }
    ans = root->val;
    max_sum(root);
    return ans;
}
