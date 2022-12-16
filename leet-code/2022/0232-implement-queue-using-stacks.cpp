// https://leetcode.com/problems/implement-queue-using-stacks/
// Easy

class MyQueue {
public:
    void push(int x) {
        stack.push(x);
    }

    int pop() {
        int item = peek();
        reverted.pop();
        return item;
    }

    int peek() {
        revert();
        return reverted.top();
    }

    bool empty() {
        revert();
        return reverted.empty();
    }

private:
    void revert() {
        if (reverted.empty()) {
            while (!stack.empty()) {
                reverted.push(stack.top());
                stack.pop();
            }
        }
    }

    std::stack<int> stack;
    std::stack<int> reverted;
};
