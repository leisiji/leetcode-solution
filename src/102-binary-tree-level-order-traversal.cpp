#include <deque>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root);
    vector<vector<int>> levelOrder1(TreeNode* root);
};

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
    vector<vector<int>> out;
    if (root == nullptr) {
        return out;
    }

    deque<TreeNode*> q;
    q.push_back(root);

    while (!q.empty()) {
        const int size = q.size();
        vector<int> o;
        for (int i = 0; i < size; i++) {
            auto* node = q.front();
            q.pop_front();
            auto *l = node->left, *r = node->right;
            if (l != nullptr) {
                q.push_back(l);
            }
            if (r != nullptr) {
                q.push_back(r);
            }
            o.push_back(node->val);
        }
        out.emplace_back(o);
    }

    return out;
}

static void dfs(vector<vector<int>> &out, int height, TreeNode *node)
{
    if (node == nullptr) {
        return;
    }

    if (height >= out.size()) {
        out.reserve(out.size() + 1);
    }

    out[height].push_back(node->val);
    dfs(out, height + 1, node->left);
    dfs(out, height + 1, node->right);
}

vector<vector<int>> Solution::levelOrder1(TreeNode* root)
{
    vector<vector<int>> out;
    dfs(out, 0, root);
    return out;
}
