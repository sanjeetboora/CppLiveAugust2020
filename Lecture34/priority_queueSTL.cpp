/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//priority_queue<int> pq; //by default max heap

	priority_queue<int, vector<int>, greater<int> >pq; //min heap

	pq.push(10);
	pq.push(100);
	pq.push(20);
	pq.push(90);
	pq.push(5);
	cout << "size : " << pq.size() << endl;
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();

	return 0;
}

