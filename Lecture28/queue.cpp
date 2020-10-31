/* Problem -  */
/* By Sanjeet Boora */
#include<iostream>
using namespace std;

class queue
{
	int* arr;
	int front;
	int rear;
	int currSize;
	int totalSize;
public:
	queue(int defaultSize = 5) {
		totalSize = defaultSize;
		arr = new int[totalSize];
		currSize = 0;
		front = 0;
		//rear = totalSize - 1;
		rear = -1;
	}
	// rear = -1;
	// 	rear = (-1+1)%5;
	// 	rear =0;
	// 	rear = totalSize-1;
	// 	rear = (4 + 1)%5;
	// 	rear =0;

	bool isEmpty() {
		return currSize == 0;
	}

	bool isFull() {
		return currSize == totalSize;
	}

	void push(int x) {
		if (isFull()) {
			cout << "Queue is already full" << endl;
			return;
		}

		rear = (rear + 1) % totalSize;
		arr[rear] = x;
		currSize++;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			return;
		}
		front = (front + 1) % totalSize;
		currSize--;
	}
	int getFront() {
		if (isEmpty()) {
			cout << "queue is empty" << endl;
			return INT_MIN;
		}
		return arr[front];
	}

};

int main(int argc, char const *argv[])
{
	queue q(4);
	cout << q.getFront() << endl;
	q.push(1);
	cout << q.getFront() << endl;
	q.push(2);
	cout << q.getFront() << endl;
	q.pop();
	cout << q.getFront() << endl;
	q.push(3);
	cout << q.getFront() << endl;
	q.pop();
	cout << q.getFront() << endl;
	q.push(4);
	cout << q.getFront() << endl;
	q.push(5);
	cout << q.getFront() << endl;
	q.pop();
	cout << q.getFront() << endl;
	q.push(6);
	cout << q.getFront() << endl;
	q.pop();
	cout << q.getFront() << endl;
	q.pop();
	cout << q.getFront() << endl;
	q.pop();
	cout << q.getFront() << endl;

	return 0;
}











