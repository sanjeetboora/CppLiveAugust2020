#include <bits/stdc++.h>
using namespace std;

class Stack
{
	vector<int> v;
public:
	bool isEmpty() {
		return v.size() == 0;
	}

	//insert an element
	void push(int x) {
		v.push_back(x);
	}
	//delete an element
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty, can't perform pop operation" << endl;
			return;
		}
		v.pop_back();
	}
	//topmost element
	int top() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return -1;
		}
		return v[v.size() - 1];
	}
};


int main(int argc, char const *argv[])
{
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.top() << endl; //3
	st.pop();
	cout << st.top() << endl; //2
	st.pop();
	cout << st.top() << endl; //1
	st.pop();
	cout << st.top() << endl; //Stack empty -1
	st.pop();					//error

	return 0;
}


