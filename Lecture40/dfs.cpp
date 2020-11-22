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

	void dfsHelper(int src, unordered_map<int, bool> &visited) {
		visited[src] = true;
		cout << src << ", ";
		for (int nbr : mp[src])
		{
			if (!visited[nbr]) {
				dfsHelper(nbr, visited);
			}
		}
	}

	void dfs(int src) {
		unordered_map<int, bool> visited;

		for (auto vertex : mp) {
			visited[vertex.first] = false;
		}
		dfsHelper(src, visited);
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
	g.dfs(0);
	return 0;
}




