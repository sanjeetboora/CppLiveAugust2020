/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;
//MAX Heap

void upheapify(vector<int>& heap, int index) {
	if (index == 0) {
		return;
	}

	int parentIdx = (index - 1) / 2;
	if (heap[index] > heap[parentIdx]) {
		swap(heap[index], heap[parentIdx]);
		upheapify(heap, parentIdx);
	}
	else {
		return;
	}

}

void insert(vector<int>& heap, int num) {
	heap.push_back(num);
	upheapify(heap, heap.size() - 1);
}

void printHeap(vector<int> heap) {
	for (int x : heap) {
		cout << x << ", ";
	}
	cout << endl;
}


void downheapify(vector<int>& heap, int idx) {
	int leftchildIdx = (2 * idx) + 1;
	int rightchildIdx = (2 * idx) + 2;

	if (leftchildIdx >= heap.size() and rightchildIdx >= heap.size()) { //leaf node
		return;
	}

	int largerChildIdx = idx;
	if (leftchildIdx < heap.size() and heap[leftchildIdx] > heap[idx]) {
		largerChildIdx = leftchildIdx;
	}
	if (rightchildIdx < heap.size() and heap[rightchildIdx] > heap[largerChildIdx]) {
		largerChildIdx = rightchildIdx;
	}

	if (largerChildIdx == idx) {
		return;
	}
	swap(heap[idx], heap[largerChildIdx]);
	downheapify(heap, largerChildIdx);
}

void deleteRoot(vector<int>& heap) {
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();

	downheapify(heap, 0);
}

void deleteNode(vector<int>& heap, int idx) {
	heap[idx] = INT_MAX;
	upheapify(heap, idx);

	deleteRoot(heap);
}

int top(vector<int> heap) {
	if (heap.size() == 0) {
		cout << "heap is empty" << endl;
		return 0;
	}
	return heap[0];
}


int main(int argc, char const *argv[])
{
	vector<int> heap;

	insert(heap, 10);
	insert(heap, 5);
	insert(heap, 20);
	insert(heap, 100);
	insert(heap, 15);
	printHeap(heap);
	deleteNode(heap, 1);
	printHeap(heap);
	cout << top(heap) << endl;

	return 0;
}

