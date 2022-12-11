// https://leetcode.com/problems/leaf-similar-trees/
// Easy

class HalfSpaceSolution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> values; values.reserve(std::log2(200));
        bool insert = true;
        dfs(root1, values, insert);
        std::reverse(values.begin(), values.end());
        return dfs(root2, values, !insert) && values.empty();
    }
private:
    bool dfs(TreeNode* node, std::vector<int>& values, bool insert) {
        if (!node) {
            return true;
        }
        if (!node->left && !node->right) {
            if (insert) {
                values.push_back(node->val);
            } else {
                if (values.empty() || values.back() != node->val) {
                    return false;
                }
                values.pop_back();
            }
        }
        return dfs(node->left, values, insert) && dfs(node->right, values, insert);
    }
};

class FirstSolution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         std::vector<int> values1; values1.reserve(std::log2(200));
         dfs(root1, values1);
         std::vector<int> values2; values2.reserve(std::log2(200));
         dfs(root2, values2);
        return values1 == values2;
    }
private:
    void dfs(TreeNode* node, std::vector<int>& values) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            values.push_back(node->val);
        }
        dfs(node->left, values);
        dfs(node->right, values);
    }
};
