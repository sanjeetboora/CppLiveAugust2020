#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//declaration of an array

	//data_type variable-name[size];

	// int arr[10]; //67890
	// arr[1] = 20;
	// arr[7] = 80;
	// cout << arr[1] << endl;

	// for (int i = 0; i <= 9 ; ++i)
	// {
	// 	cout << i << " --> " << arr[i] << endl;
	// }
	// cout << "-----------------" << endl;
	// //initialization
	// int arr1[10] = {0};
	// for (int i = 0; i <= 9 ; ++i)
	// {
	// 	cout << i << " --> " << arr1[i] << endl;
	// }

	// cout << "-----------------" << endl;
	// int arr2[10] = {1};
	// for (int i = 0; i <= 9 ; ++i)
	// {
	// 	cout << i << " --> " << arr2[i] << endl;
	// }
	// cout << "-----------------" << endl;
	// int arr3[5] = {1, 2, 4, 5};
	// for (int i = 0; i <= 4 ; ++i)
	// {
	// 	cout << i << " --> " << arr3[i] << endl;
	// }

	// cout << "-----------------" << endl;

	int arr5[10];

	// for (int i = 0; i < 10; ++i)
	// {
	// 	//arr5[i] = i * i;
	// 	cin >> arr5[i];
	// }
	// for (int i = 0; i < 10 ; ++i)
	// {
	// 	cout << i << " --> " << arr5[i] << endl;
	// }

	cout << arr5 << endl;

	cout << &(arr5[0]) << endl;

	cout << &(arr5[1]) << endl;
	cout << &(arr5[2]) << endl;

	cout << arr5 + 1 << endl;

	// char charr[10] = {'a', 'b', 'c'};
	bool charr[5];
	cout << "charr -> " << charr << endl;
	cout << "charr+1 -> " << charr + 1 << endl;

	//dynamic input for array size

	int n;
	cin >> n;

	int arr6[n]; //some compilers doesn't support this

	//max elements 100
	int arr7[100];








	return 0;
}




