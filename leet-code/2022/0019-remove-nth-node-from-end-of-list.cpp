// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Medium

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // forward right iterator n times
        auto right = head;
        while (n--) {
            right = right->next;
        }

        // corner case
        if (!right) {
            return head->next;
        }

        // forward current size-(n+1) times
        auto current = head;
        while (right->next) {
            right = right->next;
            current = current->next;
        }

        // remove node
        current->next = current->next->next;
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
