#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

	vector<int> v;

	cout << "size of vector ->" << v.size() << endl;
	cout << "capacity of vector ->" << v.capacity() << endl;

	vector<int> v1(10, -1);

	v1[1] = 10;

	for (int x = 0; x < v1.size(); x++) {
		cout << v1[x] << ",";
	}
	cout << endl;

	*v1.begin() = 20;

	for (int x = 0; x < v1.size(); x++) {
		cout << v1[x] << ",";
	}

	// v.push_back(1);
	// cout << "size of vector ->" << v.size() << endl;
	// cout << "capacity of vector ->" << v.capacity() << endl;

	// v.push_back(2);
	// cout << "size of vector ->" << v.size() << endl;
	// cout << "capacity of vector ->" << v.capacity() << endl;

	// v.push_back(3);
	// cout << "size of vector ->" << v.size() << endl;
	// cout << "capacity of vector ->" << v.capacity() << endl;

	// v.push_back(4);
	// cout << "size of vector ->" << v.size() << endl;
	// cout << "capacity of vector ->" << v.capacity() << endl;

	// v.push_back(5);
	// cout << "size of vector ->" << v.size() << endl;
	// cout << "capacity of vector ->" << v.capacity() << endl;

	// cout << v.max_size() << endl;

	// cout << v[4] << endl;
	// v.pop_back();
	// cout << v[4] << endl;



	return 0;
}