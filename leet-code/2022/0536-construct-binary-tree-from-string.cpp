// https://leetcode.com/problems/construct-binary-tree-from-string/
// Medium

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
class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) {
            return nullptr;
        }
        return view2tree(string_view(s));
    }

private:
    TreeNode* view2tree(std::string_view view) {
        auto open = view.find('(');
        auto root = new TreeNode(vtoi(view.substr(0, open)));
        if (open == std::string_view::npos) {
            return root;
        }

        // process left child
        view.remove_prefix(open);
        auto close = find_matching_brace(view);
        root->left = view2tree(view.substr(1, close-1));

        // process right child
        view.remove_prefix(close+1);
        if (!view.empty()) {
            root->right = view2tree(view.substr(1, view.size()-2));
        }
        return root;
    }

    std::size_t find_matching_brace(std::string_view view) {
        int opening = 1;
        int close = 1;
        for (; opening && close < view.size(); ++close) {
            if (view[close] == '(') {
                ++opening;
            } else if (view[close] == ')') {
                --opening;
            }
        }
        return close-1;
    }

    int vtoi(string_view number) {
        int result = 0;
        int multiplier = number.front() == '-' ? -1 : 1;
        if (multiplier == -1) {
            number.remove_prefix(1);
        }
        for (int i = 0; i < number.size(); ++i) {
            result = result * 10 + number[i]-'0';
        }
        return result * multiplier;
    }
};

/*
Test data:
"48(2(3)(1))(6(5))"
"4(2(3)(1))(6(5)(7))"
"-4(2(3)(1))(6(5)(7))"
""
*/
