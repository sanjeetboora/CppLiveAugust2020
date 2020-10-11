//find unique element in a given sorted array
#include <bits/stdc++.h>
using namespace std;
int uniqueElement(int*arr, int n) {

	if (!(n & 1)) { //no. of elements are even;
		return -1;
	}

	int start = 0, end = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		//unique element found
		if (mid == 0 and arr[mid + 1] != arr[mid]) {
			return mid;
		}
		else if (mid == n - 1 and arr[mid - 1] != arr[mid]) {
			return mid;
		}
		else if (arr[mid - 1] != arr[mid] and arr[mid + 1] != arr[mid]) {
			return mid;
		}
		//when mid is even
		if (!(mid & 1)) {
			if (arr[mid] == arr[mid + 1]) {
				start = mid + 1; //search shift to right;
			}
			else {
				end = mid - 1;//search shift to left;
			}
		}
		else {//when mid is odd
			if (arr[mid] == arr[mid - 1]) {
				start = mid + 1; //search shift to right;
			}
			else {
				end = mid - 1;//search shift to left;
			}
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int arr[10] = {0, 1, 1, 2, 2, 3, 3, 5, 5};
	int n = 9;

	int uniqueIdx = uniqueElement(arr, n);
	if (uniqueIdx != -1) {
		cout << arr[uniqueIdx] << endl;
	}
	else {
		cout << "unique element not found" << endl;
	}

	return 0;
}