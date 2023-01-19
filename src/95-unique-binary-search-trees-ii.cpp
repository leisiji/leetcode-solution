#include <vector>

#include "listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n);
};

/* 由于这道题用的是指针，因此较为特殊，需要反着来，不是从根节点开始，而是先生成子节点 */
vector<TreeNode *> generateTrees(int start, int end)
{
    if (start > end) {
        return {nullptr};
    }

    vector<TreeNode *> out;

    for (int i = start; i <= end; i++) {
        vector<TreeNode *> left = generateTrees(start, i - 1);
        vector<TreeNode *> right = generateTrees(i + 1, end);

        // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
        for (auto &l : left) {
            for (auto &r : right) {
                TreeNode *cur = new TreeNode(i);
                cur->left = l;
                cur->right = r;
                out.emplace_back(cur);
            }
        }
    }

    return out;
}

vector<TreeNode *> Solution::generateTrees(int n)
{
    return ::generateTrees(1, n);
}

int main (int argc, char *argv[])
{
    Solution s;
    auto ret = s.generateTrees(3);
    for (auto &i : ret) {
        i->print();
        cout << endl;
    }
    return 0;
}
