// 02-add-two-numbers: https://leetcode.com/problems/add-two-numbers/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class SolutionUsingNewList {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currentNode = nullptr;
        ListNode* head = nullptr;
        for (int remainder = 0; remainder || l1 || l2; forward(&l1), forward(&l2)) {
            // optimization
            if (not remainder && (not l1 || not l2)) {
                currentNode->next = l1 ? l1 : l2;
                break;
            }
            int sumResult = remainder + getValue(l1) + getValue(l2);
            currentNode = addNode(currentNode, sumResult % 10);
            if (not head) {
                head = currentNode;
            }
            remainder = sumResult > 9; // same as sumResut / 10 but should be faster
        }
        return head;
    }

private:
    int getValue(ListNode* li) {
        return li ? li->val : 0;
    }

    ListNode* addNode(ListNode* li, int value) {
        if (not li) {
            return new ListNode(value);
        }
        return li->next = new ListNode(value);
    }

    void forward(ListNode** li) {
        if (*li) {
            *li = (*li)->next;
        }
    }
};

// almost the same as above
class SolutionUsingNewList2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currentNode = nullptr;
        ListNode* head = nullptr;
        int remainder = 0;
        for (; l1 || l2; forward(&l1), forward(&l2)) {
            // optimization
            if (not remainder && (not l1 || not l2)) {
                currentNode->next = l1 ? l1 : l2;
                break;
            }
            int sumResult = remainder + getValue(l1) + getValue(l2);
            currentNode = addNode(currentNode, sumResult % 10);
            if (not head) {
                head = currentNode;
            }
            remainder = sumResult > 9; // same as sumResut / 10 but should be faster
        }
        if (remainder) {
            currentNode = addNode(currentNode, remainder);
        }

        return head;
    }

private:
    int getValue(ListNode* li) {
        return li ? li->val : 0;
    }

    ListNode* addNode(ListNode* li, int value) {
        if (not li) {
            return new ListNode(value);
        }
        return li->next = new ListNode(value);
    }

    void forward(ListNode** li) {
        if (*li) {
            *li = (*li)->next;
        }
    }
};


class SolutionUpdatingInputList {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        for (int remainder = 0; l1 || l2; forward(&l1), forward(&l2)) {
            int sumResult = remainder + getValue(l1) + getValue(l2);
            updateNode(l1, sumResult % 10);
            remainder = sumResult > 9; // same as sumResut / 10 but should be faster

            if (not l1->next) {
                if (l2) {
                    l1->next = l2->next;
                    l2->next = nullptr;
                }
                if (remainder && not l1->next) {
                    l1->next = new ListNode(remainder);
                    break;
                }
            }
        }
        return head;
    }

private:
    int getValue(ListNode* li) {
        return li ? li->val : 0;
    }

    void updateNode(ListNode* li, int value) {
        li->val = value;
    }

    void forward(ListNode** li) {
        if (*li) {
            *li = (*li)->next;
        }
    }
};
