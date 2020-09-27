#include <bits/stdc++.h>
using namespace std;

void printBStrings(string output, int n) {
	//base case
	if (n == 0 and output != "") {
		cout << output << endl;
		return;
	}

	int count = 0;

	if (output == "" or output[output.length() - 1] == '0') {
		printBStrings(output + "0", n - 1);
		printBStrings(output + "1", n - 1);
	}
	else {
		printBStrings(output + "0", n - 1);
	}
	return;
}

int countBStrings(string output, int n) {
	//base case
	if (n == 0 and output == "") return 0;
	if (n == 0 and output != "") {
		cout << output << endl;
		return 1;
	}

	int count = 0;

	if (output == "" or output[output.length() - 1] == '0') {
		count = countBStrings(output + "0", n - 1) + countBStrings(output + "1", n - 1);
	}
	else {
		count = countBStrings(output + "0", n - 1);
	}
	return  count;

}

int main(int argc, char const *argv[])
{

	int count = 0;
	int n = 3;
	cout << countBStrings("", n) << endl;

	printBStrings("", n)
	return 0;
}