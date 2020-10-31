/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

void printMaxinSubarrayOfSizeK(int* arr, int k, int n) {
	deque<int> dq(k); //store indexes in this deque

	int i = 0;
	//for first k elements
	for ( i = 0; i < k ; ++i)
	{
		while (!dq.empty() and arr[dq.back()] < arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

	//for rest of the elements (i>=k)
	for (i = k; i < n; ++i)
	{	cout << arr[dq.front()] << endl; //print max element
		//all indexes of earlier window will be removed
		while (!dq.empty() and dq.front() <= i - k) {
			dq.pop_front();
		}
		//remove smaller elements of current window
		while (!dq.empty() and arr[dq.back()] < arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout << arr[dq.front()] << endl; //print max element
}


int main(int argc, char const *argv[])
{
	int arr[10] = {10, 1, 8, 0, 6, 9, 11};
	int sz = 7;
	printMaxinSubarrayOfSizeK(arr, 3, sz);
	return 0;
}
