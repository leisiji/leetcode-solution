#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root);
};

/*
 * 记忆方法
 * - 可以通过遍历知道到底 push 哪一个到栈，由于调用了递归函数，则必须保存 root 现场，即所有情况都是
 * push root 到栈
 * - 前序遍历可以知道先将 root 填写到答案再递归，即先填写答案再循环；而中序则是先 left
 * 递归再填写答案
 */
vector<int> Solution::inorderTraversal(TreeNode *root)
{
    vector<TreeNode *> stack;
    TreeNode *node = root;
    vector<int> out;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        stack.pop_back();
        out.push_back(node->val);
        node = node->right;
    }

    return out;
}
