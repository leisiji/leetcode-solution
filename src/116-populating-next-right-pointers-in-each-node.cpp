#include <deque>

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next)
    {
    }
};

class Solution
{
public:
    Node* connect(Node* root);
    Node* connect1(Node* root);
};

Node* Solution::connect1(Node* root)
{
    Node *node, *prev;
    std::deque<Node*> q;

    if (root == nullptr) {
        return nullptr;
    }

    q.push_back(root);

    while (!q.empty()) {
        const int len = q.size();
        Node tmp;
        prev = &tmp;

        for (int i = 0; i < len; i++) {
            node = q.front();
            q.pop_front();
            auto *left = node->left, *right = node->right;
            if (left != nullptr) {
                q.push_back(left);
            }
            if (right != nullptr) {
                q.push_back(right);
            }
            prev->next = node;
            prev = node;
        }
    }

    return root;
}

void dfs(Node *node, int height)
{
    if (node == nullptr) {
        return;
    }
    dfs(node->left, height + 1);
    dfs(node->right, height + 1);
}

// 进阶：
// 1. 只能使用常量级额外空间
// 2. 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度
Node *Solution::connect(Node *root)
{
    // 利用上一层的结果 head.next 去遍历当前层的所有节点
    Node *leftmost = root;
    Node tmp2;

    // 注意题目条件：所有的叶子节点都在同一层
    while (leftmost != nullptr) {
        Node *parents = leftmost;
        Node *prev = &tmp2;

        while (parents != nullptr) {
            auto *left = parents->left, *right = parents->right;
            if (left != nullptr) {
                prev = left;
                prev->next = left;
            }
            if (right != nullptr) {
                prev = right;
            }
            parents = parents->next;
        }
        leftmost = leftmost->left;
    }

    return root;
}
