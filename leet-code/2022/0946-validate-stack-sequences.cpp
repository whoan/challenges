// https://leetcode.com/problems/validate-stack-sequences/
// Medium

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int pop_index = 0;
        for (int n : pushed) {
            stack.push(n);
            while (!stack.empty() && popped[pop_index] == stack.top()) {
                stack.pop();
                ++pop_index;
            }
        }
        return stack.empty();
    }
};

class FirstComplexSolution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_index = 0, pop_index = 0;
        stack<int> stack;
        /*
         I think this push helps the branch predictor to have
         a false most of the times in the first condition inside the loop
        */
        stack.push(pushed[push_index++]);
        while (pop_index < popped.size()) {
            if (stack.empty()) {
                stack.push(pushed[push_index++]);
            }
            while (push_index < pushed.size() && stack.top() != popped[pop_index]) {
                stack.push(pushed[push_index++]);
            }
            if (stack.top() != popped[pop_index]) {
                return false;
            }
            stack.pop();
            ++pop_index;
        }
        return true;
    }
};

/*
Test data:
[1,2,3,4,5]
[4,5,3,2,1]
[1,2,3,4,5]
[4,3,5,1,2]
[1,0]
[1,0]
*/
