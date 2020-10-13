#include <bits/stdc++.h>
using namespace std;

double squareRoot(int n, int p) {

	int low = 0, high = n;
	double ans = 0;
	while (low <= high) {

		int mid = low + (high - low) / 2;
		int square = mid * mid;

		if (square <= n) {
			ans = mid;
		}
		if (square < n) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}


	double add = 0.1;

	while (p > 0) {
		ans += add;
		while (ans * ans <= n) {
			ans += add;
		}
		ans -= add;
		add = add / 10;
		p--;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int n = 16;
	int p = 4;
	double sqrt = squareRoot(n, p);
	cout << sqrt << endl;

	return 0;
}