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

Node* reverseRecursive(Node* head) {
	//base case
	if (head == NULL or head->next == NULL) {
		return head;
	}
	Node* newHead = reverseRecursive(head->next);
	Node* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

void KthNodeFromLast(Node* head, int K) {
	Node* slow = head;
	Node* fast = head;

	int count = 0;
	while (count < K) {
		if (fast == NULL) {
			cout << K << " is greater than length of the LL " << endl;
			return;
		}
		fast = fast->next;
		count++;
	}

	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	cout << slow->data << " is the last Kth Node" << endl;
}

Node* mid(Node* head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	Node* slow = head;
	Node* fast = head->next;
	while (fast != NULL and fast-> next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;

}
//merge two sorted LL
Node* merge(Node* a, Node* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}

	Node* c;
	if (a->data <= b->data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}

Node* mergeIterative(Node* a, Node* b) {
	Node* c = new Node(0);
	Node* newHead = NULL;
	while (a != NULL and b != NULL) {
		if (a->data <= b->data) {
			if (newHead == NULL) {
				newHead = a;
			}
			c->next = a;
			c = c->next;
			a = a->next;
		}
		else {
			if (newHead == NULL) {
				newHead = b;
			}
			c->next = b;
			c = c->next;
			b = b->next;
		}
	}
	if (a != NULL) {
		c->next = a;

	}
	if (b != NULL) {
		c->next = b;
	}
	return newHead;
}

// a = 1 4 2  b= 3 5 NULL
// midNode =2
// 1 4 2 NULL 3 5 NULL
Node* mergeSort(Node* head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}
	Node* midNode = mid(head);
	Node* a = head; //left half of LL
	Node* b = midNode->next; //right half of LL
	midNode->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);
	Node* c = merge(a, b);

	return c;
}
//NlogN
// log N * (N ->merge + N -> mid)
// logN *(2N)
// 2NlogN


bool loopDetect(Node* head) {
	Node* fast = head;
	Node* slow = head;

	while (slow != NULL and fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;

}
void removeLoop(Node* head, Node* meetPoint) {
	Node* a = head;
	Node* b = meetPoint;

	while (a->next != b->next) {
		a = a->next;
		b = b->next;
	}
	b->next = NULL;
}
void detectAndRemoveCycle(Node* head) {
	Node* fast = head;
	Node* slow = head;

	while (slow != NULL and fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			removeLoop(head, slow);
			return;
		}
	}
}



int main(int argc, char const *argv[])
{
	// Node* head = NULL;
	// insertAtTail(head, 1);
	// insertAtTail(head, 5);
	// insertAtTail(head, 7);
	// print(head);
	// // head = reverseRecursive(head);
	// // print(head);
	// // KthNodeFromLast(head, 2);
	// // Node* midNode = mid(head);
	// // cout << "mid node is " << midNode->data << endl;
	// Node* head1 = NULL;
	// insertAtTail(head1, 2);
	// insertAtTail(head1, 3);
	// insertAtTail(head1, 6);
	// insertAtTail(head1, 10);
	// print(head1);
	// // head1 = merge(head1, head);
	// head1 = mergeIterative(head1, head);
	// print(head1);
	Node* head = NULL;
	insertAtTail(head, 11);
	insertAtTail(head, 15);
	insertAtTail(head, 7);
	insertAtTail(head, 1);
	insertAtTail(head, -1);
	head->next->next->next->next = head->next;
	//11-> 15 -> 7 ->  1 -> 15
	// print(head);
	// head = mergeSort(head);
	// print(head);

	if (loopDetect(head)) {
		cout << "loop/cycle detected" << endl;
	}
	else {
		cout << "loop/cycle not detected" << endl;
	}

	detectAndRemoveCycle(head);
	print(head);

	return 0;
}


//HW - Flatten a linked list

