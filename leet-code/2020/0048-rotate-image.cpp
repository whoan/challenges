// https://leetcode.com/problems/rotate-image

/*
1- Go frame by frame (frames are the swuares and subsquares) and apply rotate character algorithm
2- rotateCharacter takes an element at a position in the north side, and move it to the east side
3- do the same moving from east to south
4- the same from south to west
5- the same from west to north
6- repeat for each character
7- do the same for subsquare
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto matrixSize = matrix.size();
        for (std::size_t subsquare=0; subsquare < matrixSize/2; ++subsquare) {
            for (std::size_t i=subsquare; i < matrixSize-subsquare-1; ++i) {
                int toRotate = matrix.at(subsquare).at(i);
                std::swap(matrix.at(i).at(matrixSize-subsquare-1), toRotate);
                std::swap(matrix.at(matrixSize-subsquare-1).at(matrixSize-i-1), toRotate);
                std::swap(matrix.at(matrixSize-i-1).at(subsquare), toRotate);
                std::swap(matrix.at(subsquare).at(i), toRotate);
            }
        }
    }
};
