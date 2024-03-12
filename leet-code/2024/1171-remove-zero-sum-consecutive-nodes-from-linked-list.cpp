// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Medium

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        std::unordered_map<int, ListNode*> seen;
        ListNode prev_head(0, head);
        seen[0] = &prev_head;
        int sum = 0;
        while (head) {
            sum += head->val;
            if (auto [it, inserted] = seen.emplace(sum, head); !inserted) {
                int sum_to_delete = it->first;
                for (auto prev = it->second; prev->next != head; prev = prev->next) {
                    sum_to_delete += prev->next->val;
                    seen.erase(sum_to_delete);
                }
                it->second->next = head->next;
                sum = it->first;
            }
            head = head->next;
        }
        return seen[0]->next;
    }
};
