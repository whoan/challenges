// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/
// Medium

// sloooowww, and horribly implemented
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int maxLength = word.size()-numFriends+1;
        std::vector<int> indices(word.size());
        std::ranges::iota(indices, 0);
        const char smallest = 'a'-1;
        char max = smallest;
        std::string answer;
        answer.reserve(maxLength);
        for (int i = 0; i < maxLength; ++i) {
            std::vector<int> new_indices; new_indices.reserve(indices.size());
            for (int j : indices) {
                if (word[j] < max || j == word.size()) {
                    continue;
                }
                if (word[j] > max) {
                    max = word[j];
                    new_indices.clear();
                }
                new_indices.push_back(j+1); // next (outer) iteration check next element
            }
            std::swap(indices, new_indices);
            if (max != smallest) {
                answer.push_back(max);
            }
            max = smallest;
        }
        return answer;
    }
};
