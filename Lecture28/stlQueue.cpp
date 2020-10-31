/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	queue<string> q;

	// q.push("abc");
	// q.push("def");
	// q.push("ghi");
	// cout << q.size() << endl;
	// cout << q.back() << endl;
	// cout << q.front() << endl;
	// q.pop();
	// cout << q.front() << endl;
	// q.pop();
	// cout << q.front() << endl;
	// q.pop();
	// cout << q.size() << endl;

	deque<string> dq;
	dq.push_back("abc");
	dq.push_front("def");
	dq.push_back("ghi");

	for (auto x : dq) {
		cout << x << ", ";
	} cout << endl;

	cout << dq.front() << endl;
	dq.pop_front();
	cout << dq.front() << endl;
	dq.pop_front();
	cout << dq.front() << endl;
	dq.pop_front();


	return 0;
}

