#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// stack<int> st;
	// st.push(1);
	// st.push(2);
	// st.push(3);
	// cout << st.top() << endl; //3
	// st.pop();
	// cout << st.top() << endl; //2
	// st.pop();
	// cout << st.top() << endl; //1
	// st.pop();
	// cout << st.top() << endl;
	// st.pop();

	stack<string> st;
	st.push("abc");
	st.push("def");
	st.push("ghi");
	cout << st.top() << endl;
	st.pop();
	cout << st.empty() << endl;
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();
	cout << st.empty() << endl;
	cout << st.top() << endl;
	st.pop();

	return 0;
}