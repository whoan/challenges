// https://leetcode.com/problems/spiral-matrix-iv/
// Medium

// great solution

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int left_corner = 0, top_corner = 0, right_corner = n-1, bottom_corner = m-1;
        int row = 0, col = 0;
        while (head) {
            // go right
            for (col = left_corner; head && col <= right_corner; ++col) {
                matrix[row][col] = head->val;
                head = head->next;
            }
            --col;
            ++top_corner;
            // go down
            for (row = top_corner; head && row <= bottom_corner; ++row) {
                matrix[row][col] = head->val;
                head = head->next;
            }
            --row;
            --right_corner;
            // left
            for (col = right_corner; head && col >= left_corner; --col) {
                matrix[row][col] = head->val;
                head = head->next;
            }
            ++col;
            --bottom_corner;
            // up
            for (row = bottom_corner; head && row >= top_corner; --row) {
                matrix[row][col] = head->val;
                head = head->next;
            }
            ++row;
            ++left_corner;
        }
        return matrix;
    }
};

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
