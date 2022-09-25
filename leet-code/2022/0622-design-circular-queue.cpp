// https://leetcode.com/problems/design-circular-queue/
// Medium

class MyCircularQueue {
    int capacity, size, start, end;
    std::vector<int> queue;

public:
    MyCircularQueue(int k) : capacity(k), size(0), start(0), end(0) {
        queue.resize(capacity);
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        queue[end] = value;
        end = (end + 1) % capacity;
        ++size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        start = (start + 1) % capacity;
        --size;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : queue[start];
    }

    int Rear() {
        return isEmpty() ? -1 : queue[(end ? end : capacity)-1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
