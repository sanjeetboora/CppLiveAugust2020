#include <bits/stdc++.h>
using namespace std;


//O(n^2)
int SumAllSubmatrices3(int arr[10][10], int rows, int cols) {


	int totalSum = 0;
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			int topLeftCells = (r + 1) * (c + 1);
			int bottomRightCells = (rows - r) * (cols - c);

			int currCellContribution = topLeftCells * bottomRightCells * arr[r][c];
			totalSum += currCellContribution;

		}

	}
	return totalSum;

}

int main(int argc, char const *argv[])
{
	int rows = 3, cols = 4; //solution 2500
	int arr[10][10] = {
		{1, 2, 3 , 4},
		{11, 12, 13 , 14},
		{21, 22, 23 , 24}
	};

	// int rows = 2, cols = 2;
	// int arr[10][10] = {
	// 	{1, 1},
	// 	{1, 1}
	// };
	int sum = SumAllSubmatrices3(arr, rows, cols);
	cout << sum << endl;

	return 0;
}