// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Medium

class Solution {
    vector<int> answer;
    std::vector<TreeNode*> path;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        for (find_path(root, target); !path.empty(); --k) {
            auto* node = path.back(); path.pop_back();
            dfs(node, k);
            if (!path.empty()) {
                if (path.back()->left == node) {
                    path.back()->left = nullptr;
                } else {
                    path.back()->right = nullptr;
                }
            }
        }
        return std::move(answer);
    }

private:
    bool find_path(TreeNode* node, TreeNode* target) {
        if (!node) {
            return false;
        }
        path.push_back(node);
        if (node == target || find_path(node->left, target) || find_path(node->right, target)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    void dfs(TreeNode* node, int k) {
        if (!node) {
            return;
        }
        if (k == 0) {
            answer.push_back(node->val);
            return;
        }
        dfs(node->left, k-1);
        dfs(node->right, k-1);
    }
};
