/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* current = head;
        for (int i = n; i; --i) {
            current = current->next;
        }
        if (!current) {
            return head->next;
        }
        auto* before = head;
        while (current->next) {
            current = current->next;
            before = before->next;
        }
        before->next = before->next->next;
        return head;
    }
};
