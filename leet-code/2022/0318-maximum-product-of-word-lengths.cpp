// https://leetcode.com/problems/maximum-product-of-word-lengths/
// Medium

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<std::pair<int, int>> lengths;
        lengths.reserve(words.size());
        int max = 0;
        for (auto& word : words) {
            int current_mask = get_mask(word);
            for (auto [mask, length] : lengths) { // N^2
                max = std::max(max, int(!(current_mask & mask) * (length * word.size())));
            }
            lengths.push_back({current_mask, word.size()});
        }
        return max;
    }

private:
    int get_mask(string& s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c-'a');
        }
        return mask;
    }
};

class SortingSolution {
public:
    int maxProduct(vector<string>& words) {
        vector<std::pair<int, int>> lengths;
        lengths.reserve(words.size());
        std::sort(words.begin(), words.end(), [] (string& s, string& t) {
            return s.size() > t.size();
        });
        int max = 0;
        for (auto& word : words) {
            int current_mask = get_mask(word);
            for (auto [mask, length] : lengths) { // N^2
                if (!(current_mask & mask) && max < (length * word.size())) {
                    max = length * word.size();
                    break;
                }
            }
            lengths.push_back({current_mask, word.size()});
        }
        return max;
    }

private:
    int get_mask(string& s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c-'a');
        }
        return mask;
    }
};

class StdSolution {
public:
    int maxProduct(vector<string>& words) {
        vector<std::pair<int, int>> lengths;
        lengths.reserve(words.size());
        std::sort(words.begin(), words.end(), [] (string& s, string& t) {
            return s.size() > t.size();
        });
        std::transform(
            words.begin(),
            words.end(),
            std::back_inserter(lengths),
            [this] (string& s) { return make_pair(get_mask(s), s.size()); }
        );
        int max = 0;
        for (int i = 0; i < lengths.size(); ++i) {
            auto [mask, length] = lengths[i];
            for (int j = i+1; j < lengths.size(); ++j) {
                if (!(lengths[j].first & mask)) {
                    max = std::max(max, lengths[j].second * length);
                    break;
                }
            }
        }
        return max;
    }

private:
    int get_mask(string& s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c-'a');
        }
        return mask;
    }
};

// inefficient use of hash table
class FirstSolution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> lengths;
        int max = 0;
        for (auto& word : words) {
            int current_mask = get_mask(word);
            auto [it, inserted] = lengths.emplace(current_mask, word.size());
            if (!inserted && it->second < word.size()) {
                lengths.insert_or_assign(it, current_mask, word.size());
            }
            // N^2
            for (auto [mask, length] : lengths) {
                max = std::max(max, int(!(current_mask & mask) * (length * word.size())));
            }
        }
        return max;
    }

private:
    int get_mask(string& s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c-'a');
        }
        return mask;
    }
};

/*
Test data:
["adbbfacdbaa","edadaad","bdacabaca","dcdfd","adaeccafad","eafffeea","ccac","ddbddfafddd","dfc","ac","dacbaef","afce","abffa","eaaa","dfcfefe","dddccdbcd","cade","abdcf","bd","cdeda","bed","abbcbdac","feeabc","abebdf","bfdfd","afaac","bcbfcbc","dbdb","cbcbfccfc","cdbfdffcea","ecbdecbba","efadcc","dc","efbabcfcbd","eecbfcf","affdc","eafebcba","cbff","debcacdcd","debfebdfd","fadfafddf","cfeddafecce","cddac","faaef","fcbecba","bbdabbd","fe","dd","feecdbacae","feedbcbacfc","bda","ee","fcdfea","daebccaaf","bad","ffbb","deacbbcdb","ebfdadcaa","defe","acfefccffc","bdbcebbfb","dfcaadaedde","aabf","aeccfefba","ffbd","dbdd","ff","dcffabce","abbeeed","fd","ceaeeac","ecefdefbf","fcbfffbd","ccdfb","fbd","cbad","dbbebececdb","fedcf","eac","bacbbbfaec","bdeabbdccd","ffabcedad","edeefedd","bdfedfeebcb","efefbefbdcc","ecdefc","cddffeeb","daaad","afedff","ddaaeceae","ecade","befddafda","caacca","aabdcfd","edcddbbdbfd","dfefcab","bc","ce","ffeaaeffc","eb","fcd","caeaccaebdf","ddcb","ffbeafefcd","ecf","cf...
*/
