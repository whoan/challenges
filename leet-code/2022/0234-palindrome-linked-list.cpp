// https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        int size = 0;
        for (auto node = head; node; node = node->next) ++size;
        if (size == 1) {
            return true;
        }

        int half = size / 2;
        ListNode* prev = nullptr;
        auto node = head;
        for (int i = 0; i < half/2; ++i) {
            auto next = node->next;
            auto next_next = next->next;
            node->next = prev;
            next->next = node;
            node = next_next;
            prev = next;
        }

        // horrible part. can be improved rotating from middle
        if (half % 2 == 0 && size % 2) {
            node = node->next;
        } else if (half % 2) {
            if (size % 2) {
                if (node->val != node->next->next->val) {
                    return false;
                }
                node = node->next->next->next;
            } else {
                if (node->val != node->next->val) {
                    return false;
                }
                node = node->next->next;
            }
        }

        // check palindrome
        while (node) {
            if (node->val != prev->val) {
                return false;
            }
            node = node->next;
            prev = prev->next;
        }
        return true;
    }
};

/*
Test data:
[1,2,3,2,1]
[1,2,2]
[0,0]
[0]
[1,2]
[1,2,2,1]
[9,2,3,1]
[1,2,3,4,5,4,3,2,1]
*/
