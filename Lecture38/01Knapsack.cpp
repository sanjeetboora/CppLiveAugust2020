/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;


int knapsack01Rec(int* weight, int* price, int totalWeight, int n) {
	if (n == 0) {
		return 0;
	}

	int inc = 0, exc = 0;

	int currItemWeight = weight[n - 1];
	int currItemPrice = price[n - 1];

	//to include
	if ((totalWeight - currItemWeight) >= 0) {
		inc = currItemPrice + knapsack01Rec(weight, price, totalWeight - currItemWeight, n - 1);
	}
	exc = knapsack01Rec(weight, price, totalWeight, n - 1);

	return max(inc, exc);
}

int dp[100][100];
int knapsack01TopDown(int* weight, int* price, int totalWeight, int n) {
	if (n == 0) {
		return 0;
	}

	if (dp[n][totalWeight] != -1) {
		return dp[n][totalWeight];
	}

	int inc = 0, exc = 0;

	int currItemWeight = weight[n - 1];
	int currItemPrice = price[n - 1];

	//to include
	if ((totalWeight - currItemWeight) >= 0) {
		inc = currItemPrice + knapsack01TopDown(weight, price, totalWeight - currItemWeight, n - 1);
	}
	exc = knapsack01TopDown(weight, price, totalWeight, n - 1);

	dp[n][totalWeight] = max(inc, exc);
	return dp[n][totalWeight];
}


int knapsack01BottomUp(int* weight, int* price, int totalWeight, int n) {
	int dp[100][100] = {0};

	if (n == 0) {
		return 0;
	}

	for (int item = 1; item <= n; item++)
	{
		for (int w = 1; w <= totalWeight; w++)
		{
			int inc = 0, exc = 0;
			int currItemWeight = weight[item - 1];
			int currItemPrice = price[item - 1];
			//to include
			if (w - currItemWeight >= 0) {
				inc = currItemPrice + dp[item - 1][w - currItemWeight];
			}
			exc = dp[item - 1][w];

			dp[item][w] = max(inc, exc);
		}
	}

	for (int item = 0; item <= n; item++)
	{
		for (int w = 0; w <= totalWeight; w++)
		{
			cout << dp[item][w] << ", ";
		}
		cout << endl;
	}
	return dp[n][totalWeight];
}



int main(int argc, char const *argv[])
{
	int weight[10] = {1, 2 , 3, 4};
	int price[10] = {6, 10, 12 , 13};
	int n = 4;
	int totalWeight = 5;
	cout << knapsack01Rec(weight, price, totalWeight, n) << endl;

	//initialize dp matrix with -1;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= totalWeight; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << knapsack01TopDown(weight, price, totalWeight, n) << endl;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= totalWeight; j++)
		{
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}
	cout << "--bottom up ----" << endl;
	cout << knapsack01BottomUp(weight, price, totalWeight, n) << endl;
	return 0;

}

