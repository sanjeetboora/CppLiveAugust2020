#include <bits/stdc++.h>
using namespace std;
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
	}
}

void merge(int*arr, int start, int mid, int end) {
	//two sorted parts of array
	//array first part => start to mid
	//array second part => mid+1 to end
	int a = start, b = mid + 1, c = 0;
	int temp[end - start + 1];
	while (a <= mid and b <= end) {
		if (arr[a] <= arr[b]) {
			temp[c] = arr[a];
			a++;
			c++;
		}
		else {
			temp[c] = arr[b];
			b++;
			c++;
		}
	}

	//copy remaining elements of left part
	while (a <= mid) {
		temp[c] = arr[a];
		a++;
		c++;
	}
	//copy remaining elements of right part
	while (b <= end) {
		temp[c] = arr[b];
		b++;
		c++;
	}

	int i = 0;
	while (start <= end) {
		arr[start] = temp[i];
		start++;
		i++;
	}
}


void mergeSort(int*arr, int start, int end) {
	if (start == end) {
		return;
	}

	int mid = start + (end - start) / 2;
	//left part
	mergeSort(arr, start, mid);
	//right part
	mergeSort(arr, mid + 1, end);

	//merge both left and right part
	merge(arr, start, mid, end);

}



int main(int argc, char const *argv[])
{
	int n = 10000;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = n - i;
	}

	clock_t startTime = clock();
	bubbleSort(n, arr);
	clock_t endTime = clock();
	cout << endTime - startTime << endl;

	for (int i = 0; i < n; ++i)
	{
		arr[i] = n - i;
	}
	startTime = clock();
	mergeSort(arr, 0, n - 1);
	endTime = clock();
	cout << endTime - startTime << endl;

	return 0;
}



