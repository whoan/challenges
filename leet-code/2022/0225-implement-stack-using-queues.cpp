// https://leetcode.com/problems/implement-stack-using-queues/
// Easy

class MyStack {
public:
    // use emptry_one as a temporary buffer and should be empty again after each push()
    void push(int x) {
        empty_one.push(x);
        while (!another.empty()) {
            empty_one.push(another.front());
            another.pop();
        }
        std::swap(empty_one, another);
    }

    int pop() {
        int value = top();
        another.pop();
        return value;
    }

    int top() {
        return another.front();
    }

    bool empty() {
        return another.empty();
    }

private:
    std::queue<int> empty_one, another;
};

// using only one queue
class FollowUpStack {
public:
    void push(int x) {
        queue.push(x);
        for (int i = 0; i < queue.size()-1; ++i) {
            queue.push(queue.front());
            queue.pop();
        }
    }

    int pop() {
        int value = top();
        queue.pop();
        return value;
    }

    int top() {
        return queue.front();
    }

    bool empty() {
        return queue.empty();
    }

private:
    std::queue<int> queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
