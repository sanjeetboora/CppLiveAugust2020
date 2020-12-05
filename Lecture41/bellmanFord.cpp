/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

//weighted graph
class graph {
	int V;
	int E;
	vector<vector<int> >edgeList;

public:
	graph(int ver, int edge) {
		V = ver;
		E = edge;
		edgeList.reserve(E);
	}

	void addEdges(int x, int y, int wt) {
		vector<int> edge(3);
		edge = {x, y, wt};
		edgeList.push_back(edge);
	}

	void bellmanford(int src) {
		vector<int> distance(V);

		for (int i = 0; i < V; ++i)
		{
			distance[i] = INT_MAX;
		}
		distance[src] = 0;


		for (int i = 1; i <= V - 1; ++i)
		{
			for (int e = 0; e < E; e++) {
				int src = edgeList[e][0];
				int dest = edgeList[e][1];
				int wt = edgeList[e][2];
				if (distance[src] != INT_MAX and distance[src] + wt < distance[dest]) {
					distance[dest] =  distance[src] + wt;
				}
			}
		}

		// to detect -ve cycle
		for (int e = 0; e < E; e++) {
			int src = edgeList[e][0];
			int dest = edgeList[e][1];
			int wt = edgeList[e][2];
			if (distance[src] != INT_MAX and distance[src] + wt < distance[dest]) {
				cout << "negative cycle detected from " << src << " to " << dest << endl;
				return;
			}
		}
		for (int i = 0; i < V; ++i)
		{
			cout << i << " --> " << distance[i] << endl;
		}

	}

};




int main(int argc, char const *argv[])
{
	int vertex = 4;
	int edges = 5;
	graph g(vertex, edges);

	// g.addEdges(0, 1, 5);
	g.addEdges(1, 0, -5);
	g.addEdges(0, 2, 3);
	g.addEdges(2, 1, -2);
	g.addEdges(1, 3, 2);
	g.addEdges(2, 3, 1);

	g.bellmanford(0);
	return 0;
}





