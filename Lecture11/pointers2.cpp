#include <bits/stdc++.h>
using namespace  std;

void fun(int* arr, int arr1[10], int n) {
	cout << "inside fun" << endl;
	cout << arr << endl;
	cout << arr1 << endl;


}

int main(int argc, char const *argv[])
{

	int arr[10] = {1, 2 , 3, 4};
	int arr1[10] = {1, 2 , 3, 4};
	cout << "inside main" << endl;
	cout << arr << endl;
	cout << arr1 << endl;
	fun(arr, arr1, 4);

	return 0;
}