#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	//base case
	if (n <= 1) {
		return n;
	}

	int fibN = fib(n - 1) + fib(n - 2);
	return fibN;
}

int main(int argc, char const *argv[])
{
	int n = 5;

	int y = fib(n);
	cout << y << endl;

	return 0;
}