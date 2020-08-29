#include <bits/stdc++.h>
using namespace  std;

//function
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int countSetBits = 0;

	while (n) {
		if (n & 1) {
			countSetBits++;
		}
		n = n >> 1;
	}
	cout << countSetBits << endl;
	return 0;
}




