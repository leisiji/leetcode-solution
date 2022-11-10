struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *n1 = l1, *n2 = l2;
    ListNode *head = nullptr, *prev;
    int val1, val2, carry = 0, sum;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        if (n1 != nullptr) {
            val1 = n1->val;
            n1 = n1->next;
        } else {
            val1 = 0;
        }
        if (n2 != nullptr) {
            val2 = n2->val;
            n2 = n2->next;
        } else {
            val2 = 0;
        }
        sum = val1 + val2 + carry;
        if (sum >= 10) {
            carry = 1;
            sum = sum - 10;
        } else {
            carry = 0;
        }

        if (head == nullptr) {
            head = new ListNode(sum);
            prev = head;
        } else {
            prev->next = new ListNode(sum);
            prev = prev->next;
        }
    }

    return head;
}
