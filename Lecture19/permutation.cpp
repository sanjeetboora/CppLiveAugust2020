#include <bits/stdc++.h>
using namespace std;

void permutation(string input, string output) {
	//base case
	if (input == "") {
		cout << output << endl;
		return;
	}

	for (int i = 0; i < input.length(); i++) {
		char ch = input[i];
		string ros = input.substr(0, i) + input.substr(i + 1);

		permutation(ros, output + ch);
	}

}


int main(int argc, char const *argv[])
{
	string str = "abc";
	permutation(str, "");

	return 0;
}

// 0123 4 5678
// i = 4;
// input.substr(0, 4) + input.substr(5)
// input.substr(0, i) + input.substr(i+1)


