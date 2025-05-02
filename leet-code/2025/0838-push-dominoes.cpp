// https://leetcode.com/problems/push-dominoes/
// Medium

class Solution {
public:
    string pushDominoes(string dominoes) {
        const int None = -1;
        enum : char { Left='L', Right='R', Still='.' };
        int start = dominoes[0] == Still ? 0 : None;
        char previous = dominoes[0];
        for (int i=1; i < dominoes.size(); previous = dominoes[i++]) {
            if (dominoes[i] == Still) {
                start = (start == None ? i : start);
                if (previous == Right) {
                    dominoes[i] = Right;
                }
                continue;
            }
            if (dominoes[i] == Left && start != None) {
                if (previous == Still) {
                    adjust(dominoes, start, i, Left);
                } else { // previous == Right
                    adjust(dominoes, start+(i-start)/2, i, Left);
                    if ((i-start) % 2) { // tie
                        dominoes[start+(i-start)/2] = Still;
                    }
                }
            }
            start = None;
        }
        return dominoes;
    }
private:
    void adjust(string& dominoes, int from, int to, char what) {
        dominoes.replace(from, to-from, std::string(to-from, what));
    }
};
