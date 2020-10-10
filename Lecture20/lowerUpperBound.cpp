//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
using namespace std;

int lowerBound(int arr[], int key, int size) {
	int low = 0, high = size - 1;
	int lower = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2; //optimized - lower mid
		if (arr[mid] == key) {
			lower = mid;
			high = mid - 1;
		}
		else if (arr[mid] > key) {//left
			high = mid - 1;
		}
		else {//arr[mid] < key - right

			low = mid + 1;
		}
	}
	return lower;
}

int upperBound(int arr[], int key, int size) {
	int low = 0, high = size - 1;
	int upper = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2; //optimized - lower mid
		if (arr[mid] == key) {
			upper = mid;
			low = mid + 1;
		}
		else if (arr[mid] > key) {//left
			high = mid - 1;
		}
		else {//arr[mid] < key - right

			low = mid + 1;
		}
	}
	return upper;
}


int main(int argc, char const *argv[])
{
	int arr[10] = {1, 3, 3, 3, 78, 90, 99, 167, 879};

	// int s = sizeof(arr) / sizeof(arr[0]);
	// cout << s << endl;
	int key = 100;

	int keyIdx = lowerBound(arr, key, 9);
	int keyIdx1 = upperBound(arr, key, 9);

	if (keyIdx != -1) {
		cout << key << " is found at " << keyIdx << endl;
	}
	else {
		cout << key << " is not found" << endl;
	}

	if (keyIdx1 != -1) {
		cout << key << " is found at " << keyIdx1 << endl;
	}
	else {
		cout << key << " is not found" << endl;
	}


	return 0;
}





