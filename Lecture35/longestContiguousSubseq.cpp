/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int longestContiguousSubsequence(int* arr, int n) {
	unordered_map<int, int>mp;
	for (int i = 0; i < n; ++i)
	{
		mp[arr[i]] = i;
	}
	int maxLength = 0;

	for (int i = 0; i < n; ++i)
	{
		int leftEle = arr[i] - 1;
		if (mp.count(leftEle)) {
			continue;
		}
		else {
			int currLength = 0;
			int x = arr[i];
			while (mp.count(x)) {
				currLength++;
				x++;
			}
			maxLength = max(maxLength, currLength);
		}
	}
	return maxLength;

}

int main(int argc, char const *argv[])
{
	int arr[10] = {3, 9, 8, 6, 1, 6, 5, 3, 2};
	int n = 9;

	cout << longestContiguousSubsequence(arr, n) << endl;
	return 0;
}

