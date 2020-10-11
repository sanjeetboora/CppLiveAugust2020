//https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int dis, int* stalls, int cows, int s) {
	cows--; //first cow placed at stalls[0];
	int lastCowPlacedAtIdx = 0;

	for (int i = 1; i < s; ++i)
	{
		if (stalls[i] - stalls[lastCowPlacedAtIdx] >= dis) {
			cows--;
			lastCowPlacedAtIdx = i;
		}
		if (cows == 0) {
			return true;
		}
	}
	if (cows > 0) {
		return false;
	}
}


int minDistance(int s, int cows, int* stalls) {
	sort(stalls, stalls + s);
	int minDis = 1, maxDis = stalls[s - 1] - stalls[0];
	int ans = 1;
	while (minDis <= maxDis) {
		int mid = minDis + (maxDis - minDis) / 2;
		bool cowsKoRakhPaye = isPossible(mid, stalls, cows, s);
		if (cowsKoRakhPaye) {
			ans = mid;
			minDis = mid + 1;
		}
		else {
			maxDis = mid - 1;
		}

	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int s, cows;
		cin >> s >> cows;
		int*stalls = new int[s];
		for (int i = 0; i < s; ++i)
		{
			cin >> stalls[i];
		}

		cout << minDistance(s, cows, stalls) << endl;

	}
	return 0;
}