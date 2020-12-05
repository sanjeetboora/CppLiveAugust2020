/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class graph {
	int V;
	int connectedComponents;
	vector<int> parent;
public:
	graph(int ver) {
		V = ver;
		connectedComponents = V;
		parent.reserve(V);
		for (int i = 0; i < V; ++i)
		{
			parent[i] = i;
		}
	}
	int superparent(int x) {
		if (parent[x] == x) {
			return x;
		}
		else {
			int superparentX = superparent(parent[x]);
			parent[x] = superparentX;
			return superparentX;
		}
	}

	void unite(int x, int y) {
		int parX = superparent(x);
		int parY = superparent(y);

		if (parX != parY) {
			parent[parX] = parY;
			connectedComponents--;
			cout << connectedComponents << endl;
			for (int i = 0; i < V; ++i)
			{
				cout << parent[i] << ", ";
			} cout << endl;
		}

	}

};


int main(int argc, char const *argv[])
{
	int ver = 6;
	graph g(ver);
	int numEdges = 8;
	vector<vector<int> >edgeList;
	edgeList.reserve(numEdges);

	vector<int> edge(3); //{wt, vertex1, vertex2}

	edge = {1, 1, 2};
	edgeList.push_back(edge);
	edge = {4, 1, 3};
	edgeList.push_back(edge);
	edge = {4, 3, 4};
	edgeList.push_back(edge);
	edge = {2, 2, 4};
	edgeList.push_back(edge);
	edge = {3, 1, 4};
	edgeList.push_back(edge);
	edge = {4, 5, 4};
	edgeList.push_back(edge);
	edge = {5, 6, 5};
	edgeList.push_back(edge);
	edge = {7, 4, 6};
	edgeList.push_back(edge);

	sort(edgeList.begin(), edgeList.end());
	int totalWt = 0;

	for (int i = 0; i < numEdges; ++i)
	{
		int wt = edgeList[i][0];
		int x = edgeList[i][1];
		int y = edgeList[i][2];

		if (g.superparent(x) != g.superparent(y)) {
			g.unite(x, y);
			totalWt += wt;
		}
	}
	cout << totalWt << endl;
	return 0;
}




