#include <algorithm>
#include <deque>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root);
};

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root)
{
    if (root == nullptr) {
        return {};
    }

    vector<vector<int>> out;
    deque<TreeNode*> q;

    q.push_back(root);

    while (!q.empty()) {
        vector<int> tmp;
        const int size = q.size();
        for (int i = 0; i < size; i++) {
            auto* node = q.front();
            tmp.push_back(node->val);
            q.pop_front();
            auto *left = node->left, *right = node->right;
            if (left != nullptr) {
                q.push_back(left);
            }
            if (right != nullptr) {
                q.push_back(right);
            }
        }
        out.emplace_back(tmp);
    }
    reverse(out.begin(), out.end());

    return out;
}
