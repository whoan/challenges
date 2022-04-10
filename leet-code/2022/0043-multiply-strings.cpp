// https://leetcode.com/problems/multiply-strings/
// Medium

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') {
            return "0";
        }

        auto& shorter = num1.size() < num2.size() ? num1 : num2;
        auto& larger  = num1.size() < num2.size() ? num2 : num1;

        std::vector<std::string> partial;
        partial.reserve(shorter.size());
        for (int i = 0; i < shorter.size(); ++i) {
            char c = shorter[i];
            partial.push_back(multiply(larger, c-'0', shorter.size()-i-1));
        }
        return sum(partial);
    }

    string multiply(string& larger, int multiplier, int zeroes) {
        // allocate 1 more byte for the carry just in case (as it's expensive to ask for more memory)
        string total(larger.size()+1+zeroes, '0');
        total.pop_back();
        int carry = 0;
        for (int i = larger.size()-1; i >= 0; --i) {
            int n = (larger[i]-'0')*multiplier + carry;
            total[i] = '0' + n % 10;
            carry = n / 10;
        }
        if (carry) {
            // won't reallocate due to trick above
            total.insert(0, 1, '0' + carry);
        }
        return total;
    }

    string sum(std::vector<string>& partial) {
        // allocate 1 more byte for the carry just in case (as it's expensive to ask for more memory)
        std::string total(partial.front().size()+1, '0');
        total.pop_back();
        int carry = 0;
        for (int i = partial.front().size()-1; i >= 0; --i) {
            int n = carry;
            for (auto& s : partial) {
                if (!s.empty()) {
                    n += s.back()-'0';
                    s.pop_back();
                }
            }
            total[i] = '0' + (n % 10);
            carry = n / 10;
        }
        if (carry) {
            // won't reallocate due to trick above
            total.insert(0, 1, '0' + carry);
        }
        return total;
    }
};

/*
Test data:
"19"
"999"
*/
