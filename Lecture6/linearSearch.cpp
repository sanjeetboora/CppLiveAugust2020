#include <bits/stdc++.h>
using namespace  std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, key;
	cin >> n >> key;

	int arr[100] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//if key found then print "key found"

	//else print "key not found"


	//1st Way
	// bool keyFound = false; //key abhi nai mili
	// for (int i = 0; i < n; ++i)
	// {
	// 	if (arr[i] == key) {
	// 		keyFound = true; //key mil gyi
	// 		cout << key << " found at index " << i << endl;
	// 		break;
	//	}
	// }
	// if (!keyFound) { //kya key mil gyi?
	// 	cout << "key not found" << endl;
	// }


	//2nd way
	int i = 0;
	for (; i < n; ++i)
	{
		if (arr[i] == key) {
			cout << key << " found at index " << i << endl;
			break;
		}
	}
	if (i == n) {
		cout << "key not found" << endl;
	}


	return 0;
}




