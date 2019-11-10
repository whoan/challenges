class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    ListNode* before;
    if (l1->val <= l2->val) {
      before = l1;
      l1 = l1->next;
    } else {
      before = l2;
      l2 = l2->next;
    }

    before->next = mergeTwoLists(l1, l2);
    return before;
  }
};


// alternative solution. Shorter but not that self-explanatory
class Solution2 {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    if (l1->val <= l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }

    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
};
