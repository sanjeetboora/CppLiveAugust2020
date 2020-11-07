/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* right;
	node* down;

	node(int d) {
		data = d;
		right = NULL;
		down = NULL;
	}
};

void insertDown(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node* temp = head;
	while (temp->down != NULL) {
		temp = temp->down;
	}
	temp->down = new node(data);
	return;

}

node* merge(node* a, node* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}

	node* c;
	if (a->data <= b->data) {
		c = a;
		c->down = merge(a->down, b);
	}
	else {
		c = b;
		c->down = merge(a, b->down);
	}
	return c;
}

node* flattenALinkedList(node* head) {
	if (head == NULL or head->right == NULL) {
		return head;
	}

	node* c = merge(head, flattenALinkedList(head->right));
	return c;
}

void printList(node* head) {
	while (head != NULL) {
		cout << head->data << ", ";
		head = head->down;
	}
	cout << endl;
}


int main(int argc, char const *argv[])
{
	node* head = NULL;

	insertDown(head, 3);
	insertDown(head, 10);
	insertDown(head, 20);
	insertDown(head->right, 2);
	insertDown(head->right, 8);
	insertDown(head->right, 12);
	insertDown(head->right->right, 1);
	insertDown(head->right->right, 11);
	insertDown(head->right->right, 15);
	insertDown(head->right->right, 19);

	head = flattenALinkedList(head);
	printList(head);
	return 0;
}









