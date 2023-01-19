#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    void preorderTraversal(TreeNode *root, vector<int> &out);

public:
    // 递归的前序遍历
    vector<int> preorderTraversal(TreeNode *root);
    // 循环的前序遍历
    vector<int> preorderTraversal1(TreeNode *root);
};

void Solution::preorderTraversal(TreeNode *root, vector<int> &out)
{
    if (root == nullptr) {
        return;
    }

    out.push_back(root->val);
    preorderTraversal(root->left, out);
    preorderTraversal(root->right, out);
}
vector<int> Solution::preorderTraversal(TreeNode *root)
{
    vector<int> res;
    preorderTraversal(root, res);
    return res;
}

/* 由于没有递归的函数调用开销，以及更小的栈，遍历法的速度和内存都会更优 */
vector<int> Solution::preorderTraversal1(TreeNode *root)
{
    vector<int> res;
    vector<TreeNode *> stack;
    auto node = root;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            res.push_back(node->val);
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        stack.pop_back();
        node = node->right;
    }

    return res;
}
