#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int size) {
	int low = 0, high = size - 1;

	while (low <= high) {
		// int mid = (low + high) / 2;
		int mid = low + (high - low) / 2; //optimized - lower mid
		//int mid = low + (high - low+1) / 2; //optimized - upper mid
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {//left
			high = mid - 1;
		}
		else {//arr[mid] < key - right

			low = mid + 1;
		}
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	int arr[10] = {1, 3, 22, 63, 78, 90, 99, 167, 879};

	// int s = sizeof(arr) / sizeof(arr[0]);
	// cout << s << endl;
	int key = 0;

	int keyIdx = binarySearch(arr, key, 9);

	if (keyIdx != -1) {
		cout << key << " is found at " << keyIdx << endl;
	}
	else {
		cout << key << " is not found" << endl;
	}


	return 0;
}





