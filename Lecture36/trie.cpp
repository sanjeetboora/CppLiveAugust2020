/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	char data;
	bool isTerminated;
	unordered_map<char, node*> children;

	node(char ch) {
		data = ch;
		isTerminated = false;
	}
};

class trie
{
public:
	node* root;
	trie() {
		root = new node('\0');
	}

	void insert(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			char ch = word[i];
			if (!temp->children.count(ch)) {//ch doesn't exists in children
				node* child = new node(ch);
				temp->children[ch] = child;
			}
			temp = temp->children[ch];
		}
		temp->isTerminated = true;
	}

	bool search(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			char ch = word[i];
			if (!temp->children.count(ch)) {//ch doesn't exists in children
				return false;
			}
			temp = temp->children[ch];
		}
		return temp->isTerminated;
	}

};

int main(int argc, char const *argv[])
{
	trie t;

	t.insert("apple");
	cout << t.search("app") << endl;
	t.insert("app");
	cout << t.search("app") << endl;
	t.insert("ape");
	t.insert("mango");
	t.insert("man");
	cout << t.search("man") << endl;
	cout << t.search("mango") << endl;
	t.insert("guava");

	return 0;
}

