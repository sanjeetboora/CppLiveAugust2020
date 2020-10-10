#include <bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int key, int start, int end) {
	//base case
	if (start > end) {
		return -1; //not found
	}

	//self work
	int mid = start + (end - start) / 2;
	if (arr[mid] == key) {
		return mid;
	}

	//recursive
	else if (arr[mid] < key) { //right half
		return binarySearch(arr, key, mid + 1, end);
	}
	else { //arr[mid] > key - left half
		return binarySearch(arr, key, start, mid - 1);
	}

}


int main(int argc, char const *argv[])
{
	int arr[10] = {1, 3, 22, 63, 78, 90, 99, 167, 879};

	// int s = sizeof(arr) / sizeof(arr[0]);
	// cout << s << endl;
	int key = 90;

	int keyIdx = binarySearch(arr, key, 0, 8);

	if (keyIdx != -1) {
		cout << key << " is found at " << keyIdx << endl;
	}
	else {
		cout << key << " is not found" << endl;
	}


	return 0;
}





