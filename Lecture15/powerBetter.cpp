#include <bits/stdc++.h>
using namespace std;

int power(int a, int b) { //a^b
	//base case
	if (b == 0) {
		return 1;
	}

	int subResult = power(a, b / 2);
	int result = subResult * subResult;

	if (b & 1) {		//b is odd
		result = result * a;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int x = 2;
	int y = 4;

	int xPowery = power(x, y);
	cout << xPowery << endl;


	return 0;
}