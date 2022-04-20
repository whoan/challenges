/*
 * https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks
 */

#include <iostream>
#include <stack>
#include <stdexcept>

template <class T=int>
class MyQueue {
    std::stack<T> pushStack;
    std::stack<T> popStack;

    void changeStacks() {
        while (pushStack.size()) {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }
public:
    void pop() {
        if (popStack.empty()) {
            changeStacks();
            if (popStack.empty()) {
                throw std::out_of_range("There is no element to pop");
            }
        }
        popStack.pop();
    }

    void push(const T& data) {
        pushStack.push(data);
    }
    void push(T&& data) {
        pushStack.push(std::move(data));
    }

    const T& top() {
        if (popStack.empty()) {
            changeStacks();
            if (popStack.empty()) {
                throw std::out_of_range("There are no elements in the stack");
            }
        }
        return popStack.top();
    }
};

int main() {
    MyQueue<> q1;
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
                std::cout << q1.top() << std::endl;
                break;
        }
    }

    return 0;
}
