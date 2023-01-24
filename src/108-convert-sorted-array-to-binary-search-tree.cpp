#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    vector<int> *nums_;
    TreeNode *construct(int start, int end);

public:
    TreeNode *sortedArrayToBST(vector<int> &nums);
};

TreeNode *Solution::construct(int start, int end)
{
    if (start > end) {
        return nullptr;
    }

    const int len = end - start + 1, mid = len / 2 + start;
    TreeNode *root = new TreeNode(nums_->at(mid));
    root->left = construct(start, mid - 1);
    root->right = construct(mid + 1, end);
    return root;
}

TreeNode *Solution::sortedArrayToBST(vector<int> &nums)
{
    nums_ = &nums;
    return construct(0, nums.size() - 1);
}
