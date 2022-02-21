// https://leetcode.com/problems/moving-average-from-data-stream/
// Easy

class MovingAverage {
    std::deque<double> stream;
    int size;
    double accumulated;
public:
    MovingAverage(int size) : size(size) {

    }

    double next(int val) {
        if (stream.size() == size) {
            accumulated -= stream.front();
            stream.pop_front();
        }
        stream.push_back(val);
        accumulated += val;
        return accumulated / stream.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
