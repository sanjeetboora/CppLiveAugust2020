/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;
//unweighted graph
//adjList
class graph {
	int V;
	list<int>* arr;
public:
	graph(int ver) {
		V = ver;
		arr = new list<int>[V];
	}

	void addEdge(int x, int y, bool bidirectional = true) {
		arr[x].push_back(y);

		if (bidirectional) {
			arr[y].push_back(x);
		}
	}

	void print() {
		for (int i = 0; i < V; ++i)
		{
			cout << i << "--->";
			for (int nbr : arr[i]) {
				cout << nbr << ", ";
			} cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 3, false);
	g.addEdge(1, 4);
	g.addEdge(1, 5);
	g.addEdge(4, 2, false);
	g.print();
	return 0;
}




