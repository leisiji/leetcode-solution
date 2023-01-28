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
};

Node* Solution::connect(Node* root)
{
    Node *leftmost = root, *next, *prev, *parents = root;
    Node tmp1;

    while (leftmost != nullptr) {
        prev = &tmp1;
        next = nullptr;
        parents = leftmost;
        while (parents != nullptr) {
            auto *left = parents->left, *right = parents->right;
            if (left != nullptr) {
                prev->next = left;
                prev = left;
                if (next == nullptr) {
                    next = left;
                }
            }
            if (right != nullptr) {
                prev->next = right;
                prev = right;
                if (next == nullptr) {
                    next = right;
                }
            }
            parents = parents->next;
        }

        leftmost = next;
    }

    return root;
}
