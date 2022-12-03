#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head);
};

bool Solution::hasCycle(ListNode *head)
{
    ListNode *slow = head;

    if (nullptr == slow) {
        return false;
    }

    ListNode *fast = head->next;

    while (slow != nullptr && fast != nullptr) {
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
        if (fast->next != nullptr) {
            fast = fast->next->next;
        } else {
            fast = nullptr;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    return 0;
}
