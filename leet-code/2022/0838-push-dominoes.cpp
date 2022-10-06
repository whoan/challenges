// https://leetcode.com/problems/push-dominoes/
// Medium

class Solution {
public:
    string pushDominoes(string dominoes) {
        auto find_force = [] (char c) { return c == 'L' || c == 'R'; };
        auto prev = dominoes.begin(),
             cur  = std::find_if(dominoes.begin(), dominoes.end(), find_force),
             end  = dominoes.end();
        while (prev != end) {
            if (*prev == '.' && *cur == 'L') {
                std::fill(prev, cur, 'L');
            } else if (*prev == 'R' && cur == end) {
                std::fill(prev, cur, 'R');
            } else if (*prev == *cur) {
                std::fill(prev, cur, *prev);
            } else if (*prev == 'R') {
                int half_size = (std::distance(prev, cur)+1)/2;
                std::fill(prev, std::next(prev, half_size), *prev);
                std::fill(std::reverse_iterator(cur+1), std::reverse_iterator(std::prev(cur+1, half_size)), *cur);
            }
            std::tie(prev, cur) = make_pair(cur, std::find_if(std::next(cur), end, find_force));
        }
        return dominoes;
    }
};

class ShorterButLessClearSolution {
public:
    string pushDominoes(string dominoes) {
        auto find_force = [] (char c) { return c == 'L' || c == 'R'; };
        auto prev = dominoes.begin(), cur = std::find_if(dominoes.begin(), dominoes.end(), find_force);
        while (cur != dominoes.end()) {
            if ((*prev == '.' && *cur == 'L') || *prev == *cur) {
                std::fill(prev, cur, *cur);
            } else if (*prev == 'R') {
                int half_size = (std::distance(prev, cur)+1)/2;
                std::fill(prev, std::next(prev, half_size), *prev);
                std::fill(std::reverse_iterator(cur+1), std::reverse_iterator(std::prev(cur+1, half_size)), *cur);
            }
            std::tie(prev, cur) = make_pair(cur, std::find_if(std::next(cur), dominoes.end(), find_force));
        }
        if (*prev == 'R') {
            std::fill(std::next(prev), cur, 'R');
        }
        return dominoes;
    }
};

class FirstSolution {
public:
    string pushDominoes(string dominoes) {
        auto cur = dominoes.begin(), end = dominoes.end();
        char prev_value = 'L'; // force of element -1
        auto prev = std::prev(cur); // will never be dereferenciated, so it's fine
        auto find_force = [] (char c) { return c == 'L' || c == 'R'; };
        for (cur = std::find_if(cur, end, find_force); cur != end; cur = std::find_if(std::next(cur), end, find_force)) {
            if (prev_value == *cur) {
                std::fill(std::next(prev), cur, *cur);
            } else if (prev_value == 'R') {
                int half_size = (std::distance(prev, cur)+1)/2;
                std::fill(prev, std::next(prev, half_size), prev_value);
                std::fill(std::reverse_iterator(cur+1), std::reverse_iterator(std::prev(cur+1, half_size)), *cur);
            }
            prev = cur;
            prev_value = *cur;
        }
        if (prev_value == 'R') {
            std::fill(std::next(prev), cur, 'R');
        }
        return dominoes;
    }
};

/*
Test data:
"RR.L"
".L.R...LR..L.."
".L.R."
".R..L."
*/
