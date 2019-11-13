#include <bits/stdc++.h>

class MinStack {
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    void checkStack() {
        if (stack.empty()) {
            throw std::runtime_error("No elements in stack");
        }
    }
    
    void push(int x) {
        stack.push(x);
        if (minStack.empty()) {
            minStack.push(x);
        } else {
            auto currentMin = minStack.top();
            minStack.push(currentMin > x ? x : currentMin);
        }
    }
    
    void pop() {
        checkStack();
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        checkStack();
        return stack.top();
    }
    
    int getMin() {
        checkStack();
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
*/
