/* Problem -  */
/* By Sanjeet Boora */

#include<bits/stdc++.h>
using namespace std;

int maxLengthSubarraySumZero(int* arr, int n) {
	int prefixSum = 0;
	int maxLength = 0;
	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];


		if (prefixSum == 0) {
			maxLength = max(maxLength, i + 1);
			//cout << 0 << ", " << i << endl;
		}
		if (mp.count(prefixSum)) {
			//cout << mp[prefixSum]; + 1 << ", " << i << endl;
			int currLength = i - mp[prefixSum];
			maxLength = max(maxLength, currLength);
		}

		else {
			mp[prefixSum] = i;
		}
	}
	return maxLength;
}


int main(int argc, char const *argv[])
{
	//prefix sum array 7 8 9 3 4 9 7 8 9
	int arr[10] = {7, 8, -3, 0, 1, 2, 6};
	cout << maxLengthSubarraySumZero(arr, 6) << endl;
	return 0;
}

