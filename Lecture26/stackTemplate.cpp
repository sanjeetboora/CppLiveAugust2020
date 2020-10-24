#include <bits/stdc++.h>
using namespace std;
// pair<int, string *arr> p;
// pair<int, pair<string, int> > p;]
// template<typename T, typename V> //multiple data types
// template<typename T, typename V>
// Pair{
// 	T x;
// 	V y;
// }

template<typename T>
class Stack
{
	vector<T> v;
public:
	bool isEmpty() {
		return v.size() == 0;
	}

	//insert an element
	void push(T x) {
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
	T top() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return NULL;
		}
		return v[v.size() - 1];
	}
};


int main(int argc, char const *argv[])
{
	Stack<string> st;
	st.push("1");
	st.push("2");
	st.push("3");
	cout << st.top() << endl; //3
	st.pop();
	cout << st.top() << endl; //2
	st.pop();
	cout << st.top() << endl; //1
	st.pop();
	cout << st.top() << endl;
	st.pop();					//error

	return 0;
}


