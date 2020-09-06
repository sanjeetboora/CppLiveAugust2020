#include <bits/stdc++.h>
using namespace  std;

void printArray(int arr[10], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void bubbleSort(int n, int arr[10]) {

	for (int i = 0; i < n - 1 ; ++i) //how many elements to set at right position
	{
		bool isSorted = true;
		for (int j = 0; j < n - 1 - i ; j++)
		{
			if (arr[j] > arr[j + 1]  ) {
				swap(arr[j + 1], arr[j]);
				isSorted = false;
			}
		}
		if (isSorted) {
			break;
		}
		printArray(arr, n);
	}
}



int main()
{
	int n = 5;
	// int arr[10] = { 5, 3, 2, 1, 4};
	int arr[10] = { 1, 2, 5, 4, 3};
	printArray(arr, n);
	bubbleSort(n, arr);
	printArray(arr, n);




	return 0;
}




