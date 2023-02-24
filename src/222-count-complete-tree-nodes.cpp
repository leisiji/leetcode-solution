#include "listnode.hpp"

class Solution
{
public:
    int countNodes(TreeNode *root);
};

static inline bool exist(TreeNode *node, int height, int k)
{
    int bits = 1 << (height - 2);

    while (node != nullptr && bits > 0) {
        if ((bits & k) == 0) {
            node = node->left;
        } else {
            node = node->right;
        }
        bits = bits >> 1;
    }

    return node != nullptr;
}

int Solution::countNodes(TreeNode *root)
{
    TreeNode *node = root;
    int height = 0;

    while (node != nullptr) {
        node = node->left;
        height++;
    }

    if (height <= 1) {
        return height;
    }

    // 通过二分查找，判断最底层的第 k 个节点是否存在；k 是按层再从左到右计数
    int low = 1 << (height - 1), high = (1 << height) - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (exist(root, height, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return (low - 1);
}
