// https://leetcode.com/problems/accounts-merge/
// Medium

class UnionFind {
    std::array<int, 1000> tree;
public:
    UnionFind() {
        std::ranges::iota(tree, 0);
    }

    void _union(int p, int q) {
        tree[find(p)] = find(q);
    }

    int find(int p) {
        int root = p;
        while (root != tree[root]) {
            root = tree[root];
        }
        // optimization
        while (p != tree[p]) {
            std::tie(p, tree[p]) = {tree[p], root};
        }
        return root;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map<std::string, int> mails;
        UnionFind uf;
        for (int i = 0; i < accounts.size(); ++i) {
            auto& account = accounts[i];
            for (int j = 1; j < account.size(); ++j) {
                auto& mail = account[j];
                if (auto it = mails.find(mail); it != mails.end()) {
                    uf._union(it->second, i);
                    mail.clear();
                } else {
                    mails[mail] = i;
                }
            }
        }
        // merge accounts
        for (int i = 0; i < accounts.size(); ++i) {
            auto& account = accounts[i];
            if (int root = uf.find(i); root != i) {
                for (int j = 1; j < account.size(); ++j) {
                    accounts[root].push_back(std::move(account[j]));
                }
                account.clear();
            }
        }
        // remove empty emails
        for (int i = 0; i < accounts.size(); ++i) {
            accounts[i].erase(
                std::remove_if(accounts[i].begin()+1, accounts[i].end(), [] (auto& v) { return v.empty(); }),
                accounts[i].end()
            );
        }
        // remove merged accounts
        accounts.erase(
            std::remove_if(accounts.begin(), accounts.end(), [] (auto& v) { return v.empty(); }),
            accounts.end()
        );
        // sort everything
        std::ranges::sort(accounts);
        for (int i = 0; i < accounts.size(); ++i) {
            auto& account = accounts[i];
            std::sort(account.begin()+1, account.end());
        }
        return std::move(accounts);
    }
};
