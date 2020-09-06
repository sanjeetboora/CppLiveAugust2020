#include <bits/stdc++.h>
using namespace  std;

int main()
{

	int n = 6;
	int arr[10] = { -2, 5, -3, 7, -8, 2};
	int prefixSumArray[10] = {0};

	prefixSumArray[0] = arr[0];

	for (int i = 1; i < n; ++i)
	{
		prefixSumArray[i] = prefixSumArray[i - 1] + arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cout << prefixSumArray[i] << ", ";
	} cout << endl;


	int maxSum = 0;

	for (int startIdx = 0; startIdx < n; ++startIdx) //n
	{
		for (int endIdx = startIdx; endIdx < n; ++endIdx)  //n
		{
			int currSubarraySum = 0;
			if (startIdx == 0) {
				currSubarraySum = prefixSumArray[endIdx];
			}
			else {
				currSubarraySum = prefixSumArray[endIdx] - prefixSumArray[startIdx - 1];
			}


			cout << startIdx << ", " << endIdx << " => " << currSubarraySum << endl;
			maxSum = max(maxSum, currSubarraySum);
		}
	}
	cout << "max subarray sum : " << maxSum << endl;

	return 0;
}




