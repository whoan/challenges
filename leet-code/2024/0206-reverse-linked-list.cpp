// https://leetcode.com/problems/reverse-linked-list/
// Easy

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        auto current = head, next = current->next;
        while (next) {
            current->next = prev;
            std::tie(prev, current, next) = std::make_tuple(current, next, next->next);
        }
        current->next = prev;
        return current;
    }
};
