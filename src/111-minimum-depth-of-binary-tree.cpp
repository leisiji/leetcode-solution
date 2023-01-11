#include <deque>

#include "listnode.h"

class Solution
{
public:
    int minDepth(TreeNode *root);
};

int Solution::minDepth(TreeNode *root)
{
    if (root == nullptr) {
        return 0;
    }

    std::deque<TreeNode *> q;
    int ans = 1;

    auto *l = root->left, *r = root->right;
    if (l != nullptr) {
        q.push_back(l);
    }
    if (r != nullptr) {
        q.push_back(r);
    }

    while (!q.empty()) {
        const int size = q.size();

        ans++;
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
            if (l == nullptr && r == nullptr) {
                return ans;
            }
        }
    }

    return ans;
}
