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

	bool dfsHelper(int src, unordered_map<int, bool> &visited, vector<bool> &path) {
		visited[src] = true;
		path[src] = true;
		cout << src << ", ";
		for (int nbr : mp[src])
		{
			if (path[nbr] == true) {
				return true; // cycle detected;
			}

			if (visited.count(nbr) == 0) {
				if (dfsHelper(nbr, visited, path)) {
					return true; //cycle exists
				}
			}
		}
		path[src] = false;
		return false;
	}

	void dfs(int src) {
		unordered_map<int, bool> visited;
		vector<bool> path;
		path.reserve(100);
		for (int i = 0; i <= 10; ++i)
		{
			path[i] = false;
		}
		if (dfsHelper(src, visited, path)) {
			cout << "cycle exists" << endl;
		}
		else {
			cout << "cycle doesn't exist" << endl;
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
	// g.addEdge(0, 1, false);
	// g.addEdge(0, 3, false);
	// g.addEdge(1, 4, false);
	// g.addEdge(1, 5, false);
	// g.addEdge(4, 2, false);
	g.addEdge(0, 1, false);
	g.addEdge(1, 2, false);
	g.addEdge(2, 3, false);
	g.addEdge(3, 0, false);
	g.addEdge(3, 4, false);
	g.addEdge(4, 5, false);
	g.print();
	g.dfs(0);
	return 0;
}




