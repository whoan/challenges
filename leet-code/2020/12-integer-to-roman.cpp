// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        std::string roman;
        for (int i(0); num; num /= 10, ++i) {
            switch (num%10) {
                case 4:
                    roman = convertNumberFour(i) + roman;
                    break;
                case 5:
                    roman = convertNumberFive(i) + roman;
                    break;
                case 9:
                    roman = convertNumberNine(i) + roman;
                    break;
                case 0:
                    break;
                default:
                    roman = convertRegularNumbers(num%10, i) + roman;
            }
            
        }
        return roman;
    }
    
private:
    std::string convertNumberFour(int iteration) {
        switch (iteration) {
            case 0:
                return "IV";
            case 1:
                return "XL";
            case 2:
                return "CD";
            default:
                throw std::runtime_error("impossible");
        }
    }

    std::string convertNumberNine(int iteration) {
        switch (iteration) {
            case 0:
                return "IX";
            case 1:
                return "XC";
            case 2:
                return "CM";
            default:
                throw std::runtime_error("impossible");
        }
    }

    std::string convertNumberFive(int iteration) {
        switch (iteration) {
            case 0:
                return "V";
            case 1:
                return "L";
            case 2:
                return "D";
            default:
                throw std::runtime_error("impossible");
        }
    }
    
    std::string convertRegularNumbers(int number, int iteration) {
        std::vector<char> romanChars{'I', 'X', 'C', 'M'};
        std::string result;
        if (number > 4) {
            result = convertNumberFive(iteration);
        }
        return result + std::string(number%5, romanChars.at(iteration));
    }
};
