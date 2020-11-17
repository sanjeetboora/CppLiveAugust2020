#include <bits/stdc++.h>
using namespace std;

int countBoardPath(int start, int end, int dice) {
	if (start == end) { //valid path
		return 1;
	}

	if (start > end) { //invalid path
		return 0;
	}

	int pathCount  =  0;

	for (int d = 1; d <= dice ; d++)
	{
		pathCount += countBoardPath(start + d, end, dice);
	}
	return pathCount;
}

int countBoardPathTopDownDP(int start, int end, int dice, int* dp) {
	if (start == end) { //valid path
		dp[start] = 1;
		return 1;
	}

	if (start > end) { //invalid path
		return 0;
	}

	if (dp[start] != 0) {
		return dp[start];
	}

	int pathCount  =  0;

	for (int d = 1; d <= dice ; d++)
	{
		pathCount += countBoardPathTopDownDP(start + d, end, dice, dp);
	}
	dp[start]  = pathCount;

	return pathCount;
}


int countBoardPathBottomUpDP(int start, int end, int dice) {
	int dp[100] = {0};
	dp[start] = 1; //base case

	for (int i = start + 1; i <= end; ++i)
	{
		for (int d = 1; d <= dice; ++d)
		{
			if (i - d >= start) {
				dp[i] += dp[i - d];
			}
		}
	}
	for (int i = start; i <= end; ++i)
	{
		cout << dp[i] << ", ";
	} cout << endl;

	return dp[end];
}

int countBoardPathBottomUpDPOptimization(int start, int end, int dice) {
	int dp[100] = {0};
	dp[start] = 1; //base case
	dp[start + 1] = 1;


	for (int i = start + 2; i <= end; ++i)
	{
		if (i - dice - 1 >= start) {
			dp[i] = 2 * dp[i - 1] - dp[i - dice - 1];
		}
		else {
			dp[i] = 2 * dp[i - 1];
		}

	}
	for (int i = start; i <= end; ++i)
	{
		cout << dp[i] << ", ";
	} cout << endl;

	return dp[end];
}


int main(int argc, char const *argv[])
{
	int N = 9;

	int dice = 6;


	int noOfWays = countBoardPath(0, N, dice);
	cout << noOfWays << endl;
	int arr[10] = {0};
	cout << countBoardPathTopDownDP(0, N, dice, arr) << endl;
	for (int i = 0; i <= N; ++i)
	{
		cout << arr[i] << ", ";
	} cout << endl;
	cout << countBoardPathBottomUpDP(0, N, dice) << endl;
	cout << countBoardPathBottomUpDPOptimization(0, N, dice) << endl;

	return 0;
}


// H.W. print count board path