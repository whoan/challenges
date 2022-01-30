// https://leetcode.com/problems/rotate-array/
// Medium

/*
- use last k bytes as the buffer
- change k bytes at a time from the beginning
- if the remaining bytes to change are less than k

1,2 3,4 5,6
5,6 3,4 1,2
5,6 1,2 3,4

1,2 3 4,5
4,5 3 1,2
4,5 1 3,2
4,5 1 2,3

1,2,3 4 5,6,7
5,6,7 4 1,2,3
5,6,7 1 4,2,3
5,6,7 1 2,4,3
5,6,7 1 2,3,4

1,2,3 4,5 6,7,8
6,7,8 4,5 1,2,3
6,7,8 1,2 4,5,3
6,7,8 1,2 3,5,4
6,7,8 1,2 3,4,5


1,2,3,4,5,6,7,8
7,8,3,4,5,6,1,2
7,8,1,2,5,6,3,4
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k >= nums.size()) {
            k %= nums.size();
        }
        for (int i=0, j=nums.size()-k; j < nums.size(); ) {
            while (j < nums.size()) {
                std::swap(nums[i++], nums[j++]);
            }
            k %= (j-i);
            j -= k;
        }
    }
};

/*
Test data:
[1,2,3,4,5,6]
4
[1,2]
3
[1,2,3,4,5,6,7,8]
1
[1,2,3,4,5,6,7,8]
2
[1,2,3,4,5,6,7,8]
3
*/
