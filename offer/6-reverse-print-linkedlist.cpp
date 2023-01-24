#include <algorithm>
#include <vector>

#include "../src/listnode.hpp"

using namespace std;

class Solution
{
public:
    vector<int> reversePrint(ListNode *head);
};

vector<int> Solution::reversePrint(ListNode *head)
{
    vector<int> out;
    ListNode *node = head;

    while (node != nullptr) {
        out.push_back(node->val);
        node = node->next;
    }

    reverse(out.begin(), out.end());
    return out;
}
