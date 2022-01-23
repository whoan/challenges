// https://leetcode.com/problems/copy-list-with-random-pointer/
// Medium

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> map;
        auto current = head;
        auto new_head = new Node(head->val);
        auto new_current = new_head;

        map[head] = new_head;
        while (current) {
            if (current->next) {
                new_current->next = new Node(current->next->val);
                map[current->next] = new_current->next;
            }
            current = current->next;
            new_current = new_current->next;
        }

        current = head;
        new_current = new_head;
        while (current) {
            new_current->random = map[current->random];
            current = current->next;
            new_current = new_current->next;
        }

        return new_head;
    }
};

/*
Test data:
[[7,null],[13,0],[11,4],[10,2],[1,0]]
[[1,1],[2,1]]
[[3,null],[3,0],[3,null]]
*/
