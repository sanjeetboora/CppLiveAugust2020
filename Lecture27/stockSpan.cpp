//https://leetcode.com/problems/online-stock-span/
// 1 2 3 4 5 6
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// 1 2 3 4 5 6
// N*N
class StockSpanner {
public:
	stack<pair<int, int> > st; //price, distance
	StockSpanner() {

	}

	int next(int price) {
		int dis = 1;
		while (!st.empty() and st.top().first <= price) {
			dis += st.top().second;
			st.pop();
		}
		// st.push({price, dis});
		pair<int, int> p = make_pair(price, dis);
		st.push(p);
		return st.top().second;
		//return dis;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */