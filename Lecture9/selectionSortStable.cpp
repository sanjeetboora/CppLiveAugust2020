#include <bits/stdc++.h>
using namespace  std;

void printArray(int arr[10], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}


void selectionSortStable(int n, int arr[10]) {

	for (int minIdx = 0; minIdx <= n - 2; minIdx++)
	{
		int minElementIndex = minIdx;
		for (int j = minIdx + 1; j <= n - 1; j++) {

			if (arr[j] < arr[minElementIndex]) {
				minElementIndex = j;
			}
		}

		int minElement = arr[minElementIndex];
		//rightShift Elements
		for (int i = minElementIndex - 1; i >= minIdx; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[minIdx] = minElement;
	}
}


int main()
{

	int n = 5;
	int arr[10] = { 5, 3, 2, 1, 4};
	printArray(arr, n);
	selectionSortStable(n, arr);
	printArray(arr, n);


	return 0;
}




