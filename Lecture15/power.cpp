#include <bits/stdc++.h>
using namespace std;

int power(int a, int b) { //a^b
	//base case
	if (b == 0) {
		return 1;
	}

	int result = a * power(a, b - 1);
	return result;
}

int main(int argc, char const *argv[])
{
	int x = 2;
	int y = 5;

	int xPowery = power(x, y);
	cout << xPowery << endl;


	return 0;
}