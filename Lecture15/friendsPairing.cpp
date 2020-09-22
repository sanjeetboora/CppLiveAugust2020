#include <bits/stdc++.h>
using namespace std;

int ways(int n) {
	//base case
	if (n <= 2) {
		return n;
	}

	//single + double (n-1 * ways(n-2))
	int result = ways(n - 1) + (n - 1) * ways(n - 2);
	return result;
}

int main(int argc, char const *argv[])
{
	int n = 3;

	int y = ways(n);
	cout << y << endl;

	return 0;
}