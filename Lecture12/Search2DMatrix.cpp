//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        int r = 0, c = cols - 1;
        while (r >= 0 and r < rows and c<cols and c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            else if (target > matrix[r][c]) {
                r++;
            }
            else {
                c--;
            }
        }
        return false;
    }
};