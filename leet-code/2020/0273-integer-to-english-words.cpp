// https://leetcode.com/problems/integer-to-english-words/

/*
1- convert to string for easily parsing
2- count the characters
3- create function to convert chunks of up to 3 numbers
4- process the input by chunks of up to 3 numbers
5- if you are on 4th chunk, append billion: 3rd, million; 2nd, thousand; 1st nothing
*/

class Solution {
public:
    string numberToWords(int num) {
        string result;
        
        if (!num) {
            return "Zero";
        }

        constexpr int billion = 1000000000;
        int billions = num / billion ;
        if (billions) {
            if (!result.empty()) {
                result += " ";
            }
            result += convert(billions) + " Billion";
            num %= billion;
        }

        constexpr int million = 1000000;
        int millions = num / million;
        if (millions) {
            if (!result.empty()) {
                result += " ";
            }
            result += convert(millions) + " Million";
            num %= million;
        }

        constexpr int thousand = 1000;
        int thousands = num / thousand;
        if (thousands) {
            if (!result.empty()) {
                result += " ";
            }
            result += convert(thousands) + " Thousand";
            num %= thousand;
        }

        if (!result.empty() && num % 1000) {
            result += " ";
        }
        result += convert(num % 1000);
        
        return result;
    }
    
private:
    string convert(int n) {
        string result;
        if (n / 100) {
            result += string(unityToText.at(n / 100)) + " Hundred";
            n -= (n /100) * 100;
        }
        
        if (n / 10) {
            if (!result.empty()) {
               result += " ";
            }
            if (n / 10 == 1) {
                return result + tens10ToText.at(n%10);
            }
            result += tensToText.at(n / 10);
        }
        
        if (n%10) {
            if (!result.empty()) {
               result += " ";
            }
            result += unityToText.at(n % 10);
        }
        return result;
    }
        
    const unordered_map<int, const char*> unityToText {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
    };
    
    const unordered_map<int, const char*> tens10ToText {
        {0, "Ten"},
        {1, "Eleven"},
        {2, "Twelve"},
        {3, "Thirteen"},
        {4, "Fourteen"},
        {5, "Fifteen"},
        {6, "Sixteen"},
        {7, "Seventeen"},
        {8, "Eighteen"},
        {9, "Nineteen"},
    };
    
    const unordered_map<int, const char*> tensToText {
        {2, "Twenty"},
        {3, "Thirty"},
        {4, "Forty"},
        {5, "Fifty"},
        {6, "Sixty"},
        {7, "Seventy"},
        {8, "Eighty"},
        {9, "Ninety"},
    };
};
