// https://leetcode.com/problems/unique-morse-code-words/
// Easy

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        std::array<string, 26> codes{
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--.."
        };
        std::unordered_set<string> seen;
        for (auto& word : words) {
            string transformation;
            for (char c : word) {
                transformation.append(codes[c-'a']);
            }
            seen.insert(std::move(transformation));
        }
        return seen.size();
    }
};
