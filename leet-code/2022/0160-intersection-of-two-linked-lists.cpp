// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Easy

// good solution: https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!

/*
Algorithm of my solution:
1. Initialize node_a and node_b to point to head_a and head_b respectively

  head_a
    |
  node_a
    |
    a1 -> a2 -> c1 -> c2 -> null
          b1 -> c1 -> c2 -> null
          |
        node_b
          |
        head_b

2. Iterate over both lists until we are done with the shorter one (list b in this case):

  head_a             node_a
    |                  |
    a1 -> a2 -> c1 -> c2 -> null
          b1 -> c1 -> c2 -> null
          |                  |
        head_b             node_b

3. Continue Iterating over the larger one until the end, but also "reducing" it (moving head_a in this case):

        head_a             node_a
          |                  |
    a1 -> a2 -> c1 -> c2 -> null
          b1 -> c1 -> c2 -> null
          |                  |
        head_b             node_b


4. The iterate again from head_a and head_b until both nodes are the same (don't use `val` for the comparison as they are not unique)

              head_a       node_a
                |            |
    a1 -> a2 -> c1 -> c2 -> null
          b1 -> c1 -> c2 -> null
                |            |
              head_b       node_b

5. Return either head_b or head_b
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head_a, ListNode *head_b) {
        for (auto node_a = head_a, node_b = head_b; node_a || node_b; ) {
            if (node_a) {
                node_a = node_a->next;
            } else {
                head_b = head_b->next;
            }
            if (node_b) {
                node_b = node_b->next;
            } else {
                head_a = head_a->next;
            }
        }
        while (head_a != head_b) {
            head_a = head_a->next;
            head_b = head_b->next;
        }
        return head_a;
    }
};

class AlternativeSolution {
public:
    ListNode *getIntersectionNode(ListNode *head_a, ListNode *head_b) {
        int length_a = 0, length_b = 0;
        // calculate length of lists
        for (auto node = head_a; node; ++length_a) {
            node = node->next;
        }
        for (auto node = head_b; node; ++length_b) {
            node = node->next;
        }
        // update lists to have same length
        for (; length_a > length_b; --length_a) {
            head_a = head_a->next;
        }
        for (; length_b > length_a; --length_b) {
            head_b = head_b->next;
        }
        // iterate until nodes match
        while (head_a != head_b) {
            head_a = head_a->next;
            head_b = head_b->next;
        }
        return head_a;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
