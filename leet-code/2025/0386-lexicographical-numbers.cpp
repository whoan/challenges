// https://leetcode.com/problems/lexicographical-numbers/
// Medium

class Solution {
    vector<int> answer;
public:
    vector<int> lexicalOrder(int n) {
        recurse(n, 1);
        return std::move(answer);
    }

private:
    void recurse(int max, int n) {
        for (int i = (n == 1); i < 10 && n <= max; ++n, ++i) {
            answer.push_back(n);
            recurse(max, n*10);
        }
    }
};
