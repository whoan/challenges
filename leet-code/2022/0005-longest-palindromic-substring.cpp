// https://leetcode.com/problems/longest-palindromic-substring/
// Medium

// related: Manacher's algorithm -> https://en.wikipedia.org/wiki/Longest_palindromic_substring

class InefficientSolution {
public:
    string longestPalindrome(string s) {
        s = insert_stars_between_chars(std::move(s));
        std::vector<int> lengths(s.size());
        for (int i = 0; i < s.size(); ++i) {
            lengths[i] = !(i & 1);
            for (int j = 1; i-j >=0 && i+j < s.size() && s[i-j] == s[i+j]; ++j) {
                lengths[i] += (s[i-j] != '*')*2;
            }
        }
        auto max_it = std::max_element(lengths.begin(), lengths.end());
        int index_longest = std::distance(lengths.begin(), max_it);
        int longest = *max_it;
        string result = s.substr(index_longest-(longest-1), longest*2-1);
        return remove_stars_between_chars(result);
    }

private:
    string insert_stars_between_chars(string s) {
        auto original_size = s.size();
        s.resize(s.size()*2-1, '*');
        for (int i = original_size-1, j = s.size()-1; i >= 0; --i, j -= 2) {
            std::swap(s[i], s[j]);
        }
        return s;
    }

    string remove_stars_between_chars(string s) {
        int i = 0;
        for (int j = (s[0] == '*'); j < s.size(); ++i, j += 2) {
            s[i] = s[j];
        }
        s.resize(i);
        return s;
    }
};

/*
Test data:
"a"
"abb"
"babad"
"cbbd"
"adam"
"babadada"
"bananas"
"aaabaaaa"
*/
