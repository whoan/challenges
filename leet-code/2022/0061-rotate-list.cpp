// https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        auto node = head;
        int i = 0;
        for (; node && i < k; ++i) {
            node = node->next;
        }

        // if k is bigger than list length
        if (k > i) {
            k = k % i;
            node = head;
            for (i=0; node && i < k; ++i) {
                node = node->next;
            }
        }

        // go to list_length - k
        auto slower = head;
        while (node->next) {
            node = node->next;
            slower = slower->next;
        }
        node->next = head;
        head = slower->next;
        slower->next = nullptr;
        return head;
    }
};

/*
Test data:
[1,2,3,4,5]
2
[0,1,2]
4
[]
0
*/
