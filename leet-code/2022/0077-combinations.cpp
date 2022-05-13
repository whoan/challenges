// https://leetcode.com/problems/combinations/
// Medium

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        current.reserve(k);
        backtrack(n, k);
        return std::move(result);
    }

private:
    void backtrack(int n, int k, int start=1) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (; start <= n; ++start) {
            current.push_back(start);
            backtrack(n, k, start+1);
            current.pop_back();
        }
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};

// reserve memory in advance
class AlternativeSolution {
public:
    vector<vector<int>> combine(int n, int k) {
        current.reserve(k);
        result.reserve(get_number_of_combinations(n, k));
        backtrack(n, k);
        return std::move(result);
    }

private:
    void backtrack(int n, int k, int start=1) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (; start <= n; ++start) {
            current.push_back(start);
            backtrack(n, k, start+1);
            current.pop_back();
        }
    }

    int get_number_of_combinations(int n, int k) {
        int divisor = n-k;
        double total = 1;
        for (int i=k+1; i <= n; ++i) {
            if (divisor == 0) {
                divisor = 1;
            }
            total *= double(i)/divisor--;
        }
        return total;
    }

    std::vector<int> current;
    std::vector<std::vector<int>> result;
};
