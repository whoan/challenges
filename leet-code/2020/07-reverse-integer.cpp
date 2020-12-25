// https://leetcode.com/problems/reverse-integer

/*
  1- if x < 0, push_back "-" in a string
  2- check if x != 0 to continue; otherwise, go to step 6
  3- push_back (concat) (x modulus 10) in a string
  4- reduce x dividing it by 10
  5- back to step 2
  6- check corner cases
*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        std::string reversed;
        reversed.reserve(11);
        bool inputIsNegative = x < 0;
        if (inputIsNegative) {
            reversed += '-';
        }

        for (; x; x /= 10) {
            reversed += char('0' + std::abs(x%10));
        }
        if (smallerThanMin(reversed) || greaterThanMax(reversed)) {
            return 0;
        }

        return std::stoi(reversed);
    }

private:
    bool smallerThanMin(const std::string& reversed) {
        std::cout << reversed << std::endl;
        static const std::string min = "-2147483648";
        bool inputIsNegative = reversed[0] == '-';
        // notice here this is counterintuitive
        return inputIsNegative && reversed.size() == min.size() && reversed >  min;
    }

    bool greaterThanMax(const std::string& reversed) {
        static const std::string max = "2147483647";
        bool inputIsNegative = reversed[0] == '-';
        return !inputIsNegative && reversed.size() == max.size() && reversed > max;
    }
};
