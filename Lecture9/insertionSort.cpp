#include <bits/stdc++.h>
using namespace  std;

void printArray(int arr[10], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}


void insertionSort(int arr[10], int n) {

	for (int i = 1; i < n ; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while ( j >= 0 and arr[j] > key ) {

			//right shift
			arr[j + 1] = arr[j];
			j--;

		}

		arr[j + 1] = key;
	}

}


int main()
{

	int n = 5;

	int arr[10] = { 5, 3, 2, 1, 4};

	printArray(arr, n);

	insertionSort(arr, n);

	printArray(arr, n);


	return 0;
}




