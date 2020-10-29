//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        if (height.size() == 0) return 0;

        int water = 0;
        int idx = 0;
        while (idx < height.size()) {
            while (!st.empty() and height[st.top()] < height[idx]) {
                int tIdx = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int right = idx, left = st.top();
                int dis = right - left - 1;
                int minHeight = min(height[left], height[right]);
                water += dis * (minHeight - height[tIdx]);
            }
            st.push(idx);
            idx++;
        }
        return water;
    }
};