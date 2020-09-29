#include <bits/stdc++.h>
using namespace std;


bool isSafe(int i, int j, int rows, int cols, int maze[][10]) {
	if ( i >= 0 and j >= 0 and i < rows and j < cols and maze[i][j] == 0) {
		return true;
	}
	return false;
}

bool isPossibleRatMaze(int i, int j, int rows, int cols, int maze[][10]) {
	//base case
	if (i == rows - 1 and j == cols - 1) {
		return true;
	}

	if (isSafe(i, j, rows, cols, maze)) {

		//move horizontal
		bool Hresult = isPossibleRatMaze(i, j + 1, rows, cols, maze);
		if (Hresult) {
			return true;
		}

		//move vertical
		bool Vresult = isPossibleRatMaze(i + 1, j, rows, cols, maze);
		if (Vresult) {
			return true;
		}

		return false;
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int maze[10][10] = {
		{0, 0, 0, 1},
		{1, 0, 0, 0},
		{1, 0, 1, 1},
		{0, 0, 1, 0}
	};

	int rows = 4, cols = 4;
	bool result = isPossibleRatMaze(0, 0, rows, cols, maze);

	if (result) {
		cout << "path exists" << endl;
	}
	else {
		cout << "path doesn't exist" << endl;
	}

	return 0;
}


//Print all possible paths
//Count all possible paths