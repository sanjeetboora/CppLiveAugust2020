/* Problem -  Top K elements*/
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> >pq) {
	while (!pq.empty()) {
		cout << pq.top() << ", ";
		pq.pop();
	}
	cout << endl;
}

void topKElements(int k) {
	priority_queue<int, vector<int>, greater<int> >pq; //min heap
	int n;
	cin >> n;
	while (n != -1000) {
		if (n != -1) {
			if (pq.size() < k) {
				pq.push(n);
			}
			else if (pq.top() < n) {
				pq.pop();
				pq.push(n);
			}
		}
		else { //this is a query - print heap
			printHeap(pq);
		}
		cin >> n;
	}
}


int main(int argc, char const *argv[])
{
	int k = 3;
	topKElements(k);
	return 0;
}

