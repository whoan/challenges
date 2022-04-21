// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
// Medium

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto new_node = new Node(insertVal);
        if (!head) {
            head = new_node;
            head->next = head;
            return head;
        }
        auto current = head;
        if (current != current->next) {
            while (true) {
                if (current->next == head) {
                    break;
                }
                bool found_sweet_spot = current->val <= insertVal && current->next->val > insertVal;
                bool found_corner = current->val > current->next->val && (
                    insertVal >= current->val || insertVal < current->next->val);
                if (found_sweet_spot || found_corner) {
                    break;
                }
                current = current->next;
            }
        }
        std::tie(current->next, new_node->next) = make_pair(new_node, current->next);
        return head;
    }
};

/*
Test data:
[3,4,1]
2
[]
1
[1]
0
[3,3,3]
0
[3,5,1]
0
[3,5,1]
6
*/
