//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:

    int partition(vector<int>& arr, int start, int end) {
        int pivot = arr[end];

        int smallerElementIdx = start - 1; //smaller or equal tp pivot elements exists till this index
        int elementIdx = start;
        while (elementIdx < end) {
            if (arr[elementIdx] <= pivot) {
                smallerElementIdx++;
                swap(arr[smallerElementIdx], arr[elementIdx]);
            }
            elementIdx++;
        }
        smallerElementIdx++;
        swap(arr[end], arr[smallerElementIdx]); //placing pivot to it's correct position
        return smallerElementIdx;
    }

    int quickSort(vector<int>& arr, int start, int end, int k) {
        if (start >= end) {
            if (start == k) {
                return arr[start];
            }
            return -1;
        }

        int pivotIdx = partition(arr, start, end);
        if (pivotIdx == k) {
            return arr[k];
        }
        else if (pivotIdx < k) {
            return quickSort(arr, pivotIdx + 1, end, k); //right part
        }
        else {
            return quickSort(arr, start, pivotIdx - 1, k); //left part
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }

        return quickSort(nums, 0, n - 1, n - k);
    }
};




