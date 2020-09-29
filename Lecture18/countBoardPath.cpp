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

	// pathCount += countBoardPath(start + 1, end, dice);
	// pathCount += countBoardPath(start + 2, end, dice);
	// pathCount += countBoardPath(start + 3, end, dice);
	// pathCount += countBoardPath(start + 4, end, dice);
	// pathCount += countBoardPath(start + 5, end, dice);
	// pathCount += countBoardPath(start + 6, end, dice);

	for (int d = 1; d <= dice ; d++)
	{
		pathCount += countBoardPath(start + d, end, dice);
	}

	return pathCount;

}


int main(int argc, char const *argv[])
{
	int N = 9;

	int dice = 6;


	int noOfWays = countBoardPath(0, N, dice);

	return 0;
}


// H.W. print count board path