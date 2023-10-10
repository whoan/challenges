// https://leetcode.com/problems/minimum-number-of-keypresses
// Medium

class Solution {
public:
    int minimumKeypresses(string s) {
        std::vector<int> count(27, 0);
        for (char c : s) {
            ++count[c-'a'];
        }
        std::sort(count.begin(), count.end());
        int n_press = 0;
        for (int need_press = 1; need_press <= 3; ++need_press) {
            for (int n_buttons = 9; count.back() && n_buttons > 0; --n_buttons) {
                n_press += count.back() * need_press;
                count.pop_back();
            }
        }
        return n_press;
    }
};
