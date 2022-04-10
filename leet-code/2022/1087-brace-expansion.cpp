// https://leetcode.com/problems/brace-expansion/
// Medium

/*
I think this exercise can be solved backwardto avoid sorting at the end:
- Calculate length of resulting collection: options_1 * options_2 * ... * options_n
  eg: "{a,b,c}ddddd{e,f}"
        ^^^^^       ^^^
      options_1   options_2
          3     *    2      == length of resulting collection == 6

- Calculate length of each string: non-optional characters + number of '{' (or '})
  eg: "{a,b,c}ddddd{e,f}" -> 1 + 5 + 1 == 7
- Solve backward...
*/

class Solution {
public:
    vector<string> expand(string s) {
        std::vector<std::string> result(1);
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '{') {
                string_view view(s);
                auto options = get_options(view.substr(i+1, s.find('}', i) - i - 1));
                int original_size = result.size();
                duplicate(result, options.size());
                for (int j = 0; j < result.size(); ++j) {
                    // i + 1 to skip the '{'
                    // 2 * (j / original_size) is the offset for the next option. eg: {a,b} -> option a, then option b
                    result[j].push_back(s[i + 1 + (2 * (j / original_size))]);
                }
                i += options.size() * 2;
            } else {
                for (auto& s : result) {
                    s.push_back(c);
                }
            }
        }
        // TODO: expensive (although it beats 100%?). find a way to build the result with sorted strings
        std::sort(result.begin(), result.end());
        return result;
    }

    void duplicate(std::vector<std::string>& collection, int n) {
        int original_length = collection.size();
        collection.reserve(original_length * n);
        auto end = std::next(collection.begin(), original_length);
        while (--n) {
            std::copy(collection.begin(), end, std::back_inserter(collection));
        }
    }

    string get_options(string_view options) {
        string result;
        for (auto c : options) {
            if (c != ',') {
                result.push_back(c);
            }
        }
        //std::sort(result.begin(), result.end()); // not needed as I am sorting at the end
        return result;
    }
};
