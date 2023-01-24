#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    vector<int> tmp_;
    vector<vector<int>> *out_;
    int sum_, target_;
    void dfs(TreeNode *node);

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum);
};

void Solution::dfs(TreeNode *node)
{
    if (node == nullptr) {
        return;
    }

    sum_ += node->val;
    tmp_.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
        if (sum_ == target_) {
            out_->push_back(tmp_);
        }
    } else {
        dfs(node->left);
        dfs(node->right);
    }
    sum_ -= node->val;
    tmp_.pop_back();
}

vector<vector<int>> Solution::pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> out;
    sum_ = 0;
    target_ = targetSum;
    out_ = &out;
    dfs(root);
    return out;
}
