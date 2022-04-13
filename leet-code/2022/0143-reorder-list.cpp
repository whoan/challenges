// https://leetcode.com/problems/reorder-list/
// Medium

// disclaimer: pretty horrible solution

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
    void reorderList(ListNode* head) {
        if (!head->next) {
            return;
        }

        // find middle (divided by left and right) and revert list up to middle
        auto left = head;
        auto right = head->next;
        auto fast = head->next;
        head->next = nullptr;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            auto tmp = right->next;
            right->next = left;
            left = right;
            right = tmp;
        }

        // handle odd number of nodes
        auto right_next = fast && fast->next && !fast->next->next ? right : nullptr;
        if (right_next) {
            right = right->next;
            right_next->next = nullptr;
        }

        // merge lists (horrible way. improve)
        while (true) {
            auto tmp = left;

            auto prev_prev = left->next;
            left->next = right;
            left = prev_prev;

            auto next_next = right->next;
            right->next = right_next;
            right = next_next;

            right_next = tmp;
            if (!prev_prev) {
                break;
            }
        }
    }
};
