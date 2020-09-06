#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{

	int n = 6;
	int arr[10] = { -2, 5, -3, 7, -8, 2};
	// int arr[10] = { -2, -5, -3, -7, -8, -2};

	int maxSum = INT_MIN;
	int currSum = 0;

	//actual Kadane's Algorithm
	// for (int i = 0; i < n; ++i)
	// {
	// 	currSum += arr[i];

	// 	if (currSum < 0) {
	// 		currSum = 0;
	// 	}

	// 	maxSum = max(maxSum, currSum);

	// }


	//modified Kadane's Algorithm for all -ve cases
	// int maxNumber = arr[0];
	// for (int i = 0; i < n; ++i)
	// {
	// 	maxNumber = max(maxNumber, arr[i]);
	// 	currSum += arr[i];

	// 	if (currSum < 0) {
	// 		currSum = 0;
	// 	}

	// 	maxSum = max(maxSum, currSum);

	// }


	//2nd way to handle all -ve

	for (int i = 0; i < n; ++i)
	{

		currSum += arr[i];
		maxSum = max(maxSum, currSum);

		if (currSum < 0) {
			currSum = 0;
		}
	}

	// if (maxNumber < 0) {
	// 	cout << "max subarray sum  => " << maxNumber << endl;
	// }
	// else {
	// 	cout << "max subarray sum  => " << maxSum << endl;
	// }

	cout << maxSum << endl;

	return 0;
}






