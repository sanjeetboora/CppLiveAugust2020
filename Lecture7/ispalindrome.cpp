#include <bits/stdc++.h>
using namespace  std;

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	 freopen("output.txt", "w", stdout);
// #endif
	int n = 5;
	int arr[10] = {1, 2, 3, 4, 5};

	// 1, 2, 3, 2, 1
	// 1, 2, 3, 3, 2, 1


	int i = 0, j = n - 1;
	bool isPalindrome = true;
	while (i <= j) {
		if (arr[i] != arr[j]) {
			isPalindrome = false;
			cout << "Array is not a palindrome" << endl;
			break;
		}
		i++;
		j--;
	}

	if (isPalindrome) {
		cout << "Array is palindrome" << endl;
	}

	return 0;
}




