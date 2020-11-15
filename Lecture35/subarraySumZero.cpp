/* Problem -  */
/* By Sanjeet Boora */

#include<bits/stdc++.h>
using namespace std;

bool isSubarraySumZero(int* arr, int n) {
	int prefixSum = 0;
	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];

		if (prefixSum == 0 or mp.count(prefixSum)) {
			if (prefixSum == 0) {
				cout << 0 << ", " << i << endl;
			}
			else {
				cout << mp[prefixSum] + 1 << ", " << i << endl;
			}
			return true;
		}
		else {
			mp[prefixSum] = i;
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int arr[10] = {7, 8, -3, 0, 1, 2, 6};
	cout << isSubarraySumZero(arr, 6) << endl;
	return 0;
}

