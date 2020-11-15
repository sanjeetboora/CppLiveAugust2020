/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	unordered_map<string, int> mp;

	pair<string, int> p = make_pair("apple", 100);
	mp.insert(p);

	mp.insert(make_pair("guava", 200));
	mp.insert({"pear", 300});

	mp["C++"] = 900;

	for (auto x : mp)
	{
		cout << x.first << ", " << x.second << endl;
	}

	for (pair<string, int> x : mp)
	{
		cout << x.first << ", " << x.second << endl;
	}


	if (mp.find("gapple") != mp.end()) {
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}

	cout << mp.count("C++") << endl;
	cout << mp.count("JAVA") << endl;

	return 0;
}






