/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* createNode(int value) {
        return new ListNode(value);
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int current = 0;
        ListNode* root = nullptr;
        ListNode* tail = nullptr;
        while (l1 || l2) {
            if (l1) {
                current += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                current += l2->val;
                l2 = l2->next;
            }
            auto node = createNode(current % 10);
            if (!root) {
                root = node;
                tail = root;
            } else {
                tail->next = node;
                tail = node;
            }
            current /= 10;
        }
        if (current) {
            tail->next = createNode(current);
        }
        return root;
    }
};
