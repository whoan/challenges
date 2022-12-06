// https://leetcode.com/problems/odd-even-linked-list/
// Medium

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return head;
        }
        auto even_head = head ? head->next : head;
        auto odd = head;
        for (auto even = even_head;
             even && even->next;
             odd = odd->next, even = even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
        }
        odd->next = even_head;
        return head;
    }
};
