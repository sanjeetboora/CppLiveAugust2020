#include <bits/stdc++.h>
using namespace std;


void permutation(char* arr, int idx) {
	if (arr[idx] == '\0') {
		cout << arr << endl;
		return;
	}

	for (int j = idx; arr[j] != '\0'; j++) {
		swap(arr[idx], arr[j]);
		permutation(arr, idx + 1);
		swap(arr[idx], arr[j]); //backtracking
	}

}



int main(int argc, char const *argv[])
{
	char str[10] = {'a', 'b', 'c', '\0'};
	permutation(str, 0);
	return 0;
}