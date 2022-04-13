// https://leetcode.com/problems/add-binary/
// Easy

class Solution {
public:
    string addBinary(string a, string b) {
        return a.size() < b.size() ?
            solution(a, b) :
            solution(b, a);
    }

    string solution(string& shorter, string& longer) const {
        bool carryOver = false;
        int idxShorter = shorter.size()-1;
        int idxLonger = longer.size()-1;
        for (; idxShorter >= 0 || idxLonger >= 0; --idxShorter, --idxLonger) {
            int ones = carryOver;
            ones += idxShorter >= 0 && shorter[idxShorter] == '1';
            ones += idxLonger  >= 0 && longer[idxLonger] == '1';
            longer[idxLonger] = (ones % 2) + '0';
            carryOver = ones > 1;
        }
        return std::move(carryOver ? string(1, '1') + longer : longer);
    }
};

/*
Test data:
"11"
"1"
"1010"
"1011"
*/
