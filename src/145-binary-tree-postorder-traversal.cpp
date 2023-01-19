#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root);
};

vector<int> Solution::postorderTraversal(TreeNode* root)
{
    vector<int> out;
    TreeNode *node = root, *prev = nullptr;
    vector<TreeNode*> stack;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        auto* r = node->right;
        if (r != nullptr && r != prev) {
            node = r;
        } else {
            out.push_back(node->val);
            prev = node;  // 遍历完 node 的子树后会回到 root 的父节点，node
                          // 可能是父节点的右节点，prev 防止死循环
            node = nullptr;
            stack.pop_back();
        }
    }

    return out;
}
