//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:

    bool binarySearchCols(vector<vector<int>>&matrix, int target, int row) {
        int cols = matrix[row].size();

        int low = 0, high = cols - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == matrix[row][mid]) {
                return true;
            }
            else if (target > matrix[row][mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
    int binarySearchRows(vector<vector<int>>&matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0, high = rows - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target >= matrix[mid][0] and target <=  matrix[mid][cols - 1]) { //if target lies in current(i.e mid) row
                return mid;
            }
            else if (target >  matrix[mid][cols - 1]) { //find in below rows
                low = mid + 1;
            }
            else { //find in upper rows
                high = mid - 1;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = 0;
        if (rows > 0) {
            cols = matrix[0].size();
        }
        if (rows == 0 or cols == 0) {
            return false;
        }

        int possibleRow = binarySearchRows(matrix, target);
        if (possibleRow == -1) {
            return false;
        }
        bool found = binarySearchCols(matrix, target, possibleRow);
        return found;
    }
};




