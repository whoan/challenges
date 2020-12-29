// https://leetcode.com/problems/minimum-window-substring/

/*
1- insert the elements from t in a bag B
2- look for the next start element S in s which belong to B
3- form that point, move a pointer from S until we find the last element in B (a copy of it)
4- if the length is shorter than current (or infinite), save it
5- repeat from step 2
*/

class SlowSolution {
public:
    string minWindow(string s, string t) {
        saveInBag(t);
        string result;
        for (size_t left=0; left < s.size()-(t.size()-1); ++left) {
            if (not isInBag(s[left])) {
                continue;
            }

            auto view = string_view(s.data()+left, s.size()-left);
            auto shortest = lookForShortestWindow(view);
            //std::cout << "shortest: " << shortest << std::endl;
            if (shortest.empty()) {
                break;
            }
            if (result.empty() || shortest.size() < result.size()) {
                result = shortest;
            }
        }
        return result;
    }

private:
    void saveInBag(string s) {
        for (char c : s) {
            ++bag[c];
        }
    }

    bool isInBag(char current) const {
        return bag.count(current);
    }

    string_view lookForShortestWindow(string_view view) {
        //std::cout << "view: " << view << std::endl;
        auto copiedBag = bag;
        for (size_t i(0); i < view.size(); ++i) {
            char c = view[i];
            if (copiedBag.count(c)) {
                if (--copiedBag[c] == 0) {
                    copiedBag.erase(c);
                }
                if (copiedBag.empty()) {
                    view.remove_suffix(view.size()-(i+1));
                    return view;
                }
            }
        }
        return string_view();
    }

    unordered_map<char, size_t> bag;
};
