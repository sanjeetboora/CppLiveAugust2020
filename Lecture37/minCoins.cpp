/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int minCoinRec(int money, int* coins, int n) {
	if (money == 0) {
		return 0;
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (money - coins[i] >= 0) {
			int count = 1 + minCoinRec(money - coins[i], coins, n);
			ans = min(ans, count);
		}
	}
	return ans;
}
int minCoinTopDown(int money, int* coins, int n, int* dp) {
	if (money == 0) {
		return 0;
	}

	if (dp[money] != 0) {
		return dp[money];
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (money - coins[i] >= 0) {
			int count = 1 + minCoinTopDown(money - coins[i], coins, n, dp);
			ans = min(ans, count);
		}
	}
	dp[money] = ans;
	return ans;
}

int minCoinBottomUp(int money, int* coins, int n) {
	int dp[1000] = {0};

	for (int i = 1; i <= money; ++i)
	{
		dp[i] = INT_MAX;
		for (int c = 0; c < n ; ++c)
		{
			if (i - coins[c] >= 0) {
				int requiredCoins = 1 + dp[i - coins[c]];
				dp[i] = min(dp[i], requiredCoins);
			}
		}
	}

	for (int i = 0; i <= money; ++i)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;
	return dp[money];
}


int main(int argc, char const *argv[])
{
	int coins[10] = {10, 6, 1};
	int n = 3;
	int money{19};
	cout << minCoinRec(money, coins, n) << endl;
	int arr[100] = {0};
	cout << minCoinTopDown(money, coins, n, arr) << endl;
	for (int i = 0; i <= money; ++i)
	{
		cout << arr[i] << ", ";
	} cout << endl;
	cout << minCoinBottomUp(money, coins, n) << endl;
	return 0;
}

//H.W. - rod cutting problem

