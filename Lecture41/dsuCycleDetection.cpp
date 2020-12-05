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
	int ver = 4;
	graph g(ver);
	vector<pair<int, int> >edgeList;
	edgeList.push_back(make_pair(0, 1));
	edgeList.push_back(make_pair(1, 2));
	edgeList.push_back(make_pair(0, 3));
	// edgeList.push_back(make_pair(1, 3));

	bool cycle = false;
	for (int i = 0; i < edgeList.size(); ++i)
	{
		int x = edgeList[i].first;
		int y = edgeList[i].second;

		if (g.superparent(x) != g.superparent(y)) {
			g.unite(x, y);
		}
		else {
			cycle = true;
			cout << "cycle detected b/w " << x << " and " << y << endl;
			break;
		}
	}
	return 0;
}




