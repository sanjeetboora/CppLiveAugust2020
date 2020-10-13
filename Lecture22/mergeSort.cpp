#include <bits/stdc++.h>
using namespace std;

void merge(int*arr, int start, int mid, int end) {
	//two sorted parts of array
	//array first part => start to mid
	//array second part => mid+1 to end
	int a = start, b = mid + 1, c = 0;
	int temp[100] = {0};
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
	int arr[10] = {1, 3, 2, 0, 13, 15, -1};

	for (int i = 0; i < 7; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	mergeSort(arr, 0, 6);

	for (int i = 0; i < 7; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;


	return 0;
}





