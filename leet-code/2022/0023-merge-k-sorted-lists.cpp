// https://leetcode.com/problems/merge-k-sorted-lists/
// Hard

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using List = ListNode*;
        List head = nullptr;
        auto comparator = [] (List list1, List list2) { return list1->val > list2->val; };
        std::priority_queue<
            List,
            std::vector<List>,
            decltype(comparator)
        > heap(comparator);

        // initialize heap
        for (auto list : lists) {
            if (list) {
                heap.push(list);
            }
        }

        // sort
        List current = head;
        while (!heap.empty()) {
            auto list = heap.top();
            heap.pop();
            if (!head) {
                head = list;
                current = list;
            } else {
                current->next = list;
                current = current->next;
            }
            if (list->next) {
                heap.push(list->next);
            }
        }
        return head;
    }
};
