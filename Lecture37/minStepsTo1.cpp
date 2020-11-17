/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int minStepsToOneRecursive(int n) {
	//base case
	if (n == 1) {
		return 0;
	}

	int divBy3 = INT_MAX, divBy2 = INT_MAX, sub1 = INT_MAX;
	if (n % 3 == 0) divBy3 = minStepsToOneRecursive(n / 3);
	if (n % 2 == 0) divBy2 = minStepsToOneRecursive(n / 2);
	sub1 = minStepsToOneRecursive(n - 1);

	int minStepsForN = 1 + min(divBy3, min(divBy2, sub1));
	return minStepsForN;

}

int minStepsToOneTopDownDP(int n, int* dp) {
	//base case
	if (n == 1) {
		return 0;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	int divBy3 = INT_MAX, divBy2 = INT_MAX, sub1 = INT_MAX;
	if (n % 3 == 0) divBy3 = minStepsToOneTopDownDP(n / 3, dp);
	if (n % 2 == 0) divBy2 = minStepsToOneTopDownDP(n / 2, dp);
	sub1 = minStepsToOneTopDownDP(n - 1, dp);

	int minStepsForN = 1 + min(divBy3, min(divBy2, sub1));
	dp[n] = minStepsForN;
	return dp[n];
}

int minStepsToOneBottomUp(int n) {
	int dp[100] = {0};
	dp[1] = 0; dp[2] = 1; dp[3] = 1;

	for (int i = 4; i <= n; ++i)
	{
		int divBy3 = INT_MAX, divBy2 = INT_MAX, sub1 = INT_MAX;
		if (i % 3 == 0) divBy3 = dp[i / 3];
		if (i % 2 == 0) divBy2 = dp[i / 2];
		sub1 = dp[i - 1];

		dp[i] = 1 + min(divBy3, min(divBy2, sub1));
	}
	return dp[n];
}



int main(int argc, char const *argv[])
{
	int n = 10;
	cout << minStepsToOneRecursive(n) << endl;
	int arr[11] = {0};
	cout << minStepsToOneTopDownDP(n, arr) << endl;
	cout << minStepsToOneBottomUp(n) << endl;
	return 0;
}

