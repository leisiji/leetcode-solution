#include <algorithm>
#include <unordered_map>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    unordered_map<int, int> index_;
    vector<int> *rorder_;
    TreeNode *construct(int istart, int iend, int rstart, int rend);

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);
};

TreeNode *Solution::construct(int istart, int iend, int rstart, int rend)
{
    if (rstart > rend) {
        return nullptr;
    }

    auto num = rorder_->at(rstart);
    TreeNode *root = new TreeNode(num);
    auto mid = index_.find(num)->second;
    auto size_right_subtree = iend - mid;

    root->left = construct(istart, mid - 1, rstart + size_right_subtree + 1, rend);
    root->right = construct(mid + 1, iend, rstart + 1, rstart + size_right_subtree);

    return root;
}

TreeNode *Solution::buildTree(vector<int> &inorder, vector<int> &postorder)
{
    reverse(postorder.begin(), postorder.end());
    rorder_ = &postorder;

    const int len = inorder.size();
    for (int i = 0; i < len; i++) {
        index_.insert(make_pair(inorder[i], i));
    }

    return construct(0, len - 1, 0, len - 1);
}
