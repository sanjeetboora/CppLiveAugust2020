#include <bits/stdc++.h>
using namespace  std;

//function
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x;
	// cin >> x;
	// while (x != 5) {
	// 	cout << x << endl;
	// 	cin >> x;
	// }

	while (true) { //loop
		cin >> x;
		if (x % 2 == 0) { //condition
			break;
		}
		cout << x << endl;

	}

	cout << "-------break------" << endl;
	for (int i = 0; i < 5; i++) {
		for (int x = 0; x < 3; x++) {
			if (i == 2 and x == 1) {
				break;
			}
			cout << i << " " << x << endl;
		}
	}


	cout << "-------continue------" << endl;
	for (int i = 0; i < 5; i++) {
		for (int x = 0; x < 3; x++) {
			if (i == 2 and x == 1) {
				continue;
				cout << i << " " << x << endl;
			}
			cout << i << " " << x << endl;
		}
	}
	cout << "-------return------" << endl;
	for (int i = 0; i < 5; i++) {
		for (int x = 0; x < 3; x++) {
			if (i == 2 and x == 1) {
				return 0;
				cout << i << " " << x << endl;
			}
			cout << i << " " << x << endl;
		}
	}

	cout << "program ended" << endl;


//practice
	// X = 5623457
	// evenDigitSum = 6+2+4
	// oddDigitSum = 5+3+5+7



	return 0;
}




