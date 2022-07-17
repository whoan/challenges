// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Medium

class SlowSolution {
public:
    int minDeletions(string s) {
        constexpr int alphabet_length = 'z'-'a'+1;
        std::array<int, alphabet_length> char_count{};
        for (char c : s) {
            ++char_count[c-'a'];
        }
        std::sort(char_count.begin(), char_count.end(), std::greater<int>());
        std::map<int, int, std::greater<int>> frequency_count;
        for (int n : char_count) {
            if (n == 0) {
                break;
            }
            ++frequency_count[n];
        }
        int total_chars_to_delete = 0;
        for (auto it = frequency_count.begin(); it != frequency_count.end() && it->first > 0; ++it) {
            auto [frequency, count] = *it;
            int chars_to_delete = count - 1;
            if (chars_to_delete == 0) {
                continue;
            }
            total_chars_to_delete += chars_to_delete;
            frequency_count[frequency-1] += chars_to_delete;
        }
        return total_chars_to_delete;
    }
};

// only changes the way to write the last loop
class AlternativeSolution {
public:
    int minDeletions(string s) {
        constexpr int alphabet_length = 'z'-'a'+1;
        std::array<int, alphabet_length> char_count{};
        for (char c : s) {
            ++char_count[c-'a'];
        }
        std::sort(char_count.begin(), char_count.end(), std::greater<int>());
        std::map<int, int, std::greater<int>> frequency_count;
        for (int n : char_count) {
            if (n == 0) {
                break;
            }
            ++frequency_count[n];
        }
        int total_chars_to_delete = 0;
        for (auto [frequency, count] : frequency_count) {
            if (frequency == 0) {
                break;
            }
            int chars_to_delete = count - 1;
            if (chars_to_delete == 0) {
                continue;
            }
            total_chars_to_delete += chars_to_delete;
            frequency_count[frequency-1] += chars_to_delete;
        }
        return total_chars_to_delete;
    }
};

/*
Test data:
"accdcdadddbaadbc"
"aabbcdrrrrrtttttyyyyyuuuuuiiiiooooppp"
"aab"
"aaabbbcc"
"ceabaacb"
*/
