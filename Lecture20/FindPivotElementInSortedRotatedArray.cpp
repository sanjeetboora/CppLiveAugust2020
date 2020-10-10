//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <bits/stdc++.h>
using namespace std;

int pivotIdxRotatedArray(int* arr, int start, int end) {
	if (start >= end) {
		return start;
	}

	int mid = start + (end - start) / 2;
	//if pivot is found

	if (mid > start and arr[mid] < arr[mid - 1]) {
		return mid; //mid is pivot
	}
	else if (end > mid + 1 and arr[mid + 1] < arr[mid]) {
		return mid + 1; //mid+1 is pivot
	}

	//recursive

	if (arr[end] < arr[mid]) { //right part is unsorted
		return pivotIdxRotatedArray(arr, mid + 1, end);
	}
	else {
		return pivotIdxRotatedArray(arr, start, mid - 1);
	}

}


int main(int argc, char const *argv[])
{
	int arr[10] = {1, 2, 3, 5, 6, 7, 8, 9};

	int n = 8;

	int pivotIdx = pivotIdxRotatedArray(arr, 0, n - 1);

	cout << "array has " << pivotIdx << " rotations" << endl;


	return 0;
}

//HW -https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650
//https://www.spoj.com/problems/AGGRCOW/
