
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		if (nullptr == l1 || nullptr == l2)
		{
			return nullptr;
		}

		ListNode *ans, *tmp, *n1 = l1, *n2 = l2;
		int v1 = n1->val, v2 = n2->val;


		if (v1 < v2) {
			ans = new ListNode(v1);
		}
		else {
			ans = new ListNode(v2);
		}

		while (1)
		{
		}
	}
};
