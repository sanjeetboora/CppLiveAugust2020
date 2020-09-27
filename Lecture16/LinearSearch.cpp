#include <bits/stdc++.h>
using namespace std;

int linearSearch1(int* arr, int sizeOfArray, int key) {

	if (sizeOfArray == 0) {
		return -1;
	}

	int ele = arr[sizeOfArray - 1];
	if (ele == key) {
		return sizeOfArray - 1;
	}
	else {
		return linearSearch1(arr, sizeOfArray - 1, key);
	}
}



bool linearSearch(int* arr, int n, int key) {

	if (n == 0) {
		return false;
	}

	int ele = arr[0];
	if (ele == key) {
		return true;
	}
	else {
		return linearSearch(arr + 1, n - 1, key);
	}
}

int main(int argc, char const *argv[])
{
	int n = 5;

	int arr[10] = {1 , 2, 4, 0, 6};

	int key = 0;

	if (linearSearch(arr, n, key)) {
		cout << key << " found" << endl;
	}
	else {
		cout << key << " not found" << endl;
	}

	if (linearSearch1(arr, n, key) == -1) {
		cout << key << " not found" << endl;
	}
	else {
		cout << key << " found at " << linearSearch1(arr, n, key) << endl;
	}

	return 0;
}