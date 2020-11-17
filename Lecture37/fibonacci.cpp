/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int fibRec(int n) {
	//base case
	if (n == 0 or n == 1) {
		return n;
	}

	int nthFibonacci = fibRec(n - 1) + fibRec(n - 2);
	return nthFibonacci;
}

int fibTopDownDP(int n, int* dp) {
	//base case
	if (n == 0 or n == 1) {
		dp[n] = n;
		return n;
	}

	if (dp[n] != 0) { //fibonacci(n) is already calculated
		return dp[n];
	}

	int nthFibonacci = fibTopDownDP(n - 1, dp) + fibTopDownDP(n - 2, dp);
	dp[n] = nthFibonacci;

	return nthFibonacci;
}

int fibBottomUp(int n) {
	int dp[10];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}


int main(int argc, char const *argv[])
{
	int n = 5;

	cout << fibRec(n) << endl;
	int arr[10] = {0};
	cout << fibTopDownDP(n, arr) << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << arr[i] << ", ";
	} cout << endl;
	cout << fibBottomUp(n) << endl;
	return 0;
}

