/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

bool isPairSumZero(int* arr, int n) {
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	{
		int toGet = -1 * arr[i];
		if (mp.count(toGet)) {
			cout << arr[i] << ", " << toGet << endl;
			return true;
		}
		else {
			mp[arr[i]] = i;
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int arr[10] = {7, 8, -3, 0, 1, 2, 6};
	cout << isPairSumZero(arr, 7) << endl;
	return 0;
}

