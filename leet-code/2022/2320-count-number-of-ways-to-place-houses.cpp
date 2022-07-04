// https://leetcode.com/problems/count-number-of-ways-to-place-houses/
// Medium

class Solution {
public:
    int countHousePlacements(int n) {
        long long result = fib_cousin(n);
        result *= result;
        return result % int(1e9+7);
    }

private:
    long long fib_cousin(int n, long long next=2, long long next_next=3) {
        /*
        1 => 2
        2 => 2 + 1
        3 => fc(1) + fc(2) = 5
        4 => fc(2) + fc(3) = 8
        */
        if (n == 1) {
            return next;
        }
        if (n == 2) {
            return next_next;
        }
        return fib_cousin(n-1, next_next, (next+next_next) % int(1e9+7));
    }
};
