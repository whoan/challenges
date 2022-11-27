// https://leetcode.com/problems/unique-email-addresses/
// Easy

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_set<string> unique;
        for (auto& email : emails) {
            auto name = get_canonical_name(email);
            auto domain = get_domain(email);
            unique.insert(name + domain);
        }
        return unique.size();
    }
private:
    string get_canonical_name(string& email) {
        static string chars = "+@";
        string name(
            email.begin(),
            find_first_of(email.begin(), email.end(), chars.begin(), chars.end())
        );
        name.erase(remove(name.begin(), name.end(), '.'), name.end());
        return name;
    }

    string get_domain(string& email) {
        return {find(email.begin(), email.end(), '@'), email.end()};
    }
};

// improvement #1
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_set<string> unique;
        for (auto& email : emails) {
            auto name = get_canonical_name(email);
            auto domain = get_domain(email);
            unique.insert(name + domain);
        }
        return unique.size();
    }
private:
    string get_canonical_name(string& email) {
        static string chars = "+@";
        auto end_name = find_first_of(email.begin(), email.end(), chars.begin(), chars.end());
        auto new_end = remove(email.begin(), end_name, '.');
        return {email.begin(), new_end};
    }

    string get_domain(string& email) {
        return {find(email.begin(), email.end(), '@'), email.end()};
    }
};

// improvement #2 (no extra strings)
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::unordered_map<string_view, std::unordered_set<string_view>> unique;
        for (auto& email : emails) {
            unique[get_domain(email)].insert(get_canonical_name(email));
        }
        return std::accumulate(unique.begin(), unique.end(), 0, [] (int acc, auto& set) {
            return acc + set.second.size();
        });
    }
private:
    string_view get_canonical_name(string& email) {
        static string chars = "+@";
        auto end_name = find_first_of(email.begin(), email.end(), chars.begin(), chars.end());
        auto new_end = remove(email.begin(), end_name, '.');
        return string_view(email.c_str(), std::distance(email.begin(), new_end));
    }

    string_view get_domain(string& email) {
        return string_view(email).substr(email.find('@'));
    }
};
