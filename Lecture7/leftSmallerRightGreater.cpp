#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[100] = {5, 6, 3, 1, 0, 2, -2};
	int n = 7;

	// rightMax array
	int rightMax[100] = {0};

	rightMax[n - 1] = INT_MIN;

	for (int i = n - 2; i >= 0; i--) {
		rightMax[i] = max(arr[i + 1], rightMax[i + 1]);
	}

	// // leftMin array
	// int leftMin[100] = {0};

	// leftMin[0] = INT_MAX;

	// for (int i = 1; i < n; ++i)
	// {
	// 	leftMin[i] = min(leftMin[i - 1], arr[i - 1]);
	// }

	// //print leftMin array
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << leftMin[i] << ", ";
	// }
	// cout << endl;

	// //print array
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << arr[i] << ", ";
	// }
	// cout << endl;

	// //print rightMax array
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << rightMax[i] << ", ";
	// }
	// cout << endl;

	//print solution
	// for (int i = 0; i < n; ++i)
	// {
	// 	if (arr[i] > rightMax[i] and arr[i] < leftMin[i]) {
	// 		cout << arr[i] << ", ";
	// 	}
	// }
	// cout << endl;




	//optimization

	int leftMin = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (leftMin > arr[i] and arr[i] > rightMax[i]) {
			cout << arr[i] << ", ";
		}
		leftMin = min(leftMin, arr[i]);
	}





	return 0;
}




