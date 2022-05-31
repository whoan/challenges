// https://leetcode.com/problems/text-justification/
// Hard

// shorter solution: https://leetcode.com/problems/text-justification/discuss/24873/Share-my-concise-c%2B%2B-solution-less-than-20-lines

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int max_width) {
        vector<string> result;
        string line;
        for (int i = 0; i < words.size(); ) {
            int width = words[i].size();
            int j = i+1;

            while (j < words.size() && width + words[j].size() + 1 <= max_width) {
                width += words[j++].size() + 1;
            }

            int words_in_line = j-i;
            line = std::move(words[i++]);

            if (j == words.size()) {
                // special case
                while (i < j) {
                    line.append(1, ' ');
                    line += words[i++];
                }
                line.append(max_width-line.size(), ' ');
            } else if (words_in_line == 1) {
                line.append(max_width-line.size(), ' ');
            } else {
                int total_spaces = max_width - width + words_in_line - 1;
                int even_spaces = words_in_line > 1 ? total_spaces / (words_in_line-1) : total_spaces;
                int extra_spaces = words_in_line > 1 ? total_spaces % (words_in_line-1) : total_spaces;
                while (i < j) {
                    line.append((extra_spaces-- > 0) + even_spaces, ' ');
                    line += words[i++];
                }
            }

            result.push_back(std::move(line));
        }
        return result;
    }
};
