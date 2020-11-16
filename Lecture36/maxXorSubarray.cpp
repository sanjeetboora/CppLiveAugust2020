/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* zero;
	node* one;
	int prefixXor;
	node(int d) {
		data = d;
		zero = NULL;
		one = NULL;
		prefixXor = 0;
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
		temp->prefixXor = num;
	}

	int xorQuery(int  num) {

		node* temp = root;
		for (int j = 31; j >= 0; j--)
		{
			int currBit = (num >> j) & 1;
			if (currBit) { //currBit == 1
				if (temp->zero) {
					temp = temp->zero;
				}
				else {
					temp = temp->one;
				}
			}
			else { //currBit == 0
				if (temp->one) {
					temp = temp->one;
				}
				else {
					temp = temp->zero;
				}
			}
		}

		int numxor = num xor temp->prefixXor;

		return numxor;
	}

};

int main(int argc, char const *argv[])
{
	trie t;

	int arr[10] = {8, 2, 1, 12, 7, 6};
	int n = 6;
	int prefixXor = 0;
	int maxXorSubarrayPair = 0;
	for (int i = 0; i < n; ++i)
	{
		prefixXor = arr[i] xor prefixXor;
		t.insert(prefixXor);
		maxXorSubarrayPair = max(maxXorSubarrayPair, t.xorQuery(prefixXor));
	}

	cout << maxXorSubarrayPair << endl;

	return 0;
}

