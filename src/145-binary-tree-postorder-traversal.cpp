#include <vector>

#include "listnode.h"

using namespace std;

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root);
};

/* 后序遍历和前 2 个有点不同：
 * 需要多使用一个 prev 节点，因为先左后右无需出栈，栈内始终保存了根，
 * 会有不停 "右->根" 的循环 */
vector<int> Solution::postorderTraversal(TreeNode* root)
{
    vector<int> out;
    TreeNode* node = root, *prev = nullptr;
    vector<TreeNode*> stack;

    while (node != nullptr || !stack.empty()) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }

        node = stack.back();
        auto *r = node->right;
        if (r != nullptr && r != prev) {
            node = r;
        } else {
            out.push_back(node->val);
            prev = node;
            node = nullptr;
            stack.pop_back();
        }
    }

    return out;
}
