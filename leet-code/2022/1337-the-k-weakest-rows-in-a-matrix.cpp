// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Easy

// heap approach: cleaner one but wasn't faster than the other solutions
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        enum {STRENGTH, INDEX};
        std::priority_queue<std::pair<int, int>> heap;
        for (int index = 0; index < mat.size(); ++index) {
            auto& row = mat[index];
            heap.emplace(
                // STRENGTH
                std::distance(
                    row.begin(),
                    std::lower_bound(row.begin(), row.end(), 0, std::greater<int>())
                ),
                index
            );
            if (index >= k) {
                heap.pop();
            }
        }

        std::vector<int> result(k);
        for (int i = k-1; i >= 0; --i) {
            result[i] = std::get<INDEX>(heap.top());
            heap.pop();
        };
        return result;
    }
};

class FinalSortingSolution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        enum {STRENGTH, INDEX};
        for (int i = 0; i < mat.size(); ++i) {
            auto& row = mat[i];
            row[STRENGTH] = std::distance(
                row.begin(),
                std::lower_bound(row.begin(), row.end(), 0, std::greater<int>())
            );
            row[INDEX] = i;
        }

        // see https://youtu.be/-0tO3Eni2uo?t=305
        my_partial_sort(mat, k, [] (auto& v1, auto& v2) {
            return make_pair(v1[STRENGTH], v1[INDEX]) < make_pair(v2[STRENGTH], v2[INDEX]);
        });

        std::vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i) result.push_back(mat[i][INDEX]);
        return result;
    }

    template<typename Collection, typename Callable>
    void my_partial_sort(Collection& collection, int k, Callable comparator) {
        std::nth_element(collection.begin(), std::next(collection.begin(), k), collection.end(), comparator);
        std::sort(collection.begin(), std::next(collection.begin(), k), comparator);
    }
};

class OptimalCustomPartialSortSolution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        constexpr int max_rows = 100;
        enum {STRENGTH, INDEX};
        for (int i = 0; i < mat.size(); ++i) {
            auto& row = mat[i];
            row[STRENGTH] = std::distance(
                row.begin(),
                std::lower_bound(row.begin(), row.end(), 0, std::greater<int>())
            ) * max_rows + i; // trick to give more weight to elements with equal # of soldiers but bigger index
            row[INDEX] = i;
        }
        // see https://youtu.be/-0tO3Eni2uo?t=305
        my_partial_sort(mat, k, [] (auto& v1, auto& v2) {
            return v1[STRENGTH] < v2[STRENGTH];
        });

        // a for might end up being cleaner, but transform is more expressive (?)
        std::vector<int> result;
        result.reserve(k);
        std::transform(
            mat.begin(),
            std::next(mat.begin(), k),
            std::back_inserter(result),
            [] (const auto& row) { return row.at(INDEX); }
        );
        return result;
    }

    template<typename Collection, typename Callable>
    void my_partial_sort(Collection& collection, int k, Callable comparator) {
        std::nth_element(collection.begin(), std::next(collection.begin(), k), collection.end(), comparator);
        std::sort(collection.begin(), std::next(collection.begin(), k), comparator);
    }
};

class PartialSortSolution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        enum {STRENGTH, INDEX};
        for (int i = 0; i < mat.size(); ++i) {
            auto& row = mat[i];
            row[STRENGTH] = std::distance(
                row.begin(),
                std::lower_bound(row.begin(), row.end(), 0, std::greater<int>())
            ) * 100 + i;
            row[INDEX] = i;
        }
        // partial_sort might actually be slower in practice: https://youtu.be/-0tO3Eni2uo?t=135
        std::partial_sort(mat.begin(), next(mat.begin(), k), mat.end(), [] (auto& v1, auto& v2) {
            return v1[STRENGTH] < v2[STRENGTH];
        });
        std::vector<int> result;
        result.reserve(k);
        std::transform(
            mat.begin(),
            std::next(mat.begin(), k),
            std::back_inserter(result),
            [] (const auto& row) { return row.at(INDEX); }
        );
        return result;
    }
};

class StableSortSolution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        enum {STRENGTH, INDEX};
        for (int i = 0; i < mat.size(); ++i) {
            auto& row = mat[i];
            row[STRENGTH] = std::distance(
                row.begin(),
                std::lower_bound(row.begin(), row.end(), 0, std::greater<int>())
            );
            row[INDEX] = i;
        }
         // TODO: Do a partial_sort instead and then push the elements to result in this way:
        // - if strength is != mat[k-1][STRENGTH], push right away
        // - otherwise, look for elements with strength == mat[k-1][STRENGTH] and push the ones with smaller indices
        // - update: disregard the optimization as its complex and second scenario (point above) might be tricky/expensive
        std::stable_sort(mat.begin(), mat.end(), [] (auto& v1, auto& v2) {
            return v1[STRENGTH] < v2[STRENGTH];
        });
        std::vector<int> result;
        result.reserve(k);
        std::transform(
            mat.begin(),
            std::next(mat.begin(), k),
            std::back_inserter(result),
            [] (const auto& row) { return row.at(INDEX); }
        );
        return result;
    }
};

// didn't use binary search
class NaiveSolution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        enum {STRENGTH, INDEX};
        for (int i = 0; i < mat.size(); ++i) {
            auto& row = mat[i];
            row[STRENGTH] = std::distance(row.begin(), std::find(row.begin(), row.end(), 0));
            row[INDEX] = i;
        }
        std::stable_sort(mat.begin(), mat.end(), [] (auto& v1, auto& v2) {
            return v1[STRENGTH] < v2[STRENGTH];
        });
        std::vector<int> result;
        result.reserve(k);
        std::transform(
            mat.begin(),
            std::next(mat.begin(), k),
            std::back_inserter(result),
            [] (const auto& row) { return row.at(INDEX); }
        );
        return result;
    }
};

/*
Test data:
[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]
3
[[1,0,0,0],[1,1,1,1],[1,0,0,0],[1,0,0,0]]
2
*/
