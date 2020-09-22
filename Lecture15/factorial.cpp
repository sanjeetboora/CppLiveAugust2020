#include <bits/stdc++.h>
using namespace std;
int factorial(int n);

int main(int argc, char const *argv[]) {

	int x = 2;
	int factX = factorial(x);

	cout << factX << endl;

	return 0;
}

int factorial(int n) {
	//base case
	if (n == 0) {
		return 1;
	}

	return n * factorial(n - 1);
}
