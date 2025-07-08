// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
// Medium

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        enum { START, END };
        std::ranges::sort(events);
        int assisted = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> can_assist; // min Heap
        for (int i = 0, day = events.front()[START]; i < events.size() || !can_assist.empty(); ++day) {
            for (; i < events.size() && events[i][START] == day; ++i) {
                can_assist.push(events[i][END]);
            }
            if (!can_assist.empty() && can_assist.top() >= day) {
                can_assist.pop();
                ++assisted;
            }
            // clean missed events
            while (!can_assist.empty() && can_assist.top() <= day) {
                can_assist.pop();
            }
        }
        return assisted;
    }
};
