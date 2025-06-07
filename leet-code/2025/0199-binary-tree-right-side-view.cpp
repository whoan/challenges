// https://leetcode.com/problems/binary-tree-right-side-view/
// Medium

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            decltype(queue) level_queue;
            answer.push_back(queue.front()->val);
            for (; !queue.empty(); queue.pop()) {
                auto* node = queue.front();
                if (node->right) {
                    level_queue.push(node->right);
                }
                if (node->left) {
                    level_queue.push(node->left);
                }
            }
            std::swap(queue, level_queue);
        }
        return answer;
    }
};
