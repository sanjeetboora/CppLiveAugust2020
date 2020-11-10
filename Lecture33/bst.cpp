/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};


node* insert(node* root, int d) {
	if (root == NULL) {
		root = new node(d);
		return root;
	}

	if (d <= root->data) {	//put it in left
		root->left = insert(root->left, d);
	}
	else { //put it in right
		root->right = insert(root->right, d);
	}
	return root;
}

node* buildBST() {
	node* root = NULL;
	int d;
	cin >> d;

	while (d != -1) {
		root = insert(root, d);
		cin >> d;
	}

	return root;
}

bool search(node* root, int key) {
	if (root == NULL) {
		return false;
	}
	if (key == root->data) { //key found
		return true;
	}
	else if (key < root->data) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}

node* deleteInBST(node* root, int key) {
	if (root == NULL) {
		return NULL;
	}

	if (key > root->data) {
		root->right = deleteInBST(root->right, key);
	}
	else if (key < root->data) {
		root->left = deleteInBST(root->left, key);
	}
	else { //node found
		//node is a leaf node
		if (root->left == NULL and root->right == NULL) {
			delete root;
			return NULL;
		}
		//node has only left child
		else if (root->left != NULL and root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		//node has only right child
		else if (root->left == NULL and root->right != NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		//node has both children
		else {
			//replacing by left subtree's maximum
			node* temp = root->left;
			while (temp->right != NULL) {
				temp = temp->right;
			}
			root->data = temp->data;
			root->left = deleteInBST(root->left, root->data);
			return root;
		}
	}
	return root;
}


void printAllLevelsIterative(node * root) {
	if (root == NULL) {
		return;
	}

	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (temp == NULL) {
			if (q.size() == 0) {
				return;
			}
			cout << endl;
			q.push(NULL);
		}
		else {
			cout << temp->data << ", ";
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
	cout << endl;
}


bool isBST(node* root, int minimum, int maximum) {
	if (root == NULL) {
		return true;
	}

	if (root->data >= minimum and root->data < maximum and
	        isBST(root->left, minimum, root->data) and
	        isBST(root->right, root->data, maximum)) {
		return true;
	}
	return false;
}

void printInOrder(node * root) { //In-Order
	if (root == NULL) {
		return;
	}

	printInOrder(root->left);
	cout << root->data << ", ";
	printInOrder(root->right);

}

node* buildTree() { //pre-Order

	int d;
	cin >> d;

	//base case
	if (d == -1) {
		return NULL;
	}
	//self work
	node* root = new node(d);

	//recursive
	root->left = buildTree();
	root->right = buildTree();

	return root;
}


class nodeHelper {
public:
	bool isBST;
	int maximum;
	int minimum;
	int size;

	nodeHelper() {
		isBST = true;
		maximum = INT_MIN;
		minimum = INT_MAX;
		size = 0;
	}
};

nodeHelper largestBSTinBT(node* root) {
	if (root == NULL) {
		return nodeHelper();
	}

	nodeHelper leftSubtree = largestBSTinBT(root->left);
	nodeHelper rightSubtree = largestBSTinBT(root->right);
	nodeHelper current;

	if (leftSubtree.maximum <= root->data and rightSubtree.minimum > root->data and
	        leftSubtree.isBST and rightSubtree.isBST) {
		current.isBST = true;
		current.maximum = max(root->data, rightSubtree.maximum);
		current.minimum = min(root->data, leftSubtree.minimum);
		current.size = leftSubtree.size + rightSubtree.size + 1;
	}
	else {//when current is not a bst
		current.isBST = false;
		current.size = max(leftSubtree.size, rightSubtree.size);
	}
	return current;
}

int main(int argc, char const * argv[])
{
	// node* root = buildBST();
	// // printAllLevelsIterative(root);
	// cout << endl;
	// printInOrder(root);
	// cout << endl;
	// cout << search(root, 8) << endl;
	// cout << endl;
	// cout << search(root, 2) << endl;
	// cout << endl;
	// root = deleteInBST(root, 8);
	// printInOrder(root);
	// cout << endl;
	// root = deleteInBST(root, 10);
	// printInOrder(root);
	// cout << endl;
	// cout << isBST(root, INT_MIN, INT_MAX) << endl;
	node* root1 = buildTree();
	//cout << isBST(root1, INT_MIN, INT_MAX) << endl;
	nodeHelper sol = largestBSTinBT(root1);
	printAllLevelsIterative(root1);
	cout << endl;
	cout << "size " << sol.size << endl;




	return 0;
}
//1 2 4 -1 -1 5 -1 -1 3 -1 6 7 -1 -1 -1
//1 10 5 4 -1 -1 6 -1 -1 11 -1 12 -1 -1 19 17 -1 -1 23 22 21 -1 -1 -1 25 24 -1 -1 -1
