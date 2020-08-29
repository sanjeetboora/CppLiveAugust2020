#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x = 1;
	int y = 2;
	int z = x ^ y;
	cout << z << endl;


	int leftShift = y << x; //2<<1 => 2* pow(2,1);
	cout << leftShift << endl;


	int rightShift = z >> x;
	cout << rightShift << endl;

	int negVal = -10;
	int negRightShift = negVal >> x;
	cout << negRightShift << endl;

	int negLeftShift = negVal << x;
	cout << negLeftShift << endl;


	cout << (5 >> 2) << endl;
	cout << 5 * 2 << endl;

	// Address
	cout << &x << endl;
	cout << (z & y) << endl;
	cout << (long long int)&x << endl;


	if (x > 2) {
		cout << "x > 2" << endl;
	}
	else {
		cout << "x <= 2" << endl;
	}

	(x > 2) ? cout << "x > 2" << endl : cout << "x <= 2" << endl;

	int x2 = (x > 2) ? 5 : 10;
	cout << x2 << endl;


	x2 = x2 + 9;
	x2 += 9;

	x2 = x2 >> 2;
	x2 >>= 2;

	return 0;
}




