#include <bits/stdc++.h>
using namespace std;

void dec(int n) {
	//base case
	if (n == 0) {
		return;
	}
	cout << n << endl;
	dec(n - 1);
}

void inc(int n) {
	//base case
	if (n == 0) {
		return;
	}
	inc(n - 1);
	cout << n << endl;
}

void decInc(int n) {
	if (n == 0) {
		return;
	}

	cout << n << endl;
	decInc(n - 1);
	cout << n << endl;
}

int main(int argc, char const *argv[]) {

	int x = 5;
	dec(x);
	cout << "------" << endl;
	inc(x);
	cout << "------" << endl;
	decInc(x);

	return 0;
}

