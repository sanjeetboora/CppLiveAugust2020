#include <bits/stdc++.h>
using namespace std;

void prefixSumMatrix(int arr[10][10], int rows, int cols) {

	int tlr = 0, tlc = 0, sum = 0;

	//row-wise sum
	for (int r = 0; r < rows ; r++)
	{
		for (int c = 1; c < cols; c++)
		{
			arr[r][c] = arr[r][c] + arr[r][c - 1];
		}
	}
	//col-wise sum
	for (int r = 1; r < rows ; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			arr[r][c] = arr[r][c] + arr[r - 1][c];
		}
	}

}


int maxSumSubMatrix(int arr[10][10], int rows, int cols) {

	//tlr = top left row
	//tlc = top left col
	//brr = bottom right row
	//brc = bottom right col
	//to generate all top left
	int maxSum = 0;
	for (int tlr = 0; tlr < rows; ++tlr)
	{
		for (int tlc = 0; tlc < cols; ++tlc)
		{
			cout << arr[tlr][tlc] << "==> ";
			//to generate all bottom right
			for (int brr = tlr; brr < rows ; ++brr)
			{
				for (int brc = tlc; brc < cols ; ++brc)
				{
					cout << arr[brr][brc] << " --> ";

					int currSubMatrixSum = arr[brr][brc];

					//remove top extra rows
					if (tlr > 0) {
						currSubMatrixSum -= arr[tlr - 1][brc];
					}
					//remove left extra columns
					if (tlc > 0) {
						currSubMatrixSum -= arr[brr][tlc - 1];
					}

					//add 2 times removed part
					if (tlr > 0 and tlc > 0) {
						currSubMatrixSum += arr[tlr - 1][tlc - 1];
					}

					maxSum = max(maxSum, currSubMatrixSum);
				}
			}
			cout << endl;
		}
	}
	return maxSum;

}

int main(int argc, char const *argv[])
{
	// int rows = 3, cols = 4; //solution 2500
	// int arr[10][10] = {
	// 	{1, 2, 3 , 4},
	// 	{11, 12, 13 , 14},
	// 	{21, 22, 23 , 24}
	// };

	int rows = 2, cols = 2;
	int arr[10][10] = {
		{1, 1},
		{1, 1}
	};

	prefixSumMatrix(arr, rows, cols);
	int sum = maxSumSubMatrix(arr, rows, cols);
	cout << sum << endl;

	return 0;
}