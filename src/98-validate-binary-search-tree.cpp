#include <vector>

#include "listnode.hpp"

class Solution
{
public:
    bool isValidBST(TreeNode *root);
};

bool Solution::isValidBST(TreeNode *root)
{
    std::vector<TreeNode *> stack;
    TreeNode *node = root;
    int prev;
    bool first = true;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        auto val = node->val;
        if (first) {
            first = false;
            prev = val;
        } else if (prev >= val) {
            return false;
        }
        prev = val;
        stack.pop_back();
        node = node->right;
    }

    return true;
}
