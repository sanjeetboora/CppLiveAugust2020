//https://leetcode.com/problems/min-stack/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        //to push in minStack
        if (minSt.empty()) {
            minSt.push(x);
        }
        else {
            if (x <= minSt.top()) {
                minSt.push(x);
            }
        }
    }

    void pop() {
        int tobePopped = st.top();
        if (tobePopped == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */