//https://leetcode.com/problems/spiral-matrix/submissions/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        if (rows == 0) {
            return result;
        }
        int cols = matrix[0].size();

        //print matrix
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << matrix[i][j] << ", ";
            }
            cout << endl;
        }

        int startRow = 0, startCol = 0, endRow = rows - 1, endCol = cols - 1;

        while (startRow <= endRow and startCol <= endCol) {
            //traverse start row
            int x = startCol;
            while (x <= endCol) {
                result.push_back(matrix[startRow][x]);
                x++;
            }
            startRow++;

            //traverse end col
            x = startRow;
            while (x <= endRow) {
                result.push_back(matrix[x][endCol]);
                x++;
            }
            endCol--;

            //traverse end row
            if (startRow <= endRow) {
                x = endCol;
                while (x >= startCol) {
                    result.push_back(matrix[endRow][x]);
                    x--;
                }
                endRow--;
            }

            if (startCol <= endCol) {
                //traverse start col
                x = endRow;
                while (x >= startRow) {
                    result.push_back(matrix[x][startCol]);
                    x--;
                }
                startCol++;
            }
        }
        return result;

    }
};