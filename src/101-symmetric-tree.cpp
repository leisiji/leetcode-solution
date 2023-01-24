#include "listnode.hpp"

class Solution
{
public:
    bool isSymmetric(TreeNode *root);
};

static bool same(TreeNode *p, TreeNode *q)
{
    auto ret1 = p == nullptr, ret2 = q == nullptr;
    if (ret1 ^ ret2) {
        return false;
    } else if (ret1 && ret2) {
        return true;
    }
    return p->val == q->val && same(p->right, q->left) && same(p->left, q->right);
}

bool Solution::isSymmetric(TreeNode *root)
{
    return same(root->left, root->right);
}
