#include <bits/stdc++.h>
using namespace std;

void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int partition(int* arr, int start, int end) {
	int pivot = arr[end];

	int smallerElementIdx = start - 1; //smaller or equal tp pivot elements exists till this index
	int elementIdx = start;
	while (elementIdx < end) {
		if (arr[elementIdx] <= pivot) {
			smallerElementIdx++;
			swap(arr[smallerElementIdx], arr[elementIdx]);
		}
		elementIdx++;
	}
	smallerElementIdx++;
	swap(arr[end], arr[smallerElementIdx]); //placing pivot to it's correct position
	return smallerElementIdx;
}

int quickSort(int* arr, int start, int end, int k) {
	if (start >= end) {
		if (start == k) {
			return arr[start];
		}
		return -1;
	}

	int pivotIdx = partition(arr, start, end);
	if (pivotIdx == k) {
		return arr[k];
	}
	else if (pivotIdx < k) {
		return quickSort(arr, pivotIdx + 1, end, k); //right part
	}
	else {
		return quickSort(arr, start, pivotIdx - 1, k); //left part
	}
}


int main(int argc, char const * argv[])
{
	int arr[10] = {3, 2, 5, 1, 9, 0};
	int n = 6;
	int k = 1;
	cout << quickSort(arr, 0, n - 1, k - 1) << endl;

	return 0;
}