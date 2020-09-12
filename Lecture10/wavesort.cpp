#include <bits/stdc++.h>
using namespace  std;

void printArray(int arr[10], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}


void waveSort(int arr[10], int n) {

	for (int i = 0; i < n; i += 2)
	{
		//if current is smaller than left
		if (i != 0 and arr[i] < arr[i - 1]) {
			swap(arr[i], arr[i - 1]);
		}
		//if current is smaller than right
		if (i != n - 1 and arr[i] < arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}
	}
}


int main()
{
	int n = 9;

	int arr[10] = { 0, 2, 7, 9, 6, 4, 3, 1, 5};
	printArray(arr, n);
	waveSort(arr , n);
	printArray(arr, n);


	return 0;
}




