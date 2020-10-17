//https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = 0;
        if (r > 0) {
            c = matrix[0].size();
        }
        if (r == 0 or c == 0) {
            return false;
        }

        for (int i = 0; i < r; i++) {
            if (matrix[i][0] <= target and matrix[i][c - 1] >= target) {
                bool exist = binary_search(matrix[i].begin(), matrix[i].end(), target);
                if (exist) {
                    return true;
                }
            }
        }
        return false;
    }
};