#include <vector>
#include <ostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    static ListNode *vec_to_list(std::vector<int> vec);
    friend std::ostream &operator<<(std::ostream &out, ListNode *head) {
        out << "[";
        while (head != nullptr) {
            out << head->val << ",";
            head = head->next;
        }
        out << "]";
        return out;
    }
};

inline ListNode *ListNode::vec_to_list(std::vector<int> vec)
{
    ListNode *head = nullptr;
    ListNode **node = &head;

    for (auto &i : vec) {
        *node = new ListNode(i);
        node = &(*node)->next;
    }

    return head;
}
