#include <deque>
#include <algorithm>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root);
};

static inline void push(deque<TreeNode *> &q, TreeNode *node)
{
    if (node != nullptr) {
        q.push_back(node);
    }
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> out;
    deque<TreeNode *> q;
    bool odd = false;

    if (root == nullptr) {
        return {};
    }

    q.push_back(root);

    while (!q.empty()) {
        vector<int> tmp;
        // 再进入出入栈操作
        const int size = q.size();
        for (int i = 0; i < size; i++) {
            auto *node = q.front();
            q.pop_front();
            auto *l = node->left, *r = node->right;
            push(q, l);
            push(q, r);
            tmp.push_back(node->val);
        }
        if (odd) {
            reverse(tmp.begin(), tmp.end());
        }
        odd = !odd;
        out.emplace_back(tmp);
    }

    return out;
}

int main(int argc, char *argv[])
{
    return 0;
}
