// https://leetcode.com/problems/add-strings/
// Easy

class Solution {
public:
    string addStrings(string num1, string num2) {
        auto& shorter = num1.size() < num2.size() ? num1 : num2;
        auto& longer  = num1.size() < num2.size() ? num2 : num1;
        int shorter_index = shorter.size()-1, longer_index=longer.size()-1;
        int carry = 0;
        // sum shorter into longer
        while (shorter_index >= 0) {
            int sum = shorter[shorter_index] + longer[longer_index] + carry - 2*'0';
            longer[longer_index] = '0' + (sum % 10);
            carry = bool(sum > 9);
            --shorter_index;
            --longer_index;
        }
        // handle carry after we processed "shorter"
        while (longer_index >= 0) {
            int sum = longer[longer_index] + carry - '0';
            longer[longer_index] = '0' + (sum % 10);
            carry = bool(sum > 9);
            --longer_index;
        }
        // Append a 1 at the beginning if needed
        if (carry) {
            longer.insert(0, 1, '1');
        }
        return longer;
    }
};
