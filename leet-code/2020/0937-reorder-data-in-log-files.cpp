// https://leetcode.com/problems/reorder-data-in-log-files/

/*
1- iterate through the logs and save the digit ones in a temporary vector
2- reorder the letter logs in the original array
3- push the digit logs into the original array
*/

class SolutionNotThatSimple {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs;
        digitLogs.reserve(logs.size());

        // move digit logs to a temporary vector
        for (auto& log : logs) {
            if (isDigitLog(log)) {
                digitLogs.push_back(std::move(log));
            }
        }

        // remove the moved logs (empty now)
        logs.erase(
            remove_if(begin(logs), end(logs), [] (const auto& log) { return empty(log); }),
            end(logs)
        );

        // sort the letter logs
        sort(begin(logs), end(logs), [this] (const auto& a, const auto& b) {
            return compareLetterLogs(a, b);
        });

        // append the digit logs in the original order
        move(begin(digitLogs), end(digitLogs), back_inserter(logs));

        return move(logs);
    }

private:
    bool isDigitLog(const string& log) const {
        auto posActualLog = log.find(' ') + 1;
        return isdigit(log.at(posActualLog));
    }

    string_view getActualLog(const string& log) const {
        auto posActualLog = log.find(' ') + 1;
        return string_view(log.data()+posActualLog, size(log)-posActualLog);
    }

    string_view getIdentifier(const string& log) const {
        auto posSeparator = log.find(' ');
        return string_view(log.data(), posSeparator);
    }

    bool compareLetterLogs(const string& left, const string& right) {
        auto leftView = getActualLog(left);
        auto rightView = getActualLog(right);
        return (leftView == rightView && getIdentifier(left) < getIdentifier(right)) ||
            leftView < rightView;
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto it = stable_partition(begin(logs), end(logs), [this] (const auto& log) {
            return !isDigitLog(log);
        });
        sort(begin(logs), it, [this] (const auto& a, const auto& b) {
            return compareLetterLogs(a, b);
        });
        return move(logs);
    }

private:
    bool isDigitLog(const string& log) const {
        auto posActualLog = log.find(' ') + 1;
        return isdigit(log.at(posActualLog));
    }

    string_view getIdentifier(const string& log) const {
        auto posSeparator = log.find(' ');
        return string_view(log.data(), posSeparator);
    }

    string_view getActualLog(const string& log) const {
        auto posActualLog = log.find(' ') + 1;
        return string_view(log.data()+posActualLog, size(log)-posActualLog);
    }

    bool compareLetterLogs(const string& left, const string& right) {
        auto leftView = getActualLog(left);
        auto rightView = getActualLog(right);
        return (leftView == rightView && getIdentifier(left) < getIdentifier(right)) ||
            leftView < rightView;
    }
};
