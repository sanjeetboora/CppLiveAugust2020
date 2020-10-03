#include <bits/stdc++.h>
using namespace std;

void printBoard(int board[10][10], int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++) {
			if (board[i][j]) {
				cout << "Q ";
			}
			else {
				cout << "_ ";
			}
		}
		cout << endl;
	}
}

bool isSafe(int board[10][10], int col, int row, int n) {

	//column safe
	int c = col;
	int r = row;

	while (r >= 0) {
		if (board[r][c] == 1) {
			return false;
		}
		r--;
	}

	//left diagonal
	c = col;
	r = row;
	while (r >= 0 and c >= 0) {
		if (board[r][c] == 1) {
			return false;
		}
		r--;
		c--;
	}
	//right diagonal
	c = col;
	r = row;
	while (r >= 0 and c < n) {
		if (board[r][c] == 1) {
			return false;
		}
		r--;
		c++;
	}

	return true;
}

bool nQueen(int board[10][10], int n, int row) {
	//base case
	if (row == n) {
		printBoard(board, n);
		return true;
	}

	for (int col = 0; col < n; col++) {
		if (isSafe(board, col, row, n)) {
			board[row][col] = 1;
			bool aageQueenRakPaye = nQueen(board, n, row + 1);

			if (aageQueenRakPaye == true) {
				return true;
			}
			if (aageQueenRakPaye == false) {
				board[row][col] = 0;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int board[10][10] = {0};
	int n = 8;

	nQueen(board,  n, 0);

	return 0;
}
