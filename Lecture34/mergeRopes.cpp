/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int minCost(int* ropes, int n) {
	priority_queue<int, vector<int>, greater<int> >pq;
	for (int i = 0; i < n; ++i)
	{
		pq.push(ropes[i]);
	}
	int totalcost = 0;
	while (pq.size() > 1) {
		int firstRope = pq.top();
		pq.pop();
		int secondRope = pq.top();
		pq.pop();
		int currentRopeCost = (firstRope + secondRope);
		totalcost += currentRopeCost;
		pq.push(currentRopeCost);
		cout << firstRope << ", " << secondRope << endl;
	}
	return totalcost;
}

int main(int argc, char const *argv[])
{	int n = 5;
	int arr[10] = {2, 3, 4 , 6 , 7};
	cout << minCost(arr, n) << endl;
	return 0;
}

