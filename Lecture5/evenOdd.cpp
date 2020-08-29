#include <bits/stdc++.h>
using namespace  std;

//function
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//practice
	// X = 5623457
	// evenDigitSum = 6+2+4
	// oddDigitSum = 5+3+5+7
	int x;
	cin >> x;
	int sumEven = 0, sumOdd = 0;
	// while (x) {
	// 	int digit = x % 10;
	// 	if (digit % 2 == 0) { //even
	// 		sumEven = sumEven + digit;
	// 	}
	// 	else {
	// 		sumOdd = sumOdd + digit;
	// 	}
	// 	x = x / 10;

	// }

	while (x) {
		int digit = x % 10;
		if (digit & 1) { //odd

			sumOdd = sumOdd + digit;
		}
		else {//even
			sumEven = sumEven + digit;
		}
		x = x / 10;

	}


	cout << "sumOdd : " << sumOdd << " " << "sumEven : " << sumEven << endl;

	return 0;
}




