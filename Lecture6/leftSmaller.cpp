#include <iostream>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//5, 6, 3, 1, 0, 2, -2

	int arr[100] = {5, 6, 3, 1, 0, 2, -2};

	for (int currIdx = 0; currIdx < 7; ++currIdx)
	{
		int maximum = arr[currIdx];
		for (int i = currIdx; i < 7; ++i)
		{
			maximum = max(maximum, arr[i]);
		}
		if (maximum == arr[currIdx]) {
			cout << arr[currIdx] << endl;
		}
	}
	cout << "--------" << endl;
	//better version
	int rightMax = INT_MIN;

	for (int currIdx = 6; currIdx >= 0; currIdx--)
	{
		if (arr[currIdx] > rightMax) {
			cout << arr[currIdx] << endl;
			rightMax = arr[currIdx];
		}
	}







	return 0;
}