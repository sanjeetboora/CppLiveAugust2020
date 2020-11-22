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

	int connectedComponents() {
		unordered_map<int, bool> visited;

		for (auto vertex : mp) {
			visited[vertex.first] = false;
		}
		int components = 0;

		for (auto vertex : mp) {
			if (!visited[vertex.first]) {
				cout << "component -- " << components << endl;
				dfsHelper(vertex.first, visited);
				components++;
				cout << endl;
			}
		}
		return components;
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
	g.addEdge(0, 2);

	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(7, 3);

	g.addEdge(8, 9);

	g.print();
	cout << g.connectedComponents() << endl;
	return 0;
}




