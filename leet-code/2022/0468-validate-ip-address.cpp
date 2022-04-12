// https://leetcode.com/problems/validate-ip-address/
// Medium

bool valid_ipv4_token(std::string_view token) {
    if (token.empty() ||
        (token.front() == '0' && token.size() > 1) ||
        token.size() > 3 ||
        !std::all_of(token.begin(), token.end(), [] (char c) { return std::isdigit(c); }))
    {
        return false;
    }
    int n = std::stoi(string(token)); // expensive but shorter than using std::from_chars
    return !(n < 0 || n > 255);
}

bool valid_ipv6_token(std::string_view token) {
    return token.size() &&
           token.size() <= 4 &&
           std::all_of(token.begin(), token.end(), [] (char c) { return std::isxdigit(c); });
}

class Solution {
public:
    string validIPAddress(string queryIP) {
        auto tokens = split(queryIP);
        if (tokens.size() == 4) {
            return std::all_of(tokens.begin(), tokens.end(), valid_ipv4_token) ? "IPv4" : "Neither";
        }
        if (tokens.size() == 8) {
            return std::all_of(tokens.begin(), tokens.end(), valid_ipv6_token) ? "IPv6" : "Neither";
        }
        return "Neither";
    }

    std::vector<std::string_view> split(std::string& input) {
        std::vector<std::string_view> result;

        char separator = '.';
        int pos = input.find(separator);
        if (pos == std::string::npos) {
            separator = ':';
            pos = input.find(separator);
            if (pos == std::string::npos) {
                return result;
            }
        }

        size_t start = 0;
        for (; pos != std::string::npos; pos = input.find(separator, start)) {
            result.push_back(std::string_view(input).substr(start, pos-start));
            start = pos + 1;
        }
        result.push_back(std::string_view(input).substr(start, pos-start));
        return result;
    }
};

/*
"2001:db8:85a3:0::8a2E:0370:7334"  -> this is not a valid IPv6? - thought that "::" was valid -> https://en.wikipedia.org/wiki/IPv6#Address_representation

Test data:
f:f:f:f:f:f:f:f"
"2001:db8:85a3:0::8a2E:0370:7334"
"1.1.1.1"
"172.16.254.1"
"2001:0db8:85a3:0:0:8A2E:0370:7334"
"256.256.256.256"
"172.16.254.1.1.1"
""
"."
".."
"..."
"....."
"........"
*/
