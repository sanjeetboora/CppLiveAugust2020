#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int val) {
	if (st.empty()) {
		st.push(val);
		return;
	}
	int t = st.top();
	st.pop();
	insertAtBottom(st, val);
	st.push(t);
}
void reverse(stack<int> &st) {
	if (st.empty()) {
		return;
	}
	int t = st.top(); //pick the top element
	st.pop();
	reverse(st);//reverse rest of stack
	insertAtBottom(st, t);//insert at bottom the picked element
}


int main(int argc, char const *argv[])
{	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);

	reverse(st);

	cout << st.top() << endl; //1
	st.pop();
	cout << st.top() << endl; //2
	st.pop();
	cout << st.top() << endl; //3
	st.pop();

	return 0;
}