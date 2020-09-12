#include <bits/stdc++.h>
using namespace  std;

int main(int argc, char const *argv[])
{
	int rows = 3, cols = 4;

	//stack
	int arr[3][4]; //declaration

	//initialization
	int arr1[3][4] = {{1, 2, 3, 4},
		{11, 12, 13, 14},
		{21, 22, 23, 24}
	};

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << arr1[r][c] << ", ";
		}
		cout << endl;
	}
	cout << "-----------------" << endl;

	//dynamic - heap memory

	int** arr2 = new int* [rows];

	for (int i = 0; i < rows; ++i)
	{
		arr2[i] = new int[cols];
	}


	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			arr2[r][c] = (10 * r) + c;
		}
	}

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << arr2[r][c] << ", ";
		}
		cout << endl;
	}
	cout << arr2 << endl;
	cout << arr2 + 1 << endl;
	cout << arr2 + 2 << endl;

	cout << "columns address" << endl;
	cout << arr2[0] << endl;
	cout << arr2[0] + 1 << endl;
	cout << arr2[0] + 2 << endl;
	cout << arr2[0] + 3 << endl;

	return 0;
}







