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

	bool dfsHelper(int src, unordered_map<int, bool> &visited, int parent) {
		visited[src] = true;
		cout << src << ", ";
		for (int nbr : mp[src])
		{
			if (visited.count(nbr) == 0) { //nbr is not visited
				if (dfsHelper(nbr, visited, src)) {
					return true;
				}
			}
			//nbr is already visited but it's not your parent
			else if (nbr != parent) { //cycle detected
				return true;
			}
		}
		return false;
	}

	void dfs(int src) {
		unordered_map<int, bool> visited;

		if (dfsHelper(src, visited, -1)) {
			cout << "cycle exists" << endl;
		}
		else {
			cout << "cycle doesn't exists" << endl;
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
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.print();
	g.dfs(0);
	return 0;
}




