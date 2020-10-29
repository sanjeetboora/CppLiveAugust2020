/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;


int maxArea(int* arr, int n) {

	stack<int> st;

	int i = 0;
	int maxarea = 0;
	while (i < n) {
		if (st.empty() or arr[i] >= arr[st.top()]) {
			st.push(i);
			i++;
		}
		else {
			int tIdx = st.top();
			st.pop();
			int right = i;
			int left = st.empty() ? -1 : st.top();
			int area = arr[tIdx] * (right - left - 1);
			//int area = arr[tIdx] * (st.empty() ? i : (right - st.top() - 1));
			if (area > maxarea) {
				maxarea = area;
			}
		}
	}

	while (!st.empty()) {
		int tIdx = st.top();
		st.pop();
		int right = i;
		int left = st.empty() ? -1 : st.top();
		int area = arr[tIdx] * (right - left - 1);
		//int area = arr[tIdx] * (st.empty() ? i : (right - st.top() - 1));
		if (area > maxarea) {
			maxarea = area;
		}
	}
	return maxarea;
}

int main(int argc, char const *argv[])
{
	int arr[10] = {6, 2, 5, 4, 5, 1, 25};
	int n = 7;

	int maxRectangularArea = maxArea(arr, n);
	cout << maxRectangularArea << endl;

	return 0;
}

