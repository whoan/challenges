// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Medium

class SlowSolution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        std::vector<std::vector<int>> table(nums1.size()+1, std::vector<int>(nums2.size()+1, 0));
        int max = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                table[i+1][j+1] = (nums1[i] == nums2[j])*(table[i][j] + 1);
                max = std::max(max, table[i+1][j+1]);
            }
        }
        return max;
    }
};

// nop
struct TrieNode {
    bool leaf;
    std::array<TrieNode*, 101> children;
    TrieNode(bool leaf=false) : leaf(leaf), children({}) {}
};

class WrongSolution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        TrieNode root;
        for (int i = 0; i < nums1.size(); ++i) {
            auto current = &root;
            for (int j = i; j < nums1.size(); ++j) {
                if (!current->children[nums1[j]]) {
                    current->children[nums1[j]] = new TrieNode();
                }
                current = current->children[nums1[j]];
            }
            current->leaf = true;
        }
        int max = 0;
        for (int i = 0; i < nums2.size(); ++i) {
            int candidate = 0;
            for (auto current = &root; current->children[nums2[i]]; current = current->children[nums2[i]]) {
                ++candidate;
            }
            max = std::max(max, candidate);
        }
        return max;
    }
};

/*
Test data:
[1]
[2]
[1,1,1,1,1]
[1,1,1,1,2]
[0,1,1,1,1]
[1,0,1,0,1]
[1,2,3,2,1]
[3,2,1,4,7]
[0,0,0,0,0]
[0,0,0,0,0]
*/
