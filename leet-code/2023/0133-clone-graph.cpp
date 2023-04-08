// https://leetcode.com/problems/clone-graph/
// Medium

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return node;
        }
        std::vector<Node*> graph(101, nullptr);
        std::queue<Node*> q;
        q.push(node);
        graph[node->val] = new Node(node->val);
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            for (Node* neighbor : node->neighbors) {
                if (!graph[neighbor->val]) {
                    graph[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                graph[node->val]->neighbors.push_back(graph[neighbor->val]);
            }
        }
        return graph[1];
    }
};
