// https://leetcode.com/problems/apply-discount-to-prices/
// Medium

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        auto words = split(sentence);
        string result;
        for (auto word : words) {
            result.append(!result.empty(), ' ');
            auto [price, is_price] = get_price(word);
            if (is_price) {
                price -= price*(double(discount)/100);
                result.push_back('$');
                std::ostringstream s;
                s << std::fixed << std::setprecision(2) << price;
                result += s.str();
            } else {
                result += word;
            }
        }
        return result;
    }

private:
    std::pair<double, bool> get_price(string_view token) {
        if (token.empty() || token[0] != '$') {
            return {0, false};
        }
        token.remove_prefix(1);
        try {
            size_t count = 0;
            double result = std::stod(string(token), &count);
            return {result, token.size() == count};
        } catch (...) {
            return {0, false};
        }
    }

    std::vector<std::string_view> split(std::string_view input) const {
        std::vector<std::string_view> tokens;
        std:size_t start = 0;
        for (auto pos = input.find(' '); pos != std::string_view::npos; pos = input.find(' ', start)) {
            tokens.push_back(input.substr(start, pos-start));
            start = pos + 1;
        }
        tokens.push_back(input.substr(start));
        return tokens;
    }
};

class ManualSolution {
public:
    string discountPrices(string sentence, int discount) {
        auto words = split(sentence);
        string result;
        for (auto word : words) {
            result.append(!result.empty(), ' ');
            auto [price, is_price] = get_price(word);
            if (is_price) {
                price -= price*(double(discount)/100);
                result.push_back('$');
                std::ostringstream s;
                s << std::fixed << std::setprecision(2) << price;
                result += s.str();
            } else {
                result += word;
            }
        }
        return result;
    }

private:
    std::pair<double, bool> get_price(string_view token) {
        if (token.empty() || token[0] != '$') {
            return {0, false};
        }
        token.remove_prefix(1);
        auto pos = token.find('.');
        auto [integer, is] = is_integer(token.substr(0, pos));
        double result = integer;
        if (is && pos != std::string_view::npos) {
            auto [new_int, still_is] = is_integer(token.substr(pos+1));
            if (!still_is) {
                return {0, false};
            }
            result += double(new_int)/100;
        }
        return {result, is*result};
    }

    std::pair<long, bool> is_integer(string_view token) {
        if (!std::all_of(token.begin(), token.end(), [] (char c) { return std::isdigit(c); })) {
            return {0, false};
        }
        long result = 0;
        for (int i = 0; i < token.size(); ++i) {
            result *= 10;
            result += token[i]-'0';
        }
        return {result, true};
    }

    std::vector<std::string_view> split(std::string_view input) const {
        std::vector<std::string_view> tokens;
        std:size_t start = 0;
        for (auto pos = input.find(' '); pos != std::string_view::npos; pos = input.find(' ', start)) {
            tokens.push_back(input.substr(start, pos-start));
            start = pos + 1;
        }
        tokens.push_back(input.substr(start));
        return tokens;
    }
};

/*
Test data:
"$76111 ab $6 $"
48
"there are $1 $2 and 5$ candies in the shop"
50
"1 2 $3 4 $5 $6 7 8$ $9 $10$"
100
"$7383692 5q $5870426"
64
"706hzu76jjh7yufr5x9ot60v149k5 $7651913186 pw2o $6"
28
*/
