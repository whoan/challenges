// https://leetcode.com/problems/palindrome-linked-list/
// Easy

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0;
        for (auto current = head; current; current = current->next) {
            ++count;
        }
        int half = count / 2;
        std::stack<int> stack;
        for (int i = 0; i < half; ++i) {
            stack.push(head->val);
            head = head->next;
        }
        // ignore middle element if count is odd
        if (count % 2) {
            head = head->next;
        }
        while (head) {
            if (head->val != stack.top()) {
                return false;
            }
            stack.pop();
            head = head->next;
        }
        return true;
    }
};

// follow up. O(1) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int count = 0;
        for (auto current = head; current; current = current->next) {
            ++count;
        }
        int half = count / 2;
        auto prev = head, current=head->next;
        head->next = nullptr;
        // reverse up to half of the list
        while (--half > 0) {
            std::tie(current->next, prev, current) = std::make_tuple(prev, current, current->next);
        }
        // ignore middle element if count is odd
        if (count % 2 && count > 1) {
            current = current->next;
        }
        // compare both lists form the middle
        while (current && prev) {
            if (current->val != prev->val) {
                return false;
            }
            std::tie(current, prev) = std::make_tuple(current->next, prev->next);
        }
        return true;
    }
};
