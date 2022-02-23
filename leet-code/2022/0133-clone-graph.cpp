// https://leetcode.com/problems/clone-graph/
// Medium

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// also look at good DFS solution: https://leetcode.com/problems/clone-graph/discuss/42313/C%2B%2B-BFSDFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        unordered_set<Node*> seen;
        std::queue<Node*> queue;
        std::vector<Node*> nodes(101, nullptr);
        queue.push(node);
        nodes[node->val] = new Node(node->val);
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            bool should_insert = nodes[current->val]->neighbors.empty();
            for (auto neighbor : current->neighbors) {
                if (!nodes[neighbor->val]) {
                    nodes[neighbor->val] = new Node(neighbor->val);
                }
                if (should_insert) {
                    nodes[current->val]->neighbors.push_back(nodes[neighbor->val]);
                }
                if (seen.insert(neighbor).second) {
                    queue.push(neighbor);
                }
            }
        }
        return nodes[node->val];
    }
};
