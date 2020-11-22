/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;
//unweighted graph
//adjList
class graph {
	int V;
	unordered_map<int, list<int> >mp;
	//unordered_map<vertex, list<neighbours> >mp;
public:

	void addEdge(int x, int y, bool bidirectional = true) {
		mp[x].push_back(y);

		if (bidirectional) {
			mp[y].push_back(x);
		}
	}


	void sssp(int src) {
		queue<int> q;
		unordered_map<int, int> distance;

		q.push(src);
		distance[src] = 0;
		while (!q.empty()) {
			int frontNode = q.front();
			q.pop();
			cout << frontNode << ", ";
			for (int nbr : mp[frontNode]) {
				if (distance.count(nbr) == 0) {
					q.push(nbr);
					distance[nbr] = distance[frontNode] + 1;
				}
			}
		}
		cout << endl;
		for (auto x : distance)
		{
			cout << x.first << ", " << x.second << endl;
		}
	}


	void print() {
		for (auto pr : mp) {
			int vertex = pr.first;
			list <int>neighbours = pr.second;
			cout << vertex << " --> ";
			for (auto nbr : neighbours) {
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 3, false);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(4, 2, false);
	g.print();
	g.sssp(0);
	return 0;
}




