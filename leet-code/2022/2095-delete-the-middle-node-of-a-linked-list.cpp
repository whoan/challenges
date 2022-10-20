// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Medium

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode prev_head(0, head);
        auto *slow = &prev_head, *fast = head;
        while (fast && fast->next) {
            std::tie(slow, fast) = make_pair(slow->next, fast->next);
            if (fast) {
                fast = fast->next;
            }
        }
        slow->next = slow->next->next;
        return prev_head.next;
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
