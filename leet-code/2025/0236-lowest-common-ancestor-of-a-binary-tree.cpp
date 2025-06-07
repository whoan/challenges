// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Medium

// just another approach to use less storage
class Solution {
    std::stack<TreeNode*> path;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_path(root, p);
        auto copy = path;
        while (!copy.empty()) {
            path = std::stack<TreeNode*>();
            if (find_path(copy.top(), q)) {
                return copy.top();
            }
            copy.pop();
        }
        return root;
    }
private:
    bool find_path(TreeNode* node, TreeNode* target) {
        if (node == nullptr) {
            return false;
        }
        path.push(node);
        if (node == target || find_path(node->left, target) || find_path(node->right, target)) {
            return true;
        }
        path.pop();
        return false;
    }
};

// same as above but modifying tree to avoid recursing over visited nodes
class Solution {
    std::stack<TreeNode*> path;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_path(root, p);
        auto copy = path;
        while (!copy.empty()) {
            path = std::stack<TreeNode*>();
            auto subtree_root = copy.top(); copy.pop();
            if (find_path(subtree_root, q)) {
                return subtree_root;
            }
            if (!copy.empty()) {
                if (copy.top()->left == subtree_root) {
                    copy.top()->left = nullptr;
                } else {
                    copy.top()->right = nullptr;
                }
            }
        }
        return root;
    }
private:
    bool find_path(TreeNode* node, TreeNode* target) {
        if (node == nullptr) {
            return false;
        }
        path.push(node);
        if (node == target || find_path(node->left, target) || find_path(node->right, target)) {
            return true;
        }
        path.pop();
        return false;
    }
};

// approach similar to the one I recall from an old interview at Amazon
// this was the way suggested by the interviewer
class Solution {
    std::vector<std::vector<TreeNode*>> roots;
    int index = 0;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        roots.resize(2);
        dfs(root, p);
        ++index;
        dfs(root, q);
        int i = 0;
        int min_size = std::min(roots[0].size(), roots[1].size());
        while (i < min_size && roots[0][i] == roots[1][i]) {
            ++i;
        }
        return roots[0][i-1];
    }

private:
    bool dfs(TreeNode* node, TreeNode* target) {
        if (node == nullptr) {
            return false;
        }
        roots[index].push_back(node);
        if (node == target || dfs(node->left, target) || dfs(node->right, target)) {
            return true;
        }
        roots[index].pop_back();
        return false;
    }
};

