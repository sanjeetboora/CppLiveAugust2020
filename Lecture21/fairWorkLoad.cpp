//https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> folders, int workers, int workLoad) {
	int worker = 1, load = 0;
	for (int i = 0; i < folders.size(); ++i)
	{
		if (load + folders[i] <= workLoad) { //curr worker can handle folders[i]
			load += folders[i];
		}
		else {
			worker++;
			load = folders[i];
		}
	}
	if (worker <= workers) {
		return true;
	}
	else {
		return false;
	}
}

int minWorkLoad(vector<int> folders, int workers) {
	int cabinets = folders.size();
	int minWork = *max_element(folders.begin(), folders.end());
	int maxWork = accumulate(folders.begin(), folders.end(), 0);

	while (minWork < maxWork) {
		int currWork = minWork + (maxWork - minWork) / 2;
		if (isPossible(folders, workers, currWork)) {
			maxWork = currWork;
		}
		else {
			minWork = currWork + 1;
		}

	}
	return minWork;
}


int main(int argc, char const *argv[])
{
	vector<int> folders = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 };
	int workers = 2;

	cout << minWorkLoad(folders, workers) << endl;

	return 0;
}


// Book Allocation
// Painter's Problem
// CB Winning Scholarship


