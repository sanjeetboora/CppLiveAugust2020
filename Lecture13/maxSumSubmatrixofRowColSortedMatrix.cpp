#include <bits/stdc++.h>
using namespace std;

void suffixSumMatrix(int arr[10][10], int rows, int cols) {
	rows = rows - 1;
	cols = cols - 1;

	//row-wise sum
	for (int r = rows; r >= 0; r--)
	{
		for (int c = cols - 1; c >= 0; c--)
		{
			arr[r][c] += arr[r][c + 1];

		}

	}
	//col-wise sum
	for (int r = rows - 1; r >= 0; r--)
	{
		for (int c = cols; c >= 0; c--)
		{
			arr[r][c] += arr[r + 1][c ];

		}

	}
}

//O(n^2)
int maxSumSubmatrix(int arr[10][10], int rows, int cols) {


	int maxSum = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			maxSum = max(maxSum, arr[r][c]);

		}

	}
	return maxSum;

}

int main(int argc, char const *argv[])
{
	int rows = 3, cols = 4; //solution 2500
	int arr[10][10] = {
		{ -15, -10, -5 , -3},
		{ -2, 0, 1 , 2},
		{5, 7, 9 , 10}
	};

	suffixSumMatrix(arr, rows, cols);
	int sum = maxSumSubmatrix(arr, rows, cols);
	cout << sum << endl;

	return 0;
}