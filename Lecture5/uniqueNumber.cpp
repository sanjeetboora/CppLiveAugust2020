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
	int xorAll = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		xorAll = xorAll ^ x;
	}
	cout << xorAll << endl;

	return 0;
}




