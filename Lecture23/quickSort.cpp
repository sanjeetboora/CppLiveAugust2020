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

void quickSort(int* arr, int start, int end) {
	if (start >= end) {
		return;
	}

	int pivotIdx = partition(arr, start, end);
	quickSort(arr, start, pivotIdx - 1); //left part
	quickSort(arr, pivotIdx + 1, end); //right part

}


int main(int argc, char const * argv[])
{
	int arr[10] = {3, 2, 5, 1, 9, 0};
	int n = 6;

	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	printArray(arr, n);

	return 0;
}