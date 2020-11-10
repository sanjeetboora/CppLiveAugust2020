
/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* leftChild;
	node* rightChild;

	node(int d) {
		data = d;
		leftChild = NULL;
		rightChild = NULL;
	}
};

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
	root->leftChild = buildTree();
	root->rightChild = buildTree();

	return root;
}

void printTree(node* root) { //pre-Order
	if (root == NULL) {
		return;
	}
	cout << root->data << ", ";
	printTree(root->leftChild);
	printTree(root->rightChild);
}
void printPostOrder(node* root) { //post-Order
	if (root == NULL) {
		return;
	}

	printPostOrder(root->leftChild);
	printPostOrder(root->rightChild);
	cout << root->data << ", ";
}

void printInOrder(node* root) { //In-Order
	if (root == NULL) {
		return;
	}

	printInOrder(root->leftChild);
	cout << root->data << ", ";
	printInOrder(root->rightChild);

}

int height(node* root) {
	if (root == NULL) {
		return -1;
	}

	return 1 + max(height(root->leftChild), height(root->rightChild));

}
int nodesCount(node* root) {
	if (root == NULL) {
		return 0;
	}
	int totalNodes = 1 + nodesCount(root->leftChild) + nodesCount(root->rightChild);
	return totalNodes;
}
int sumAllNodes(node* root) {
	if (root == NULL) {
		return 0;
	}
	int totalSum = root->data + sumAllNodes(root->leftChild) + sumAllNodes(root->rightChild) ;
	return totalSum;
}


void printLevelK(node* root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data << ", ";
		return;
	}
	if (root->leftChild != NULL) {
		printLevelK(root->leftChild, k - 1);
	}
	if (root->rightChild != NULL) {
		printLevelK(root->rightChild, k - 1);
	}
}

void printAllLevels(node* root) {
	int levels = height(root);
	for (int i = 0; i <= levels; ++i)
	{
		printLevelK(root, i);
		cout << endl;
	}

}

void bfs(node* root) {
	if (root == NULL) {
		return;
	}

	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		cout << temp->data << ", ";
		if (temp->leftChild != NULL) {
			q.push(temp->leftChild);
		}
		if (temp->rightChild != NULL) {
			q.push(temp->rightChild);
		}
	}
	cout << endl;
}

void printAllLevelsIterative(node* root) {
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
			if (temp->leftChild != NULL) {
				q.push(temp->leftChild);
			}
			if (temp->rightChild != NULL) {
				q.push(temp->rightChild);
			}
		}
	}
	cout << endl;
}

void mirror(node* root) {
	if (root == NULL) {
		return;
	}
	swap(root->leftChild, root->rightChild);
	mirror(root->leftChild);
	mirror(root->rightChild);
}

int replaceWithDescendantsSum(node* root) {
	if (root == NULL) {
		return 0;
	}

	if (root->leftChild == NULL and root->rightChild == NULL) {
		return root->data;
	}

	int leftSum = replaceWithDescendantsSum(root->leftChild);
	int rightSum = replaceWithDescendantsSum(root->rightChild);

	int descendantsSum = leftSum + rightSum;
	int temp = root->data;

	root->data = descendantsSum;
	return root->data + temp;
}



void leftView(node* root) {
	if (root == NULL) {
		return;
	}

	queue<node*> q;
	q.push(root);
	q.push(NULL);
	cout << root->data << ", ";
	while (q.size() > 1) {
		node* temp = q.front();
		if (temp == NULL) {
			cout << endl;
			q.pop();
			cout << q.front()->data << ", ";
			q.push(NULL);
		}
		else {
			if (temp->leftChild != NULL) {
				q.push(temp->leftChild);
			}
			if (temp->rightChild != NULL) {
				q.push(temp->rightChild);
			}
			q.pop();
		}
	}
	cout << endl;
}


node* buildHeightBalancedTree(int* arr, int start, int end) {
	if (start > end) {
		return NULL;
	}
	int mid = start + (end - start) / 2;
	node* root = new node(arr[mid]);
	root->leftChild = buildHeightBalancedTree(arr, start, mid - 1);
	root->rightChild = buildHeightBalancedTree(arr, mid + 1, end);
	return root;
}
int i = 0;
node* buildTreeUsingPreorderInorder(int* preorder, int* inorder, int start, int end) {
	if (start > end) {
		return NULL;
	}
	node* root = new node(preorder[i]);

	int idx = -1;
	for (int k = start; k <= end; ++k)
	{
		if (inorder[k] == preorder[i]) {
			idx = k;
			break;
		}
	}
	i++;
	root->leftChild = buildTreeUsingPreorderInorder(preorder, inorder, start, idx - 1);
	root->rightChild = buildTreeUsingPreorderInorder(preorder, inorder, idx + 1, end);
	return root;
}



int main(int argc, char const *argv[])
{
	//node* root = buildTree();
	// printTree(root);
	// cout << endl;
	// printPostOrder(root);
	// cout << endl;
	// printInOrder(root);
	// cout << endl;

	// cout << height(root) << endl;
	// cout << nodesCount(root) << endl;
	// cout << sumAllNodes(root) << endl;
	// printLevelK(root, 2);
	// cout << endl;
	// printAllLevels(root);
	// bfs(root);
	// printAllLevelsIterative(root);
	// cout << endl;
	// mirror(root);
	//replaceWithDescendantsSum(root);
	//printAllLevelsIterative(root);
	// leftView(root);
	// cout << endl;

	// int arr[10] = {1, 2, 3 , 4, 5, 6, 7 , 8};
	// node* root1 = buildHeightBalancedTree(arr, 0, 7);
	// printAllLevelsIterative(root1);
	int pre[10] = {1, 2, 3 , 4, 5, 6};
	int in[10] = { 3 , 2, 4, 1, 5, 6};
	node* root2 = buildTreeUsingPreorderInorder(pre, in, 0, 5);

	printAllLevelsIterative(root2);

	cout << endl;

	return 0;
}
// 1 2 4 NULL NULL 5 NULL NULL 3 NULL 6 7 NULL NULL NULL
// 1 2 4 -1 -1 5 -1 -1 3 -1 6 7 -1 -1 -1


