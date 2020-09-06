#include <bits/stdc++.h>
using namespace  std;

void printArray(int arr[10], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}


void selectionSort(int n, int arr[10]) {

	for (int minIdx = 0; minIdx <= n - 2; minIdx++)
	{
		int minElementIndex = minIdx;
		for (int j = minIdx + 1; j <= n - 1; j++) {

			if (arr[j] < arr[minElementIndex]) {
				minElementIndex = j;
			}
		}
		//swap(arr[minIdx], arr[minElementIndex]);

		int temp = arr[minIdx];
		arr[minIdx] = arr[minElementIndex];
		arr[minElementIndex] = temp;
	}
}


int main()
{

	int n = 5;
	int arr[10] = { 5, 3, 2, 1, 4};
	printArray(arr, n);
	selectionSort(n, arr);
	printArray(arr, n);


	return 0;
}




