class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node* copyRandomList(Node* head);
};

/* 这一题的难点在于复制 random 时，random 可能指向非常后面的非分配的节点 */
Node *Solution::copyRandomList(Node *head)
{
    return nullptr;
}
