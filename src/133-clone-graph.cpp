#include <deque>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    Node *dfs(Node *node);
    unordered_map<Node*, Node*> map_;
public:
    Node* cloneGraph(Node* node);
    Node* cloneGraph1(Node* node);
};

Node *Solution::dfs(Node *node)
{
    // 节点已经访问过了
    auto iter = map_.find(node);
    if (iter != map_.end()) {
        return iter->second;
    }

    Node *new_node = new Node(node->val);
    map_.insert(make_pair(node, new_node));

    for (auto &i : node->neighbors) {
        new_node->neighbors.push_back(dfs(i));
    }

    return new_node;
}

Node *Solution::cloneGraph(Node *node)
{
    if (node == nullptr) {
        return nullptr;
    }
    map_.clear();
    return dfs(node);
}

Node *Solution::cloneGraph1(Node *node)
{
    map_.clear();

    if (node == nullptr) {
        return nullptr;
    }

    deque<Node*> q;
    Node *new_node = new Node(node->val);

    q.push_back(node);
    map_.insert(make_pair(node, new_node));

    while (!q.empty()) {
        const int size = q.size();
        for (int i = 0; i < size; i++) {
            Node *tmp = q.front();
            q.pop_front();

            auto cur = map_.find(tmp)->second;
            for (auto &neighbor : tmp->neighbors) {
                Node *new_neighbor;
                auto iter = map_.find(neighbor);
                if (iter == map_.end()) {
                    new_neighbor = new Node(neighbor->val);
                    map_.insert(make_pair(neighbor, new_neighbor));
                    q.push_back(neighbor);
                } else {
                    new_neighbor = iter->second;
                }
                cur->neighbors.push_back(new_neighbor);
            }
        }
    }

    return new_node;
}
