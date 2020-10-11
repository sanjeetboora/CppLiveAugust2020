//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int* arr, int key, int n) {
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		//if key found at mid
		if (arr[mid] == key) {
			return mid;
		}

		//if left part is sorted
		if (arr[low] <= arr[mid]) {
			if (arr[low] <= key and arr[mid] > key) {//if key is lying in range of left half
				high = mid - 1;	//shift to left half
			}
			else {
				low = mid + 1;//shift to right half
			}

		}
		else {//else right part is sorted
			if (arr[mid] < key and arr[high] >= key) { //if key is lying in range of right half
				low = mid + 1; //shift to right half
			}
			else {
				high = mid - 1;//shift to left half
			}

		}
	}
	return -1;

}


int main(int argc, char const *argv[])
{
	int arr[10] = {7, 8, 9, 1, 2, 3, 4, 5, 6,};

	int n = 9;
	int key = 0;
	int KeyIdx = searchInRotatedArray(arr, key, n);
	if (KeyIdx != -1) {
		cout << key << " found at " << KeyIdx << endl;
	}
	else {
		cout << key << " not found" << endl;
	}

	return 0;
}
