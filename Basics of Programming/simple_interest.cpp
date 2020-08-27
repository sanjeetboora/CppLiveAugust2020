#include <iostream>

using namespace std;

int main() {

	// int a; // dec
	// a = 10; // initialization


	// int a = 10; // dec + ini

	// declaration
	int p;
	int r;
	int t;

	cout << "Enter Principle Amount" << endl;
	cin >> p;

	cout << "Enter rate " << endl;
	cin >> r;

	cout << "Enter time " << endl;
	cin >> t;


	cout << "Teeno mil gaye :D" << endl;

	// cout << "Time hai mere pas " << t << endl; // A

	cout << "Time hai mere pas "; // B
	cout << t << endl; // B

	cout << "Rate hai mere pas " << r << endl;
	cout << "Principle hai mere pas " << p << endl;

	cout << "******************************" << endl;

	int si = (p * r * t) / 100;

	cout << "Simple Interest is " << si << endl;

	return 0;
}