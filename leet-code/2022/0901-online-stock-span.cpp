// https://leetcode.com/problems/online-stock-span/
// Medium

// stack
class StockSpanner {
    enum { SPAN, PRICE };
    std::stack<std::pair<int, int>> buffer;
public:
    StockSpanner() {
    }

    int next(int price) {
        int span = 1;
        while (!buffer.empty() && std::get<PRICE>(buffer.top()) <= price) {
            span += std::get<SPAN>(buffer.top());
            buffer.pop();
        }
        buffer.push({span, price});
        return span;
    }
};

 // vector
class StockSpanner {
    enum { SPAN, PRICE };
    std::vector<std::pair<int, int>> buffer;
public:
    StockSpanner() {
        buffer.reserve(1e4);
    }

    int next(int price) {
        int span = 1;
        while (!buffer.empty() && std::get<PRICE>(buffer.back()) <= price) {
            span += std::get<SPAN>(buffer.back());
            buffer.pop_back();
        }
        buffer.push_back({span, price});
        return span;
    }
};

class OldStockSpanner {
    enum { SPAN, PRICE };
    std::vector<std::pair<int, int>> buffer;
public:
    StockSpanner() {
        buffer.reserve(1e4);
    }

    int next(int price) {
        int span = 1;
        for (int i = buffer.size()-1; i >= 0 && std::get<PRICE>(buffer[i]) <= price; --i) {
            span += std::get<SPAN>(buffer[i]);
            i -= std::get<SPAN>(buffer[i]) - 1;
        }
        buffer.push_back({span, price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
