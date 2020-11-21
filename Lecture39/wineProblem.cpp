/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;


int wineProblemRec(int* prices, int start, int end, int year) {
	if (start > end) {
		return 0;
	}

	int startInclude = (prices[start] * year) + wineProblemRec(prices, start + 1, end, year + 1);
	int endInclude = (prices[end] * year) + wineProblemRec(prices, start, end - 1, year + 1);

	int profit = max(startInclude, endInclude);
	return profit;
}


int wineProblemTopDown(int* prices, int start, int end, int year, int dp[100][100]) {
	if (start > end) {
		return 0;
	}
	if (dp[start][end] != 0) {
		return dp[start][end];
	}

	int startInclude = (prices[start] * year) + wineProblemRec(prices, start + 1, end, year + 1);
	int endInclude = (prices[end] * year) + wineProblemRec(prices, start, end - 1, year + 1);

	int profit = max(startInclude, endInclude);
	dp[start][end] = profit;
	return profit;
}


int wineProblemBottomUp(int* prices, int n) {
	int years = n;
	int dp[n][n];
	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = years * prices[i];
	}
	years--;

	for (int window = 2; window <= n; window++)
	{
		int start = 0, end = n - window;
		while (start <= end) {
			int currWindowStart = start;
			int currWindowEnd = start + window - 1;

			int sellStart = (prices[currWindowStart] * years) + dp[currWindowStart + 1][currWindowEnd];
			int sellEnd = (prices[currWindowEnd] * years) + dp[currWindowStart][currWindowEnd - 1];
			dp[currWindowStart][currWindowEnd] = max(sellStart, sellEnd);
			start++;
		}
		years--;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << dp[i][j] << ", ";
		} cout << endl;
	}
	return dp[0][n - 1];

}




int main(int argc, char const *argv[])
{	int arr[10] = {2, 3, 5, 1 , 4};
	int n = 5;
	cout << wineProblemRec(arr, 0, n - 1, 1) << endl;
	int dp[100][100] = {0};
	cout << wineProblemTopDown(arr, 0, n - 1, 1, dp) << endl;
	cout << wineProblemBottomUp(arr, n) << endl;
	return 0;

}

