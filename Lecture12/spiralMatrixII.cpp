//https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > matrix;

        for (int i = 0; i < n; i++) {
            vector<int> v(n, 0);
            matrix.push_back(v);
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << matrix[i][j] << ", ";
            }
            cout << endl;
        }

        int startRow = 0, startCol = 0, endRow = n - 1, endCol = n - 1;
        int value = 1;

        while (startRow <= endRow and startCol <= endCol) {
            //traverse start row
            int x = startCol;
            while (x <= endCol) {
                matrix[startRow][x] = value;
                value++;
                x++;
            }
            startRow++;

            //traverse end col
            x = startRow;
            while (x <= endRow) {
                matrix[x][endCol] = value;
                value++;
                x++;
            }
            endCol--;

            //traverse end row
            x = endCol;
            while (x >= startCol) {
                matrix[endRow][x] = value;
                value++;
                x--;
            }
            endRow--;

            //traverse start col
            x = endRow;
            while (x >= startRow) {
                matrix[x][startCol] = value;
                value++;
                x--;
            }
            startCol++;
        }
        return matrix;
    }
};





