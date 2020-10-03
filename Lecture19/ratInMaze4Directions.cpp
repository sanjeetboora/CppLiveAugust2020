#include <bits/stdc++.h>
using namespace std;

void printMaze1(int maze[10][10], int i, int j, int rows, int cols, string output, int visited[10][10]) {
	if (i == rows - 1 and j == cols - 1) {
		cout << output << endl;
		return;
	}
	if ( i >= rows or j >= cols or i < 0 or j < 0 or visited[i][j] == 1 or maze[i][j] == 1) {
		// cout << "invalid cases -> " << output << endl;
		return;
	}

	visited[i][j] = 1;
	//right
	printMaze1(i, j + 1, rows, cols, output + "R", visited);
	//down
	printMaze1(i + 1, j, rows, cols, output + "D", visited);
	//left
	printMaze1(i, j - 1, rows, cols, output + "L", visited);
	//up
	printMaze1(i - 1, j, rows, cols, output + "U", visited);
	visited[i][j] = 0;

}



void printMaze(int i, int j, int rows, int cols, string output, int visited[10][10]) {
	if (i == rows - 1 and j == cols - 1) {
		cout << output << endl;
		return;
	}
	if ( i >= rows or j >= cols or i < 0 or j < 0 or visited[i][j] == 1) {
		// cout << "invalid cases -> " << output << endl;
		return;
	}

	visited[i][j] = 1;
	//right
	printMaze(i, j + 1, rows, cols, output + "R", visited);
	//down
	printMaze(i + 1, j, rows, cols, output + "D", visited);
	//left
	printMaze(i, j - 1, rows, cols, output + "L", visited);
	//up
	printMaze(i - 1, j, rows, cols, output + "U", visited);
	visited[i][j] = 0;

}


int main(int argc, char const *argv[])
{
	int rows = 3, cols = 4;

	//printMazePath(0, 0, rows, cols, "");
	int visited[10][10] = {0};
	printMaze(0, 0, rows, cols, "", visited);
	return 0;
}


//count maze path