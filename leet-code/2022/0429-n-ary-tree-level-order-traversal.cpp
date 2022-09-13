// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Medium

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            decltype(queue) level_nodes;
            vector<int> level_values;
            while (!queue.empty()) {
                auto node = queue.front(); queue.pop();
                level_values.push_back(node->val);
                for (auto child : node->children) {
                    level_nodes.push(child);
                }
            }
            result.push_back(move(level_values));
            queue.swap(level_nodes);
        }
        return result;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
