#include <bits/stdc++.h>
using namespace  std;

int main()
{

	int n = 4;
	int arr[5] = {1, 2, 3, 4};

	for (int startIdx = 0; startIdx < n; ++startIdx)
	{
		for (int endIdx = startIdx; endIdx < n; ++endIdx)
		{
			for (int temp = startIdx; temp <= endIdx; ++temp)
			{
				cout << arr[temp] << ", ";
			}
			cout << endl;
		}
	}

	return 0;
}




