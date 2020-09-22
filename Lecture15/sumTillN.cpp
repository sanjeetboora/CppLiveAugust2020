#include <bits/stdc++.h>
using namespace std;

int sumTillN(int n) {
	//base case
	if (n == 0) {
		return 0;
	}

	int result = n + sumTillN(n - 1);
	return result;
}

int main(int argc, char const *argv[])
{
	int n = 10;

	int y = sumTillN(n);
	cout << y << endl;

	return 0;
}