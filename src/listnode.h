#include <vector>
#include <ostream>
#include <iostream>

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

template<class T>
static inline void print_vec(std::vector<T> &vec)
{
    std::cout << "[";
    for (auto &i : vec) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
}

template<class T>
static inline void print_vec_vec(std::vector<std::vector<T>> &vec)
{
    for (auto& i : vec) {
        std::cout << "[";
        for (auto& j : i) {
            std::cout << j << ",";
        }
        std::cout << "], ";
    }
    std::cout << std::endl;
}
