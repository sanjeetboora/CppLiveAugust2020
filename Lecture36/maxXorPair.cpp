/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* zero;
	node* one;

	node(int d) {
		data = d;
		zero = NULL;
		one = NULL;
	}
};

class trie
{
public:
	node* root;
	trie() {
		root = new node('\0');
	}

	void insert(int num) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) //total 32 bits in a number
		{
			int currBit = (num >> i) & 1;
			if (currBit) {	//currBit == 1
				if (temp->one == NULL) {
					node* bit = new node(1);
					temp->one = bit;
				}
				temp = temp->one;
			}
			else {//currBit == 1
				if (temp->zero == NULL) {
					node* bit = new node(0);
					temp->zero = bit;
				}
				temp = temp->zero;
			}
		}
	}

	int maxXorPair(int* arr, int n) {
		int maxXor = 0;

		for (int i = 0; i < n; ++i)
		{
			int num = arr[i];
			int numXor = 0;

			node* temp = root;
			for (int j = 31; j >= 0; j--)
			{
				int currBit = (num >> j) & 1;
				if (currBit) { //currBit == 1
					if (temp->zero) {
						numXor += pow(2, j);
						temp = temp->zero;
					}
					else {
						temp = temp->one;
					}
				}
				else { //currBit == 0
					if (temp->one) {
						numXor += pow(2, j);
						temp = temp->one;
					}
					else {
						temp = temp->zero;
					}
				}
			}
			maxXor = max(maxXor, numXor);
		}
		return maxXor;
	}

};

int main(int argc, char const *argv[])
{
	trie t;

	int arr[10] = {3, 2, 1, 6, 5};
	int n = 5;
	for (int i = 0; i < n; ++i)
	{
		t.insert(arr[i]);
	}

	cout << t.maxXorPair(arr, n) << endl;

	return 0;
}

