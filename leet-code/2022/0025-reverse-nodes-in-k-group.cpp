// https://leetcode.com/problems/reverse-nodes-in-k-group/
// Hard

// seems to be inefficient. For a Hard one, I am fine with that

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head->next) {
            return head;
        }
        ListNode prev_to_head;
        ListNode* last_tail = &prev_to_head;
        auto current = head;
        while (current) {
            auto [full_group, new_head, new_tail] = reverse(current, k);
            if (!full_group) {
                // undo/redo last call
                reverse(new_head, k);
                break;
            }
            current = new_tail->next; // pointer to N*k+1 node
            last_tail->next = new_head;
            last_tail = new_tail;
        }
        return prev_to_head.next;
    }

    /*
     * This function reverse k nodes but leaves tail's next pointer, pointing to
     * old next value (k+1 node) so it creates a cycle. This is useful for further processing
     * and should be handled on the caller function
     */
    std::tuple<bool, ListNode*, ListNode*> reverse(ListNode* head, int k) {
        if (!head->next) {
            return {false, head, head};
        }
        auto previous = head, current = previous->next, next = current->next;
        int i = 0;
        for (; current && i < k-1; ++i) {
            current->next = previous;
            previous = current;
            current = next;
            next = next ? next->next : nullptr;
        }
        head->next = current;
        return {i == k-1, previous, head};
    }
};

/*
Test data:
[1,2,3,4,5]
2
[1,2,3,4,5]
3
[1,2,3,4,5,6,7,8,9,10,11]
4
[1,2,3,4,5,6,7,8,9,10,11]
3
*/
