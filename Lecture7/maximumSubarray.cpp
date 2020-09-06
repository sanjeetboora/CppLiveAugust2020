#include <bits/stdc++.h>
using namespace  std;

int main()
{

	int n = 6;
	int arr[10] = { -2, 5, -3, 7, -8, 2};

	int maxSum = 0;

	for (int startIdx = 0; startIdx < n; ++startIdx) //n
	{
		for (int endIdx = startIdx; endIdx < n; ++endIdx)  //n
		{
			int currSubarraySum = 0;
			for (int temp = startIdx; temp <= endIdx; ++temp)  //n
			{
				currSubarraySum += arr[temp];
				cout << arr[temp] << ", ";
			}

			cout << currSubarraySum << endl;
			maxSum = max(maxSum, currSubarraySum);
		}
	}
	cout << "max subarray sum : " << maxSum << endl;

	return 0;
}




