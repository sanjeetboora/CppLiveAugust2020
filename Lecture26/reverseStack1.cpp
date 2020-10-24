#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int> &A) {
	stack<int> B;
	stack<int> C;

	//transfer all elements from A to B
	while (!A.empty()) {
		B.push(A.top());
		A.pop();
	}

	//transfer all elements from B to C
	while (!B.empty()) {
		C.push(B.top());
		B.pop();
	}
	//transfer all elements from C to A
	while (!C.empty()) {
		A.push(C.top());
		C.pop();
	}
}


int main(int argc, char const *argv[])
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);

	reverse(st);

	cout << st.top() << endl; //3
	st.pop();
	cout << st.top() << endl; //2
	st.pop();
	cout << st.top() << endl; //1
	st.pop();

	return 0;
}