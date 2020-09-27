#include <bits/stdc++.h>
using namespace std;

void codeOfString(string input, string output) {
	//base case
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	//self work
	//char one = input[0] + 'a' -'1' ;
	int one = input[0] - '0' ;
	int two = 0;
	if (input.length() > 1) {
		two = stoi(input.substr(0, 2));
	}

	//first call - considering 1 char
	char ch1 = 'a' + one - 1;
	string roi = input.substr(1);
	if (one == 0) {
		codeOfString(roi, output);
	} else {
		codeOfString(roi, output + ch1);
	}

	if (input.length() > 1 and two <= 26 and input[0] != '0') {
		//second call - considering 2 char
		char ch2 = 'a' + two - 1;
		roi = input.substr(2);
		codeOfString(roi, output + ch2);
	}

}


int main(int argc, char const *argv[])
{

	string str = "01234";
	codeOfString(str, "");

	return 0;
}

// '1' - '0' = 1
// 49 - 48 = 1


// one  = 1
// 2 + 'a' - 1 = 'b'

// 2 + 97 - 1= 98


// '1' + 'a' - '1' = 'a'
// 49  + 97  - 49 = 97

// '2' + 'a' - '1' = 'b'
// 50  + 97  - 49  = 98

// input => "1234"
// input[0] = '1' => 49
//            '1' - '0'
//            49 - 48 = 1