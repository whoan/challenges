// https://leetcode.com/problems/buddy-strings/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size() || A.size() == 1) {
            return false;
        }
        differences.reserve(2);

        for (std::size_t i(0); i < A.size(); ++i) {
            if (A[i] != B[i]) {
                if (differences.size() == 2) {
                    return false;
                }
                saveDifference(A[i], B[i]);
            } else {
                checkRepeated(A[i]);
            }
        }
        
        if (differences.size() == 2) {
            return differences[0].first == differences[1].second
                && differences[1].first == differences[0].second;
        }
        
        return differences.size() == 0 && repeatedCharacter;
    }

private:
    bool repeatedCharacter = false;
    std::vector<std::pair<char, char>> differences;
    std::unordered_set<char> charCount;
    
    void saveDifference(char expected, char found) {
        differences.push_back(std::make_pair(expected, found));
    }
    
    void checkRepeated(char current) {
        if (repeatedCharacter) {
            return;
        }
        repeatedCharacter = charCount.count(current);
        charCount.insert(current);
    }
};
