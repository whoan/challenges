// https://leetcode.com/problems/design-sql/
// Medium -> Felt Easy

class SQL {
public:
    SQL(vector<string>& names, vector<int>& columns) {
        tables.reserve(names.size());
    }

    void insertRow(string name, vector<string> row) {
        tables[std::move(name)].push_back(std::move(row));
    }

    void deleteRow(string name, int rowId) {
        //tables[name][rowId-1].clear();
    }

    string selectCell(string name, int rowId, int columnId) {
        return tables[name][rowId-1][columnId-1];
    }

private:
    using RowT = vector<string>;
    unordered_map<string, vector<RowT>> tables;
};
