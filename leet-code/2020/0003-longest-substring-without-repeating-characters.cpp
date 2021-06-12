// 03-longest-substring-without-repeating-characters: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Terrible solutions!

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        for (std::size_t i(0); i < s.size(); ++i) {
            char currentChar = s[i];
            auto [seen, where] = alreadySeen(currentChar);
            if (not seen) {
                setAsSeen(currentChar, i);
                longest = std::max(longest, int(whichWhere.size()));
            } else {
                cleanSeenUpTo(where);
                setAsSeen(currentChar, i);
            }
        }
        return longest;
    }
private:
    std::unordered_map<char, std::size_t> whichWhere;

    void setAsSeen(char which, std::size_t where) {
        whichWhere[which] = where;
    }

    std::pair<bool, std::size_t> alreadySeen(char which) {
        if (whichWhere.count(which)) {
            return std::make_pair(true, whichWhere[which]);
        }
        return std::make_pair(false, char());
    }
    
    void cleanSeenUpTo(std::size_t targetWhere) {
        // TODO: optimize this with a vector
        for (auto it = std::begin(whichWhere); it != std::end(whichWhere); ) {
            if (it->second <= targetWhere) {
                it = whichWhere.erase(it);
            } else {
                ++it;
            }
        }
    }
};

class Window {
public:
    Window(char* start) : start(start) {}

    void incrementSize() { ++size; }

    std::string_view removePrefix(int n) {
        std::string_view prefix(start + startIndex, n);
        startIndex += n;
        size -= n;
        return prefix;
    }

    std::size_t getStartIndex() const { return startIndex; }
    std::size_t getSize() const { return size; }

private:
    char* start;
    std::size_t startIndex = 0;
    std::size_t size = 0;
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        Window window(s.data());
        for (std::size_t i(0); i < s.size(); ++i) {
            char currentChar = s[i];
            auto [seen, where] = alreadySeen(currentChar);
            if (seen) {
                auto prefix = window.removePrefix(i - window.getStartIndex());
                cleanSeen(prefix);
            }
            setAsSeen(currentChar, i);
            window.incrementSize();
        }
        return window.getSize();
    }
private:
    std::unordered_map<char, std::size_t> whichWhere;

    std::size_t calculatePrefixSize(std::size_t currentIndexOriginal, std::size_t curentWindowSize, std::size_t repeatedIndexOriginal) const {
        return repeatedIndexOriginal - (currentIndexOriginal - curentWindowSize);
    }

    void setAsSeen(char which, std::size_t where) {
        whichWhere[which] = where;
    }

    std::pair<bool, std::size_t> alreadySeen(char which) {
        if (whichWhere.count(which)) {
            return std::make_pair(true, whichWhere[which]);
        }
        return std::make_pair(false, char());
    }
    
    void cleanSeen(std::string_view prefix) {
        for (auto a : prefix) {
            whichWhere.erase(a);
        }
    }
};
