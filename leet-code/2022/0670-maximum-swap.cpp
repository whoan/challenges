// https://leetcode.com/problems/maximum-swap/
// Medium

class Solution {
public:
    int maximumSwap(int num) {
        // convert to vector of digits (you can use to_string too)
        std::vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }

        // sort the digits to compare
        auto sorted_digits = digits;
        std::sort(sorted_digits.begin(), sorted_digits.end());

        // swap digits (if needed)
        for (int i = digits.size()-1; i >= 0; --i) {
            if (digits[i] != sorted_digits[i]) {
                auto index_to_swap = std::distance(
                    digits.begin(),
                    find(digits.begin(), digits.end(), sorted_digits[i])
                );
                std::swap(digits[index_to_swap], digits[i]);
                break;
            }
        }

        // create number again from vector of digits
        for_each(digits.rbegin(), digits.rend(), [&num] (int n) {
            num = num * 10 + n;
        });
        return num;
    }
};
