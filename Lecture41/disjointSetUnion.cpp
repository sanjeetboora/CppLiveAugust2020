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
	int ver = 7;
	graph g(ver);

	g.unite(0, 1);
	g.unite(0, 2);
	g.unite(0, 3);
	g.unite(0, 4);
	g.unite(0, 5);
	g.unite(0, 6);
	return 0;
}




