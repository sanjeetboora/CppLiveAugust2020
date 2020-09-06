//https://leetcode.com/problems/trapping-rain-water/


#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{

	int n = 12;
	int height[15] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	int leftMax[15];

	leftMax[0] = height[0];
	for (int i = 1; i < n; ++i)
	{
		int maximum = max(leftMax[i - 1], height[i]);
		leftMax[i] = maximum;
	}
	// for (int i = 0; i < n; ++i)
	// {

	// 	cout << leftMax[i] << ", ";
	// }
	// cout << endl;
	//rightmax
	int rightmax = height[n - 1];
	int totalStoredWater = 0;
	for (int i = n - 1; i >= 0; i--) {

		rightmax = max(rightmax, height[i]);
		//cout << rightmax << ", ";

		//stored water
		int currWater = min(leftMax[i], rightmax) - height[i];
		totalStoredWater += currWater;
	}

	cout << totalStoredWater << endl;



	return 0;
}




//leetcode solution
// class Solution {
// public:
// 	int trap(vector<int>& height) {
// 		vector<int> leftMax;
// 		int n = height.size();

// 		if (n == 0) {
// 			return 0;
// 		}


// 		leftMax.push_back(height[0]); //	leftMax[0] = height[0];

// 		for (int i = 1; i < n; ++i)
// 		{
// 			int maximum = max(leftMax[i - 1], height[i]);
// 			leftMax.push_back(maximum); //leftMax[i] = maximum;

// 		}

// 		//rightmax
// 		int rightmax = height[n - 1];
// 		int totalStoredWater = 0;
// 		for (int i = n - 1; i >= 0; i--) {

// 			rightmax = max(rightmax, height[i]);


// 			//stored water
// 			int currWater = min(leftMax[i], rightmax) - height[i];
// 			totalStoredWater += currWater;
// 		}

// 		return totalStoredWater;
// 	}
// };





