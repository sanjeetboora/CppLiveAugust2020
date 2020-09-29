#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void bubbleSort(int* arr, int n) {
	//base case
	if (n <= 0) {
		return;
	}

	//self work
	for (int j = 0; j < n ; j++)
	{
		if (arr[j] > arr[j + 1]) {
			swap(arr[j], arr[j + 1]);
		}
	}

	//recursive case
	bubbleSort(arr, n - 1);
}


void bubbleSort1(int* arr, int n, int j) {
	//base case - 1
	if (n <= 0) {
		return;
	}

	//base case - 2
	if (j == n) {
		//recursive case 1
		bubbleSort1(arr, n - 1, 0);
		return;
	}

	//self work
	if (arr[j] > arr[j + 1]) {
		swap(arr[j], arr[j + 1]);
	}

	//recursive case 2
	bubbleSort1(arr, n, j + 1);
}



int main(int argc, char const *argv[])
{

	int arr[10] = {5, 4, 3, 2, 1};
	int n = 5;
	printArray(arr, n);
	bubbleSort(arr, n - 1);
	printArray(arr, n);



	return 0;
}