// https://leetcode.com/problems/linked-list-in-binary-tree/
// Medium

class Solution {
    std::vector<TreeNode*> roots;

    void collect_roots(int val, TreeNode* root) {
        if (!root) {
            return;
        }
        if (val == root->val) {
            roots.push_back(root);
        }
        collect_roots(val, root->left);
        collect_roots(val, root->right);
    }

    bool find_path(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root) {
            return false;
        }
        if (root->val != head->val) {
            return false;
        }
        return find_path(head->next, root->left) || find_path(head->next, root->right);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        collect_roots(head->val, root);
        return std::ranges::any_of(roots, [this, head] (TreeNode* root) {
            return find_path(head, root);
        });
    }
};
