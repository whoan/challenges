// https://leetcode.com/problems/last-stone-weight/
// Easy

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;
        for (int stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int heavier = top(pq);
            int difference = heavier-top(pq);
            if (difference) {
                pq.push(difference);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
private:
    template<typename PQ>
    int top(PQ& pq) {
        int val = pq.top();
        pq.pop();
        return val;
    }
};
