// https://leetcode.com/problems/accounts-merge/
// Medium

// This solution is similar to the weighted quick-union implementation from:
// Robert Sedgewick and Kevin Wayne - Algorithms, 4th edition (pg. 227) (**)
class WeightedQuickUnionSolution {

    class UnionFind {
        // this is the representation of the tree
        std::array<int, 1000> ids;
        // this is to know which tree to append to the other to guarantee log
        std::array<size_t, 1000> sizes;
    public:
        UnionFind(int n) {
            for (int i = 0; i < n; ++i) {
                ids[i] = i;
                sizes[i] = 1;
            }
        }

        // (**)
        void weighted_quick_union(int old_id, int new_id) {
            int new_root = find(new_id);
            int old_root = find(old_id);
            if (sizes[new_root] < sizes[old_root]) {
                ids[new_root] = old_root;
                sizes[old_root] += sizes[new_root];
            } else {
                ids[old_root] = new_root;
                sizes[new_root] += sizes[old_root];
            }
        }

        int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // register root of each email and create UnionFind object to track relations
        UnionFind union_find(accounts.size());
        std::unordered_map<string, int> mail_root;
        for (int root_id = 0; root_id < accounts.size(); ++root_id) {
            auto& account = accounts[root_id];
            for (int j = 1; j < account.size(); ++j) {
                auto& mail = account[j];
                auto [it, inserted] = mail_root.emplace(std::move(mail), root_id);
                if (!inserted) {
                    union_find.weighted_quick_union(it->second, root_id);
                }
            }
        }

        // reuse input vector (maintaining account owners)
        for (auto& account : accounts) {
            account.resize(1);
        }

        // merge emails per account
        for (auto& [mail, id] : mail_root) {
            auto& account = accounts[union_find.find(id)];
            account.push_back(std::move(mail));
        }

        // remove empty accounts (the ones that were "unioned" and now only contain owner name)
        accounts.erase(
            std::remove_if(accounts.begin(), accounts.end(), [] (const auto& account) {
                return account.size() == 1;
            }),
            accounts.end()
        );

        // sort emails in the accounts to satisfy condition
        for (auto& account : accounts) {
            std::sort(std::next(account.begin()), account.end());
        }

        return std::move(accounts);
    }
};

// This solution is similar to the quick-union implementation from:
// Robert Sedgewick and Kevin Wayne - Algorithms, 4th edition (pg. 224) (*)
class QuickUnionSolution {

    class UnionFind {
        // this is the representation of the tree
        std::array<int, 1000> ids; // you can also use a vector here
    public:
        UnionFind(int n) {
            for (int i = 0; i < n; ++i) {
                ids[i] = i;
            }
        }

        // (*)
        void quick_union(int old_id, int new_id) {
            ids[find(new_id)] = find(old_id);
        }

        int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // register root of each email and create UnionFind object to track relations
        UnionFind union_find(accounts.size());
        std::unordered_map<string, int> mail_root;
        for (int root_id = 0; root_id < accounts.size(); ++root_id) {
            auto& account = accounts[root_id];
            for (int j = 1; j < account.size(); ++j) {
                auto& mail = account[j];
                auto [it, inserted] = mail_root.emplace(std::move(mail), root_id);
                if (!inserted) {
                    union_find.quick_union(it->second, root_id);
                }
            }
        }

        // reuse input vector (maintaining account owners)
        for (auto& account : accounts) {
            account.resize(1);
        }

        // merge emails per account
        for (auto& [mail, id] : mail_root) {
            auto& account = accounts[union_find.find(id)];
            account.push_back(std::move(mail));
        }

        // remove empty accounts (the ones that were "unioned" and now only contain owner name)
        accounts.erase(
            std::remove_if(accounts.begin(), accounts.end(), [] (const auto& account) {
                return account.size() == 1;
            }),
            accounts.end()
        );

        // sort emails in the accounts to satisfy condition
        for (auto& account : accounts) {
            std::sort(std::next(account.begin()), account.end());
        }

        return std::move(accounts);
    }
};

class HorribleAndInefficientSolution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        using Emails = unordered_set<string>;
        vector<pair<string, Emails>> account_emails;
        account_emails.reserve(accounts.size());
        for (auto& account : accounts) {
            account_emails.push_back(make_pair(account[0], Emails()));
            auto& emails = account_emails.back().second;
            for (int i = 1; i < account.size(); ++i) {
                emails.insert(std::move(account[i]));
            }
        }

        vector<vector<string>> result;
        while (account_emails.size()) {
            auto last = std::move(account_emails.back());
            account_emails.pop_back();
            for (auto& [account, emails] : account_emails) {
                auto found = std::find_if(emails.begin(), emails.end(), [&last] (auto& email) {
                    return last.second.count(email);
                });
                if (found != emails.end()) {
                    std::copy(
                        last.second.begin(),
                        last.second.end(),
                        std::inserter(emails, emails.end())
                    );
                    last.second.clear();
                    break;
                }
            }
            if (!last.second.empty()) {
                std::vector<string> account;
                account.reserve(last.second.size()+1);
                account.push_back(std::move(last.first));
                for (auto& email_to_move : last.second) {
                    account.push_back(std::move(email_to_move));
                }
                std::sort(std::next(account.begin()), account.end());
                result.push_back(std::move(account));
            }
        }
        return result;
    }
};

class NaiveAndNonWorkingSolution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int, unordered_set<string>> buffer;
        for (size_t i=0; i < accounts.size(); ++i) {
            auto& account = accounts[i];
            size_t index = i;
            for (size_t email_idx=1; email_idx < account.size(); ++email_idx) {
                for (auto& [account_idx, emails] : buffer) {
                    if (emails.count(account[email_idx])) {
                        index = account_idx;
                        break;
                    }
                }
            }

            for (size_t email_idx=1; email_idx < account.size(); ++email_idx) {
                buffer[index].insert(std::move(account[email_idx]));
            }
        }

        vector<vector<string>> result;
        for (auto& [index, emails] : buffer) {
            result.push_back(std::vector<string>());
            result.back().push_back(std::move(accounts[index].front()));
            for (auto &email : emails) {
                result.back().push_back(std::move(email));
            }
            std::sort(std::next(result.back().begin()), result.back().end());
        }
        return result;
    }
};

/*
Test data:
[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
[["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
[["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]]
[["David","David0@m.co","David4@m.co","David3@m.co"],["David","David5@m.co","David5@m.co","David0@m.co"],["David","David1@m.co","David4@m.co","David0@m.co"],["David","David0@m.co","David1@m.co","David3@m.co"],["David","David4@m.co","David1@m.co","David3@m.co"]]
[["Alex","Alex2@m.co","Alex6@m.co","Alex1@m.co","Alex5@m.co","Alex9@m.co"],["Alex","Alex9@m.co","Alex4@m.co","Alex3@m.co","Alex0@m.co","Alex11@m.co"],["Alex","Alex9@m.co","Alex5@m.co","Alex6@m.co","Alex7@m.co","Alex12@m.co"],["Alex","Alex6@m.co","Alex5@m.co","Alex12@m.co","Alex11@m.co","Alex10@m.co"],["Alex","Alex1@m.co","Alex5@m.co","Alex10@m.co","Alex9@m.co","Alex11@m.co"],["Alex","Alex9@m.co","Alex5@m.co","Alex1@m.co","Alex3@m.co","Alex1@m.co"],["Alex","Alex10@m.co","Alex0@m.co","Alex3@m.co","Alex0@m.co","Alex0@m.co"],["Alex","Alex7@m.co","Alex3@m.co","Alex6@m.co","Alex7@m.co","Alex2@m.co"],["Alex","Alex8@m.co","Alex6@m.co","Alex4@m.co","Alex6@m.co","Alex2@m.co"],["Alex","Alex10@m.co","Alex9@m.co","Alex11@m.co","Alex10@m.co","Alex9@m.co"],["Alex","Alex0@m.co","Alex2@m.co","Alex9@m.co","Alex1@m.co","Alex6@m.co"],["Alex","Alex6@m.co","Alex5@m.co","Alex7@m.co","Alex8@m.co","Alex10@m.co"]]

*/
