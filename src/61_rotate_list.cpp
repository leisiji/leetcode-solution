struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		
		if (nullptr == head)
		{
			return nullptr;
		}

		ListNode *node = head;
		ListNode *newHead = nullptr;

		while (node != nullptr) {
			node = node->next;
		}

		newHead = node;

		return newHead;
	}
};

