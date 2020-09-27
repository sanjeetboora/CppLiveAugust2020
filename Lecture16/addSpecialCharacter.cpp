#include <bits/stdc++.h>
using namespace std;

void specialString(string input, string output) {

	if (input  == "") {
		cout << output << endl;
		return;
	}

	//self work
	if (input.length() > 1 and input[0] == 'a' and input[1] == 'a') {
		output += input[0];
		output += "#";

		string ros = input.substr(1);
		specialString(ros, output);
	}
	else {
		output += input[0];
		string ros = input.substr(1);
		specialString(ros, output);
	}
	return ;

}


int main(int argc, char const *argv[])
{
	string input = "gfaaajhaadealhaajha";
	specialString(input, "");
	return 0;
}