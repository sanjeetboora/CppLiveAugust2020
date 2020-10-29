#include <bits/stdc++.h>
using namespace std;

class Stack
{
	vector<int> v;
	int minimum;
public:
	bool isEmpty() {
		return v.size() == 0;
	}

	//insert an element
	void push(int x) {
		if (isEmpty()) {
			v.push_back(x);
			minimum = x;
		}
		else if (x < minimum) {
			v.push_back(2 * x - minimum);
			minimum = x;
		}
		else {
			v.push_back(x);
		}
	}
	//delete an element
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty, can't perform pop operation" << endl;
			return;
		}
		int toBePopped = v[v.size() - 1];
		if (toBePopped < minimum) {
			minimum = 2 * minimum - toBePopped;
		}
		v.pop_back();
	}
	//topmost element
	int top() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return -1;
		}
		int t = v[v.size() - 1];
		if (t < minimum) {
			t = minimum;
		}
		return t;
	}

	int getMin() {
		return minimum;
	}
};


int main(int argc, char const *argv[])
{
	Stack st;
	st.push(5);
	st.push(3);
	st.push(4);
	st.push(-1);
	st.push(2);
	cout << "top - " << st.top() << endl;
	cout << "minimum - " << st.getMin() << endl;
	st.pop();
	cout << "top - " << st.top() << endl;
	cout << "minimum - " << st.getMin() << endl;
	st.pop();
	cout << "top - " << st.top() << endl;
	cout << "minimum - " << st.getMin() << endl;
	st.pop();
	cout << "top - " << st.top() << endl;
	cout << "minimum - " << st.getMin() << endl;
	st.pop();
	cout << "top - " << st.top() << endl;
	cout << "minimum - " << st.getMin() << endl;
	st.pop();


	return 0;
}


