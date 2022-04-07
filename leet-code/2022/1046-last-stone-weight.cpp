// https://leetcode.com/problems/last-stone-weight/
// Easy

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> heap;
        for (int stone : stones) {
            heap.push(stone);
        }
        while (heap.size() > 1) {
            int y = heap.top();
            heap.pop();
            int x = heap.top();
            heap.pop();
            if (x != y) {
                heap.push(y-x);
            }
        }
        return heap.empty() ? 0 : heap.top();
    }
};
