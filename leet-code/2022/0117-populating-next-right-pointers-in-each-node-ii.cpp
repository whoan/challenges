// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Medium

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            auto first = current;
            while (!queue.empty()) {
                current->next = queue.front();
                queue.pop();
                current = current->next;
            }
            for (current = first; current; current = current->next) {
                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }
            }
        }
        return root;
    }
};

// notice that it uses `queue.size()` which I am not sure if that's part of Queue ADT
class AlternativeSolution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> queue;
        queue.push(root);
        Node prev_dummy;
        while (!queue.empty()) {
            auto prev = &prev_dummy;
            for (auto size = queue.size(); size; --size) {
                auto node = queue.front();
                queue.pop();
                if (!node) {
                    continue;
                }
                prev->next = node;
                queue.push(node->left);
                queue.push(node->right);
                prev = node;
            }
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
