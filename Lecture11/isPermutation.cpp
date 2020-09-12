#include <bits/stdc++.h>
using namespace  std;

void printArray(int arr[10], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

bool isPermutation(int n , int* A, int B[10]) {

	int minEle = *min_element(A, A + n);
	int maxEle = *max_element(A, A + n);

	cout << minEle << endl;
	cout << maxEle << endl;

	int freqSize = maxEle - minEle + 1;
	int freqArr[freqSize];

	for (int i = 0; i < freqSize; ++i) //initialize freq array with 0
	{
		freqArr[i] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		freqArr[A[i] - minEle]++;
	}

	for (int i = 0; i < n; ++i)
	{
		freqArr[B[i] - minEle]--;
	}

	for (int i = 0; i < freqSize; ++i)
	{
		if (freqArr[i] != 0) {
			return false;
		}
	}
	return true;
}


int main()
{
	int n = 5;
	int B[10] = { -5, 3, -3, 1, 4};
	int A[10] = { 1, -3, -5, 4, 3};

	if (isPermutation(n, A, B)) {
		cout << "both the arrays are Permutation of each other" << endl;
	}
	else {
		cout << "both the arrays are not the Permutation of each other" << endl;
	}

	return 0;
}




