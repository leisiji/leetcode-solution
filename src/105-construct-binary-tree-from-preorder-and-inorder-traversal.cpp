#include <unordered_map>
#include <utility>
#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
private:
    vector<int> *preorder_;
    TreeNode *construct(int, int, int, int);
    unordered_map<int, int> index_;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
};

// 前序遍历的第一个元素为根节点
// 中序遍历中，该根节点所在位置的左侧为左子树，右侧为右子树
TreeNode *Solution::construct(int pstart, int pend, int istart, int iend)
{
    if (pstart > pend) {
        return nullptr;
    }

    auto s = preorder_->at(pstart);
    TreeNode *root = new TreeNode(s);
    auto mid = index_.find(s)->second;
    auto size_left_subtree = mid - istart; // 得到左子树的大小

    root->left = construct(pstart + 1, pstart + size_left_subtree, istart, mid - 1);
    root->right = construct(pstart + size_left_subtree + 1, pend, mid + 1, iend);

    return root;
}

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
    preorder_ = &preorder;
    const int len = inorder.size();
    for (int i = 0; i < len; i++) {
        index_.insert(make_pair(inorder[i], i));
    }
    return construct(0, len - 1, 0, len - 1);
}
