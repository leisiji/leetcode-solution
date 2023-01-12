#include <deque>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#include "listnode.h"

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists);
    ListNode *mergeKLists1(vector<ListNode *> &lists);
};

static inline void insert_deq(deque<ListNode *> &queue, ListNode *node)
{
    int left = 0, right = queue.size() - 1;
    int target = node->val;

    while (left <= right) {
        int mid = (left + right) >> 1;
        int val = queue[mid]->val;
        if (val > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    queue.insert(queue.begin() + left, node);
}

ListNode *Solution::mergeKLists(vector<ListNode *> &lists)
{
    const int len = lists.size();
    deque<ListNode *> queue;

    for (int i = 0; i < len; i++) {
        auto &node = lists[i];
        if (node != nullptr) {
            insert_deq(queue, node);
        }
    }

    if (queue.size() == 0) {
        return nullptr;
    }

    ListNode head;
    ListNode *node = &head;

    while (!queue.empty()) {
        ListNode *cur = queue.front();
        auto *next = cur->next;
        node->next = cur;
        node = cur;
        queue.pop_front();
        if (next != nullptr) {
            insert_deq(queue, next);
        }
    }

    return head.next;
}

struct Node {
    Node(ListNode *n) : node(n) {}
    ListNode *node;
    bool operator<(const Node &rhs) const { return node->val > rhs.node->val; }
};

/* 使用 priority_queue 比自己写的二分查找插入速度快并且内存占用更小 */
ListNode *Solution::mergeKLists1(vector<ListNode *> &lists)
{
    const int len = lists.size();
    priority_queue<Node> q;

    for (int i = 0; i < len; i++) {
        auto n = lists[i];
        if (n) {
            q.emplace(Node(n));
        }
    }

    ListNode head;
    ListNode *node = &head;

    while (!q.empty()) {
        auto n = q.top();
        node->next = n.node;
        auto next = n.node->next;
        node = n.node;
        q.pop();
        if (next != nullptr) {
            q.emplace(Node(next));
        }
    }

    return head.next;
}

int main(int argc, char *argv[])
{
    vector<ListNode *> a = {
        ListNode::vec_to_list({1, 4, 5}),
        ListNode::vec_to_list({1, 3, 4}),
        ListNode::vec_to_list({2, 6}),
    };
    vector<ListNode *> b = {
        ListNode::vec_to_list({1}),
    };
    vector<ListNode *> c = {
        ListNode::vec_to_list({0, 2, 5}),
    };
    Solution s;
    cout << s.mergeKLists1(a) << endl;
    cout << s.mergeKLists1(b) << endl;
    cout << s.mergeKLists1(c) << endl;
    return 0;
}
