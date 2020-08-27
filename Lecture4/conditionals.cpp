#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int marks;
	cin >> marks;
	// if (marks >= 33) {
	// 	cout << "pass" << endl;
	// }
	// else {
	// 	cout << "fail" << endl;
	// }
	if (marks < 33) {
		cout << "fail" << endl;
	}
	else if (marks >= 33 && marks < 50) {
		cout << "bas pass1" << endl;
	}
	else if (marks >= 50 && marks < 75) {
		cout << "bas pass2" << endl;
	}
	else {
		cout << "distinction" << endl;
	}





	return 0;
}



