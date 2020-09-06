#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[10] = {1, 2, 3, 4, 5, 6};
	int k = 3;
	int n = 6;
	//1st Approach //n*k

	// for (int i = 1; i <= k; ++i)
	// {
	// 	int temp = arr[n - 1];
	// 	for (int i = 0; i < n; ++i)
	// 	{
	// 		int currElement = arr[i];
	// 		arr[i] = temp;
	// 		temp = currElement;
	// 	}
	// }
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << arr[i] << ", ";
	// }


	//2nd Approach //n+k


	int temp[10] = {0}; //k size

	//shift to temp array
	for (int i = 0; i < k; ++i)
	{
		temp[i] = arr[n - k + i];
	}

	//right shift by k
	for (int i = n - 1 - k; i >= 0; i--)
	{
		arr[i + k] = arr[i];
	}

	//temp array to actual array
	for (int i = 0; i < k; ++i)
	{
		arr[i] = temp[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}


	return 0;
}




