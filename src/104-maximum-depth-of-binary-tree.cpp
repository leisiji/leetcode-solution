#include <algorithm>
#include <deque>

#include "listnode.hpp"

class Solution
{
public:
    int maxDepth(TreeNode *root);
    int maxDepth1(TreeNode *root);
};

/* DFS */
int Solution::maxDepth(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

/* BFS */
int Solution::maxDepth1(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }
    int ans;
    std::deque<TreeNode *> q;

    q.push_back(root);

    while (!q.empty()) {
        const int size = q.size();

        for (int i = 0; i < size; i++) {
            auto *node = q.front();
            q.pop_front();
            auto *l = node->left, *r = node->right;
            if (l != nullptr) {
                q.push_back(l);
            }
            if (r != nullptr) {
                q.push_back(r);
            }
        }
        ans++;
    }

    return ans;
}
