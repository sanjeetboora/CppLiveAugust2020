#include <bits/stdc++.h>
using namespace std;

//print subsequences of "012" for given "abc"
void subsequences2(string input, string output) {
	if (input == "") {
		cout << output << endl;
		return;
	}

	char ch = input[0];
	int chInt = ch - 'a';
	char intForCharValue = chInt + '0';
	string ros = input.substr(1);

	subsequences2(ros, output + intForCharValue);
	subsequences2(ros, output);
}

//print subsequences of "abc" for given "012"
void subsequences1(string input, string output) {
	if (input == "") {
		cout << output << endl;
		return;
	}

	char ch = input[0];
	int chInt = ch - '0';
	char charForIntValue = 'a' + chInt;
	string ros = input.substr(1);

	subsequences1(ros, output + charForIntValue);
	subsequences1(ros, output);

}

//print subsequences of "abc" for given "abc"
void subsequences(string input, string output) {
	if (input == "") {
		cout << output << endl;
		return;
	}

	char ch = input[0];
	string ros = input.substr(1);

	subsequences(ros, output + ch);
	subsequences(ros, output);

}


int main(int argc, char const *argv[])
{
	string str = "abc";
	string str1 = "012";
	subsequences2(str, "");
	subsequences1(str1, "");
	subsequences(str, "");

	return 0;
}