#include <algorithm>
#include <unordered_map>
#include <utility>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
private:
    std::unordered_map<Node *, Node *> map_;

public:
    Node *copyRandomList(Node *head);
};

/* map_ 保存了旧链表和新链表的指针一一对应关系 */
Node *Solution::copyRandomList(Node *head)
{
    Node *node = head;
    Node newhead(0);
    Node *prev = &newhead;

    while (node != nullptr) {
        Node *cur;
        auto rand = map_.find(node);
        if (rand != map_.end()) {
            cur = rand->second;
        } else {
            cur = new Node(node->val);
            map_.insert(std::make_pair(node, cur));
        }
        prev->next = cur;
        prev = cur;

        auto random = node->random;
        if (random != nullptr) {
            Node *randp;
            auto tmp = map_.find(random);
            if (tmp != map_.end()) {
                randp = tmp->second;
            } else {
                randp = new Node(random->val);
                map_.insert(std::make_pair(random, randp));
            }
            cur->random = randp;
        }

        node = node->next;
    }

    return newhead.next;
}

int main(int argc, char *argv[])
{
    return 0;
}
