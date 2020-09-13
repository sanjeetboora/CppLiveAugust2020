#include <bits/stdc++.h>
using namespace std;


void printAllSubmatrices(int arr[10][10], int rows, int cols) {

	//tlr = top left row
	//tlc = top left col
	//brr = bottom right row
	//brc = bottom right col
	//to generate all top left

	int maximumSum = 0;
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
					//to print a submatrix
					int submatrixSum = 0;
					for (int r = tlr; r <= brr ; r++)
					{
						for (int c = tlc; c <= brc; ++c)
						{
							cout << arr[r][c] << ", ";
							submatrixSum += arr[r][c];
						}
					}
					maximumSum = max(maximumSum, submatrixSum);
					cout << endl;

				}
			}
			cout << endl;
		}
	}
	cout << maximumSum << endl;

}

int main(int argc, char const *argv[])
{
	int rows = 3, cols = 4;
	int arr[10][10] = {
		{1, 2, 3 , 4},
		{ -11, -12, -13 , -14},
		{ -21, -22, -23 , -24}
	};

	printAllSubmatrices(arr, rows, cols);
	return 0;
}