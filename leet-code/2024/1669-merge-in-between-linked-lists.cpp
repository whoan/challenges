// https://leetcode.com/problems/merge-in-between-linked-lists/
// Medium

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto head = list1;
        b -= a-3; // -3 because we start from 1 prev node (not to be deleted),
                  // then we need to remove b-a+1 nodes,
                  // and then we need to position the merge point past the last element removed.
        // find merge points in list 1
        while (--a) {
            list1 = list1->next;
        }
        auto merge_point1 = list1;
        while (--b) {
            list1 = list1->next;
        }
        auto merge_point2 = list1;
        // merge start of list2
        merge_point1->next = list2;
        while (merge_point1->next) {
            merge_point1 = merge_point1->next;
        }
        merge_point1->next = merge_point2;
        return head;
    }
};
