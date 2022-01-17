// https://leetcode.com/problems/swap-nodes-in-pairs/
// Medium

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto next_batch = head->next->next;
        head->next->next = head;
        std::swap(head->next, head);
        head->next->next = swapPairs(next_batch);
        return head;
    }
};
