#include <bits/stdc++.h>
using namespace std;

string keypad[10] = {"_", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void keypadCombination( string input, string output) {
	//base case
	if (input == "") {
		cout << output << endl;
		return;
	}

	//self work
	char ch = input[0];
	string ros = input.substr(1);
	int idx = ch - '0';
	string code = keypad[idx];

	for (int i = 0; i < code.length(); i++) {
		//recursive case
		keypadCombination(ros, output + code[i]);
	}
}


int main(int argc, char const *argv[])
{
	string input = "267";

	keypadCombination(input, "");

	return 0;
}


//count keypad Combination