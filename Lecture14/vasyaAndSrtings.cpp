#include <bits/stdc++.h>
using namespace std;

int longestSubstring(int n, int k, string str) {

	int left = 0, right = 0;
	int maxLen = 0;
	int count[2] = {0};

	while (right < n) {

		//str[right] - 'a' => a = 0 , b = 1

		count[ str[right] - 'a' ]++;

		if (min(count[0], count[1]) > k) {
			count[str[left] - 'a']--;
			left++;
		}
		else {
			maxLen++;
		}
		right++;
	}

	return maxLen;

}

int main(int argc, char const *argv[])
{
	// int n, k;
	// string str;

	// cin >> n >> k >> str;

	int n = 8, k = 1;
	string str = "aabaabaa";
	int maxLen = longestSubstring(n, k, str);
	cout << maxLen << endl;

	return 0;
}