/* Problem - Longest common subsequence */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;


int lcsRec(string str1, string str2) {
	if (str1.length() == 0 or str2.length() == 0) {
		return 0;
	}

	if (str1[0] == str2[0]) {
		return 1 + lcsRec(str1.substr(1), str2.substr(1));
	}
	else {
		return max( lcsRec(str1.substr(1), str2), lcsRec(str1, str2.substr(1)));
	}
}

int dp[100][100];

int lcsTopDown(string str1, string str2, int i, int j) {
	if (i == str1.length() or j == str2.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int ans = 0;
	if (str1[i] == str2[j]) {
		ans = 1 + lcsTopDown(str1, str2, i + 1, j + 1);
	}
	else {
		ans = max( lcsTopDown(str1, str2, i, j + 1), lcsTopDown(str1, str2, i + 1, j));
	}

	dp[i][j] = ans;
	return ans;
}


int lcsBottomUp(string str1, string str2) {
	int dp[100][100] = {0};

	for (int i = 1; i <= str1.length(); ++i)
	{
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	for (int i = 0; i <= str1.length(); ++i)
	{
		for (int j = 0; j <= str2.length(); j++)
		{
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}

	return dp[str1.length()][str2.length()];
}


int main(int argc, char const *argv[])
{
	string str1 = "acfgh";
	string str2 = "bcdegf";
	cout << lcsRec(str1, str2) << endl;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << lcsTopDown(str1, str2, 0, 0) << endl;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << dp[i][j] << ", ";
		}
		cout << endl;
	}
	cout << "----lcsBottomUp------" << endl;
	cout << lcsBottomUp(str1, str2) << endl;
	return 0;
}

