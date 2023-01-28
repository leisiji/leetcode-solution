#include <vector>

#include "listnode.hpp"

class Solution
{
public:
    void flatten(TreeNode* root);
};

/* 最简单的方法就是用数组存储前序遍历的结果，之后遍历数组，更改每个元素左右子节点的值 */
void Solution::flatten(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    std::vector<TreeNode*> vec;
    std::vector<TreeNode*> stack;
    TreeNode* node = root;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            vec.push_back(node);
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        stack.pop_back();
        node = node->right;
    }

    vec.push_back(nullptr);
    const int len = vec.size();
    for (int i = 0; i < len - 2; i++) {
        vec[i]->left = nullptr;
        vec[i]->right = vec[i + 1];
    }
}
