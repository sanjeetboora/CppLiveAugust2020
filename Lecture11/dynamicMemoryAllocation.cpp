#include <bits/stdc++.h>
using namespace  std;

int main(int argc, char const *argv[])
{
	int n = 10; //stack

	//heap
	int *m1 = new int(); //declaration
	int *m = new int(10); //initialization

	*m1 = n;
	cout << *m1 << endl;


	cout << "n -> " << n << endl;
	cout << "m -> " << *m << endl;

	int arr[10]; //stack

	int* arr1 = new int[10];

	int* arr2 = new int[n];

	for (int i = 0; i < 10; ++i)
	{
		arr[i] = i * i;
		arr1[i] = i * i;
		arr2[i] = i * i;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << ", " << arr1[i] << "," << arr2[i] << endl;
	}

	return 0;
}