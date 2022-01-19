// https://leetcode.com/problems/linked-list-cycle-ii/
// Medium

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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        // detect cycle
        auto slow = head, fast = head->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast && fast->next) {
                fast = fast->next;
            } else {
                return nullptr;
            }
        }
        // calculate length of cycle
        int cycle_length = 1;
        for (auto node_in_cycle = slow; slow->next != node_in_cycle; slow = slow->next) {
            ++cycle_length;
        }
        // walk list to get to TOTAL-cycle_length nodes of the intersection
        slow = head;
        for (int i=0; i < cycle_length; ++i) {
            slow = slow->next;
        }
        // calculate TOTAL-cycle_length finding the intersection
        while (head->next != slow->next) {
            head = head->next;
            slow = slow->next;
        }
        return head == slow ? head : head->next;
    }
};
