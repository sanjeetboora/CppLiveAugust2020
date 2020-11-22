/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;
//unweighted graph
//adjList
template<typename T>
class graph {
	int V;
	unordered_map<T, list<T> >mp;
	//unordered_map<vertex, list<neighbours> >mp;
public:

	void addEdge(T x, T y, bool bidirectional = false) {
		mp[x].push_back(y);

		if (bidirectional) {
			mp[y].push_back(x);
		}
	}

	void topologicalSortBfs() {
		unordered_map<T, int>indegree;
		for (auto vertex : mp)
		{
			indegree[vertex.first] = 0;
		}
		//store indegree of all vertices;
		for (auto vertex : mp)
		{
			T currentVtx = vertex.first;
			list<T> neighbours = vertex.second;
			for (T nbr : neighbours) {
				indegree[nbr]++;
			}
		}

		list<T> ans;
		queue<T>q;
		for (auto v : indegree) {
			if (indegree[v.first] == 0) {
				q.push(v.first);
			}
		}

		while (!q.empty()) {
			T frontNode = q.front();
			q.pop();
			ans.push_back(frontNode);
			for (T nbr : mp[frontNode]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

		for (T x : ans) {
			cout << x << ", ";
		} cout << endl;

	}

	void print() {
		for (auto pr : mp) {
			T vertex = pr.first;
			list <T>neighbours = pr.second;
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
	graph<string> g;
	g.addEdge("10", "Diploma");
	g.addEdge("10", "11");
	g.addEdge("Diploma", "BTech");
	g.addEdge("11", "12");
	g.addEdge("12", "DU");
	g.addEdge("12", "NDA");
	g.addEdge("12", "drop");
	g.addEdge("drop", "JEE");
	g.addEdge("12", "JEE");
	g.addEdge("JEE", "BE");
	g.addEdge("JEE", "BTech");
	g.addEdge("Intelligent", "BTech");
	g.print();
	g.topologicalSortBfs();

	return 0;
}




