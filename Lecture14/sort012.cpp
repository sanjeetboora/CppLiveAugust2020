//dnf algo
#include <bits/stdc++.h>
using namespace std;

void dnf(int n, int* arr) {

	int st = 0, mid = 0, end = n - 1;

	while (mid <= end) {

		if (arr[mid] == 0) {
			swap(arr[st], arr[mid]);
			st++;
			mid++;
		}

		else if (arr[mid] == 2) {
			swap(arr[mid], arr[end]);
			end--;
		}

		else {
			mid++;
		}

	}

}


int main(int argc, char const *argv[])
{
	int n = 10;
	int arr[10] = {1, 2, 0, 1, 0, 2, 1, 1, 2, 1};

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ",";
	} cout << endl;

	dnf(n, arr);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ",";
	} cout << endl;

	return 0;
}