// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
// Medium

// nvm, better look at this great solution: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/discuss/932914/Java-in-6-lines
// look at this comment to understand solution: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/discuss/932914/Java-in-6-lines/1094642

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        std::unordered_set<Node*> seen;
        seen.insert(p);
        while (p->parent) {
            p = p->parent;
            seen.insert(p);
        }
        while (!seen.count(q)) {
            q = q->parent;
        }
        return q;
    }
};
