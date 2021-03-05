// https://leetcode.com/problems/clone-graph/

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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        vector<Node*> cache;
        queue<Node*> queue;

        if (!node) {
            cache.reserve(1);
            cache.push_back(nullptr);
        } else {
            queue.push(node);
            cache.resize(node->val, nullptr);
            cache[node->val-1] = new Node(node->val);
        }

        while (not queue.empty()) {
            Node* current = queue.front();
            queue.pop();
            for (auto neighbor : current->neighbors) {
                if (cache.size() < neighbor->val) {
                    cache.resize(neighbor->val, nullptr);
                }
                if (!cache[neighbor->val-1]) {
                    cache[neighbor->val-1] = new Node(neighbor->val);
                    queue.push(neighbor);
                }
                cache[current->val-1]->neighbors.push_back(cache[neighbor->val-1]);
            }
        }
        return cache[0];
    }
};
