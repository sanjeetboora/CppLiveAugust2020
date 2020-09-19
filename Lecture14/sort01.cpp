#include <bits/stdc++.h>
using namespace std;

void sort01array(int n, int* arr) {

	int left = 0, right = n - 1;

	while (left < right) {

		if (arr[left] == 1) {
			swap(arr[left], arr[right]);
			right--;
		}
		else {
			left++;
		}
	}

}


int main(int argc, char const *argv[])
{
	int n = 10;
	int arr[10] = {1, 0, 1, 1, 0, 0, 1, 1, 0, 1};

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ",";
	} cout << endl;

	sort01array(n, arr);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ",";
	} cout << endl;

	return 0;
}