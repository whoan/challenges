// https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts(k, nullptr);
        ListNode hear(0, head);
        int nNodes = 0;

        for (auto node = head; node; node = node->next, ++nNodes) {
            parts[nNodes%k] = advance(parts[nNodes%k] ? parts[nNodes%k] : &hear, nNodes%k);
        }

        if (nNodes % k && nNodes > k) {
            for (int i=nNodes%k; i < k; ++i) {
                parts[i] = advance(parts[i], nNodes%k);
            }
        }

        for (int i = 0; i < parts.size() && parts[i]; ++i) {
            auto node = parts[i];
            parts[i] = node->next;
            node->next = nullptr;
        }

        return parts;
    }

    ListNode* advance(ListNode* node, int i) {
        while (i--) {
            node = node->next;
        }
        return node;
    }
};

/*
Dataset:
[1,2,3]
5
[1,2,3,4,5,6,7,8,9,10]
3
[0,1]
1
[0,1,2,3]
2
[0,1,2,3,4]
3
*/
