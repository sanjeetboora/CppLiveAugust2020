#include <bits/stdc++.h>
using namespace std;

int squareRootInteger(int n) {

	int low = 0, high = n, ans = 0;
	while (low <= high) {

		int mid = low + (high - low) / 2;
		if (mid * mid == n) { //perfect square
			return mid;
		}
		else if (mid * mid < n) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n = 8;

	int sqrt = squareRootInteger(n);
	cout << sqrt << endl;

	return 0;
}