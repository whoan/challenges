/*
 * https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks
 */

#include <iostream>
#include <stack>
#include <stdexcept>

class MyQueue {
    typedef int type;
    std::stack<type> pushStack;
    std::stack<type> popStack;

    void changeStacks(std::stack<type>& origin, std::stack<type>& destination) {
        while (origin.size()) {
            destination.push(origin.top());
            origin.pop();
        }
    }
public:
    void pop() {
        if (popStack.empty()) {
            changeStacks(pushStack, popStack);
        }
        if (popStack.empty()) throw std::out_of_range("There is no elements to pop");
        popStack.pop();
    }

    void push(type data) {
        pushStack.push(data);
    }

    type front() {
        if (popStack.empty()) {
            changeStacks(pushStack, popStack);
        }
        if (popStack.empty() && pushStack.empty()) throw std::out_of_range("There is no elements in the stack");
        return popStack.top();
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        std::cin >> type;
        switch (type) {
            case 1:
                std::cin >> x;
                q1.push(x);
                break;
            case 2:
                q1.pop();
                break;
            default:
                std::cout << q1.front() << std::endl;
                break;
        }
    }

    return 0;
}
