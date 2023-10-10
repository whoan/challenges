// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
// Medium

// better solution: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/solutions/932914/java-in-6-lines/

// better?
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        if (is_leaf_of(p, q)) {
            return p;
        }
        p->left = nullptr;
        p->right = nullptr;
        return lowestCommonAncestor(p->parent, q);
    }

private:
    bool is_leaf_of(Node* root, Node *node) {
        if (!root) {
            return false;
        }
        return root == node
            || is_leaf_of(root->left, node)
            || is_leaf_of(root->right, node)
        ;
    }
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        if (is_leaf_of(p, q)) {
            return p;
        }
        q->left = nullptr;
        q->right = nullptr;
        if (is_leaf_of(q, p)) {
            return q;
        }
        p->left = nullptr;
        p->right = nullptr;
        return lowestCommonAncestor(p->parent, q);
    }

private:
    bool is_leaf_of(Node* root, Node *node) {
        if (!root) {
            return false;
        }
        return root == node
            || is_leaf_of(root->left, node)
            || is_leaf_of(root->right, node)
        ;
    }
};
