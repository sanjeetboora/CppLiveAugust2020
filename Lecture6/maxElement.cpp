#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//print maximum element of the array
	int n, key;
	cin >> n >> key;

	int arr[100] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//maximum Element;

	//int maximum = INT_MIN;
	int maximum = arr[0];

	// for (int i = 1; i < n; i++)
	// {
	// 	if (arr[i] > maximum) {
	// 		maximum = arr[i];
	// 	}
	// }

	for (int i = 1; i < n; i++)
	{
		maximum = max(maximum, arr[i]);
	}

	cout << maximum << endl;

	return 0;
}



//H.W. to find minimum element in given array
