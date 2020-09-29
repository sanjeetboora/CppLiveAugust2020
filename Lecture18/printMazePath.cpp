#include <bits/stdc++.h>
using namespace std;

void printMazePath(int i, int j, int rows, int cols, string output) {
	if (i == rows - 1 and j == cols - 1) {
		cout << output << endl;
		return;
	}
	if ( i >= rows or j >= cols) {
		cout << "invalid cases -> " << output << endl;
		return;
	}

	//horizontal
	printMazePath(i, j + 1, rows, cols, output + "H");
	//vertical
	printMazePath(i + 1, j, rows, cols, output + "V");

}


void printMazePathDiagonally(int i, int j, int rows, int cols, string output) {
	if (i == rows - 1 and j == cols - 1) {
		cout << output << endl;
		return;
	}
	if ( i >= rows or j >= cols) {
		cout << "invalid cases -> " << output << endl;
		return;
	}

	//horizontal
	printMazePathDiagonally(i, j + 1, rows, cols, output + "H");
	//vertical
	printMazePathDiagonally(i + 1, j, rows, cols, output + "V");
	//diagnoal
	printMazePathDiagonally(i + 1, j + 1, rows, cols, output + "D");

}


int main(int argc, char const *argv[])
{
	int rows = 3, cols = 4;

	//printMazePath(0, 0, rows, cols, "");
	printMazePathDiagonally(0, 0, rows, cols, "");
	return 0;
}


//count maze path