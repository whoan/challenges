// https://leetcode.com/problems/satisfiability-of-equality-equations/
// Medium

class UnionFind {
    std::string equality;
public:
    UnionFind() {
        equality.resize('z'+1);
        for (char c = 'a'; c <= 'z'; ++c) {
            equality[c] = c;
        }
    }

    void union_(char one, char another) {
        // check the smaller branch?
        equality[find_(one)] = find_(another);
    }

    char find_(char c) {
        while (equality[c] != c) {
            c = equality[c];
        }
        // compress equality?
        return c;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf;
        for (auto& equation : equations) {
            if (equation[1] == '=') {
                uf.union_(equation[0], equation[3]);
            }
        }
        for (auto& equation : equations) {
            if (equation[1] == '!' && uf.find_(equation[0]) == uf.find_(equation[3])) {
                return false;
            }
        }
        return true;
    }
};

/*
Test data:
["f==a","a==b","f!=e","a==c","b==e","c==f"]
["a==b","b!=a"]
["b==a","a==b"]
["a==b","b!=c","c==a"]
["c==c","b==d","x!=z"]
*/
