https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        enum Char { a, b, l, n, o, max };
        vector<short> repetitions(Char::max, 0); // ablno

        for (auto c : text) {
            switch (c) {
                case 'a':
                    ++repetitions[Char::a];
                    break;
                case 'b':
                    ++repetitions[Char::b];
                    break;
                case 'l':
                    ++repetitions[Char::l];
                    break;
                case 'n':
                    ++repetitions[Char::n];
                    break;
                case 'o':
                    ++repetitions[Char::o];
                    break;
                default:
                    break;
            }
        }
        repetitions[Char::l] /= 2;
        repetitions[Char::o] /= 2;
        return *std::min_element(std::begin(repetitions), std::end(repetitions));
    }
};
