// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Hard

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::queue<std::pair<int, TreeNode*>> main_queue;
        main_queue.push({0, root});
        std::unordered_map<int, std::vector<int>> main_map;
        int min_column = 0, max_column = 0;
        while (!main_queue.empty()) {
            std::queue<std::pair<int, TreeNode*>> level_queue;
            std::unordered_map<int, std::vector<int>> level_map;
            while (!main_queue.empty()) {
                auto [column, node] = main_queue.front();
                main_queue.pop();
                level_map[column].push_back(node->val);
                if (node->left) {
                    level_queue.push({column-1, node->left});
                }
                if (node->right) {
                    level_queue.push({column+1, node->right});
                }
                min_column = std::min(min_column, column);
                max_column = std::max(max_column, column);
            }
            // copy sorted values per level to the main DS
            for (auto& [column, values] : level_map) {
                std::sort(values.begin(), values.end());
                std::copy(values.begin(), values.end(), std::back_inserter(main_map[column]));
            }
            std::swap(main_queue, level_queue);
        }
        // "transform" DSs to satisfy return type
        vector<vector<int>> result;
        while (min_column <= max_column) {
            result.push_back(vector<int>());
            result.back().reserve(main_map[min_column].size());
            std::copy(main_map[min_column].begin(), main_map[min_column].end(), std::back_inserter(result.back()));
            ++min_column;
        }
        return result;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Test data:
[3,1,4,0,2,2]
*/
