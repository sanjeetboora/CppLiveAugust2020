#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x = 2;
	int y = 3;
	int z = 2 & 3;
	cout << z << endl;
	int x2 = 1;
	int z2 = x2 & y;
	cout << z2 << endl;

	int z3 = x2 | y;
	cout << z3 << endl;

	int z4 = ~x2;
	cout << z4 << endl;

	return 0;
}