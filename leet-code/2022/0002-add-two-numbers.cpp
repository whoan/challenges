// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int remaining) {
        int sum = remaining;
        if (l1) {
            sum += l1->val + (l2 ? l2->val : 0);
            l1->val = sum % 10;
            l1->next = addTwoNumbers(l1->next, l2 ? l2->next : nullptr, sum/10);
            return l1;
        }
        if (l2) {
            sum += l2->val;
            l2->val = sum % 10;
            l2->next = addTwoNumbers(l2->next, nullptr, sum/10);
            return l2;
        }
        return remaining ? new ListNode(remaining) : nullptr;

    }
};

class FirstUglySolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int remaining) {
        int sum = remaining;
        if (l1 && l2) {
            sum += l1->val + l2->val;
            l1->val = sum % 10;
            l1->next = addTwoNumbers(l1->next, l2->next, sum/10);
            return l1;
        }

        auto longest = l1 ? l1 : l2;
        if (!longest) {
            return remaining ? new ListNode(remaining) : nullptr;
        }

        sum += longest->val;
        longest->val = sum % 10;
        if (!longest->next && sum/10) {
            longest->next = new ListNode(remaining);
        } else {
            longest->next = addTwoNumbers(longest->next, nullptr, sum/10);
        }
        return longest;
    }
};

/*
[9,9,9,9,9,9,9]
[9,9,9,9]
*/