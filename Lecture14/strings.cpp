#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char crr[3];
	//cin >> crr;

	char arr[6] = {'a', 'b', 's', 'e', 't', '\0'};
	cout << arr << endl;

	int arr1[5] = {1, 2, 3, 4, 5};
	cout << arr1 << endl;

	string st = "a bcdefj,fl ksdl";
	cout << st << endl;

	cout << st.length() << endl;

	reverse(st.begin(), st.end());
	cout << st << endl;

	string s1 = "abcdefghijklmnop";

	string s2 = s1.substr(3, 4); //first arg -> start index, second arg -> length of substring

	string s3 = s1.substr(2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	char ch = s1[1];
	cout << ch << endl;

	return 0;
}





