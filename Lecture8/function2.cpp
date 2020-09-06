#include <bits/stdc++.h>
using namespace std;

int globalVariable =  50;


//pass by value
int func1(int N) {

	N = N + 20;
	cout << "N: " << N << endl;
	return N;
}

//pass by reference
int func2(int &N) {

	N = N + 20;
	cout << "N: " << N << endl;
	return N;
}


// int func3(int arr[10]) {


// }
// int func3(int* arr) {


// }


int main()
{
	int x = 10;
	int y = func1(x);
	cout << "y: " << y << endl;


	func1(x); //pass by value
	cout << "x: " << x << endl;

	// func2(x); //pass by reference
	// cout << "x: " << x << endl;

	// int arr[10] = {1, 2, 3};

	// func3(arr);



	return 0;
}