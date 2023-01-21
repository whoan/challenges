// https://leetcode.com/problems/restore-ip-addresses/
// Medium

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0);
        return move(result);
    }

private:
    void backtrack(const string& s, int s_index, int section) {
        if (s_index == s.size() && section == 4) {
            result.push_back(ip);
            return;
        }
        for (int digits=1; digits < 4 && s_index+digits <= s.size(); ++digits) {
            string n_string = s.substr(s_index, digits);
            if ((digits == 2 && s[s_index] == '0') || (digits == 3 && n_string >= "256")) {
                break;
            }
            bool put_dot = section < 3;
            ip.append(move(n_string));
            ip.append(put_dot, '.');
            backtrack(s, s_index+digits, section+1);
            ip.resize(ip.size()-digits-put_dot);
        }
    }

    string ip;
    vector<string> result;
};
