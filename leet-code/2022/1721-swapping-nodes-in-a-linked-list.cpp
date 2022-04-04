// https://leetcode.com/problems/
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode first;
        first.next = head;

        auto left = &first;
        for (int i=1; i < k; ++i) {
            left = left->next;
        }

        auto right = &first;
        auto node = left;
        while (node->next->next) {
            node = node->next;
            right = right->next;
        }

        std::swap(left->next, right->next);
        std::swap(left->next->next, right->next->next);

        return first.next;
    }
};

class SwappingValuesSolution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode first;
        first.next = head;

        auto left = &first;
        for (int i=1; i < k; ++i) {
            left = left->next;
        }

        auto right = &first;
        auto node = left;
        while (node->next->next) {
            node = node->next;
            right = right->next;
        }

        std::swap(left->next->val, right->next->val);

        return first.next;
    }
};

/*
Test data:
[1,2,3,4,5]
2
[7,9,6,6,7,8,3,0,9,5]
5
[7,9,6,6,7,8,3,0,9,5]
1
[1]
1
*/
