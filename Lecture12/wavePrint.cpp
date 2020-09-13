#include <bits/stdc++.h>
using namespace std;
void printMatrix(int rows, int cols, int**arr) {
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}
}


void wavePrint(int rows, int cols, int** arr) {

	for (int c = 0; c < cols; ++c)
	{
		// cout << arr[0][c] << ", ";

		if (c & 1) { // column no. is odd

			for (int r = rows - 1; r >= 0 ; r--)
			{
				cout << arr[r][c] << ", ";
			}
		}
		else { // column no. is even
			for (int r = 0; r < rows ; r++)
			{
				cout << arr[r][c] << ", ";
			}
		}

	}
	cout << endl;

}



int main(int argc, char const *argv[])
{
	int rows = 3, cols = 5;
	int** arr = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int [cols];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			arr[i][j] = (i * 10) + (j + 1);
		}
	}
	printMatrix(rows, cols, arr);
	wavePrint(rows, cols, arr);


	return 0;
}


//H.W. Rowwise WavePrint

