#include <bits/stdc++.h>
using namespace std;

bool isSortedArray(int* arr, int n) {
	if (n == 0 or n == 1) {
		return true;
	}

	if (arr[0] <= arr[1] and isSortedArray(arr + 1, n - 1)) {
		return true;
	}

	return false;

}

int main(int argc, char const *argv[])
{
	int n = 5;

	int arr[10] = {1 , 2, 4, 0, 6};


	if (isSortedArray(arr, n)) {
		cout << "Sorted" << endl;
	}
	else {
		cout << " Unsorted" << endl;
	}

	return 0;
}