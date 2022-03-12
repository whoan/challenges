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

// great solution: https://leetcode.com/problems/copy-list-with-random-pointer/discuss/811151/Extremely-simple-solution-using-C%2B%2B

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


class AlternativeSolution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> old_new;
        auto old_node = head;
        auto new_head = old_new.insert({old_node, new Node(old_node->val)}).first->second;
        auto new_node = new_head;

        while (old_node) {
            decltype(old_new)::iterator it;
            bool inserted = false;

            if (old_node->random) {
                std::tie(it, inserted) = old_new.insert({old_node->random, nullptr});
                if (inserted) {
                    it->second = new Node(old_node->random->val);
                }
                new_node->random = it->second;
            }

            if (old_node->next) {
                std::tie(it, inserted) = old_new.insert({old_node->next, nullptr});
                if (inserted) {
                    it->second = new Node(old_node->next->val);
                }
                new_node->next = it->second;
            }

            old_node = old_node->next;
            new_node = new_node->next;
        }
        return new_head;
    }
};


class SlightlyCleanerSolution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> old_new;
        auto new_head = old_new.emplace(old_node, new Node(old_node->val)).first->second;

        auto old_node = head;
        auto new_node = new_head;
        while (old_node) {
            if (old_node->random) {
                auto [it, inserted] = old_new.emplace(old_node->random, nullptr);
                if (inserted) {
                    it->second = new Node(old_node->random->val);
                }
                new_node->random = it->second;
            }

            if (old_node->next) {
                auto [it, inserted] = old_new.emplace(old_node->next, nullptr);
                if (inserted) {
                    it->second = new Node(old_node->next->val);
                }
                new_node->next = it->second;
            }

            old_node = old_node->next;
            new_node = new_node->next;
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
