// https://leetcode.com/problems/validate-stack-sequences/
// Medium

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> stack;
        for (int i = 0, j = 0; j < popped.size(); ) {
            if (stack.empty() || popped[j] != stack.top()) {
                if (i == pushed.size()) {
                    return false;
                }
                stack.push(pushed[i++]);
            } else {
                stack.pop();
                ++j;
            }
        }
        return stack.empty();
    }
};
