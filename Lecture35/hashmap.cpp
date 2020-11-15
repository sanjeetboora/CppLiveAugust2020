/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node {
public:
	string key;
	T value;
	node<T>* next;

	node(string k, T val) {
		key = k;
		value = val;
		next = NULL;
	}

	//destructor
	~node() {
		if (next != NULL) {
			delete next;
		}
	}
};

template<typename T>
class hashmap {
	node<T>** arr; //array to store address of nodes
	int totalSize;
	int currSize;
	int hashFunc(string str) {
		int idx = 0;
		int L = str.length();
		int multiplicationFactor = 1;

		for (int i = 0; i < L; ++i)
		{
			//multiplicationFactor = pow(37, i); O(L*L)
			int result = (str[L - i - 1] % totalSize * multiplicationFactor % totalSize) % totalSize;
			idx = (idx % totalSize + result % totalSize) % totalSize;
			multiplicationFactor = (multiplicationFactor % totalSize * 37 % totalSize) % totalSize;
		}
		return idx;
	}

	//(a + b) % x = (a % x + b % x) % x;


	void rehash() {
		node<T>** oldArray = arr;
		int oldSize = totalSize;

		totalSize  = 2 * totalSize;
		arr = new node<T>*[totalSize];
		currSize = 0;
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}

//copy all the elements from older array to newer array
		for (int i = 0; i < oldSize; ++i)
		{
			if (oldArray[i] != NULL) {
				node<T>* temp = oldArray[i];
				while (temp != NULL) {
					insert(temp->key, temp->value);
					temp = temp->next;
				}
			}
		}

//delete older array
		for (int i = 0; i < oldSize; ++i)
		{
			delete oldArray[i];
		}
		delete[] oldArray;

	}

public:

	hashmap(int defaultSize = 7) {
		totalSize = defaultSize;
		currSize = 0;
		arr = new node<T>*[totalSize];
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}
	}


	void insert(string k, T val) {
		int idx = hashFunc(k);
		node<T>* newNode = new node<T>(k, val);
		//arr[idx] -> head
		newNode->next = arr[idx]; //attach new node at head of LinkedList
		arr[idx] = newNode;
		currSize++;

		float loadFactor = (float)currSize / (float)totalSize;
		if (loadFactor > 0.7) {
			rehash();
		}
	}

	T* search(string k) {

		int idx = hashFunc(k);
		node<T>* temp = arr[idx];
		while (temp != NULL) {
			if (temp->key == k) {
				return &(temp->value);
			}
			temp = temp->next;
		}

		return NULL;
	}

	void print() {
		for (int i = 0; i < totalSize; ++i)
		{
			cout << i << " --> ";
			node<T>* temp =  arr[i];
			while (temp != NULL) {
				cout << "(" << temp->key << ", " << temp->value << ")";
				temp = temp->next;
			}
			cout << endl;
		}

		cout << "----------------------" << endl;
	}

	T& operator[](string k) {//this will return value by refernce
		T* valueAddress = NULL;
		if (search(k) != NULL) { //key already exists in hashmap
			valueAddress = search(k);
		}
		else { //key doesn't exists
			T garbageValue;
			insert(k, garbageValue);
			valueAddress = search(k);
		}
		return *valueAddress;
	}

};


// void funf(int &x) {
// 	x = 5;
// }




int main(int argc, char const *argv[])
{
	// int y = 10;
	// funf(y);


	hashmap<int> hp(5);

	hp.insert("abc", 10);
	hp.insert("banana", 780);
	hp.insert("mango", 280);
	hp.insert("grapes", 400);
	hp.insert("guava", 980);
	hp.insert("C++", 180);
	hp.print();
	cout << *hp.search("abc") << endl;
	//cout << *hp.search("def") << endl;

	// arr[0] = 10;
	// arr[0] = 11;
	hp["JAVA"] = 99; //hp.insert("JAVA", 99);
	hp.print();
	hp["JAVA"] = 100;
	hp.print();
	return 0;
}

