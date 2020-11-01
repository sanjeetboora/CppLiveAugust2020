/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

//class Node
class Node {
public:
	int data;
	Node* next;

	Node(int d) {
		data = d;
		next = NULL;
	}
};

int length(Node* head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

// 5 -> 2 -> 3 -> 4 -> NULL
void insertAtHead(Node* &head, int d) { //pass by ref
	if (head == NULL) {
		head = new Node(d);
		return;
	}

	Node* temp = new Node(d);
	temp ->next = head;
	head = temp;
}

void insertAtTail(Node* &head, int d) {
	if (head == NULL) {
		head = new Node(d);
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) { // to find last node
		temp = temp->next;
	}
	temp -> next = new Node(d);
}

void insertAtKPosition(Node* &head, int k, int d) {
	if (head == NULL or k == 0) {
		insertAtHead(head, d);
		return;
	}
	else if (k >= length(head)) {
		insertAtTail(head, d);
		return;
	}
	else {
		int pos = 0;
		Node* temp = head;
		while (pos < k - 1) {
			temp = temp->next;
			pos++;
		}
		Node* x = new Node(d);
		x->next = temp->next;
		temp -> next = x;
		return;
	}
}

void deleteAtHead(Node* &head) {
	if (head == NULL) {
		return;
	}
	Node* toBeDeleted = head;
	head = head->next;
	delete toBeDeleted;
}

void deleteAtTail(Node* &head) {
	if (head == NULL or head->next == NULL) {
		deleteAtHead(head);
		return;
	}
	Node* temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}

void deleteAtKPosition(Node* &head, int k) {
	if (k == 0 or head == NULL or head->next == NULL) {
		deleteAtHead(head);
		return;
	}
	else if ( k >= length(head) - 1) {
		deleteAtTail(head);
		return;
	}
	else {
		int pos = 0;
		Node* temp = head;
		while (pos < k - 1) {
			temp = temp->next;
			pos++;
		}
		Node* toBeDeleted = temp->next;
		temp->next = temp->next->next;
		delete toBeDeleted;
		return;
	}

}

// 5 -> 2 -> 3 -> 4 -> NULL
void print(Node* head) { //pass by value
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << endl;
}

//1 2 3 4 5 -1
void buildList(Node* &head) {
	int d;
	cin >> d;
	while (d != -1) {
		insertAtTail(head, d);
		cin >> d;
	}
}

//iteratively search for an element x
bool searchIterative(int x, Node* head) { //pass by value
	if (head == NULL) {
		return false;
	}
	while (head != NULL) {
		if (head -> data == x) {
			return true;
		}
		head = head->next;
	}
	return false;
}
//recursively search for an element x
bool searchRecursive(int x, Node* head) {//pass by value
	//base case
	if (head == NULL) {
		return false;
	}

	//self work
	if (head->data == x) {
		return true;
	}
	else {
		return searchRecursive(x, head->next); //recursive call
	}

}

void reverseIterative(Node* &head) {
	if (head == NULL or head->next == NULL) {
		return;
	}

	Node* prev = NULL;
	Node* curr = head;
	Node* nxt = curr->next;
	while (nxt != NULL) {
		curr -> next = prev;
		prev = curr;
		curr = nxt;
		nxt = curr->next;
	}
	curr -> next = prev;
	prev = curr;
	curr = nxt;

	head = prev;
}


int main(int argc, char const *argv[])
{
	// Node* x = new Node(10);
	// cout << x->data << endl;

	// Node X;
	// X.data = 7;

	Node* head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	print(head);
	insertAtKPosition(head, 0, 0);
	print(head);
	insertAtKPosition(head, 2, -2);
	print(head);
	insertAtKPosition(head, 6, 6);
	print(head);
	// deleteAtHead(head);
	// print(head);
	// deleteAtTail(head);
	// print(head);
	// cout << length(head) << endl;
	// deleteAtKPosition(head, 2);
	// print(head);
	// // cout << searchIterative(-2, head) << endl;
	// // cout << searchIterative(-1, head) << endl;
	// cout << searchRecursive(-2, head) << endl;
	// cout << searchRecursive(-1, head) << endl;
	reverseIterative(head);
	print(head);

	return 0;
}

// write reverse a linked list recursively
// find kth node //1 2 3 4 5,  k= 2, ans = 2
// find last kth node //1 2 3 4 5,  k= 2, ans = 4
// find mid element // 1 2 3, ans = 2 //1 2 3 4, ans = 2

