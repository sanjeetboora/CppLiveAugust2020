/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

//weighted graph
class graph {
	unordered_map<int, list<pair<int, int> > >mp;
	//unordered_pair<vertex, list<pair<nbr, weight> > >mp;

public:

	void addEdge(int x, int y, int wt, bool bidirectional = true) {
		mp[x].push_back(make_pair(y, wt));

		if (bidirectional) {
			mp[y].push_back(make_pair(x, wt));
		}
	}

	void print() {
		for (auto pr : mp) {
			int vertex = pr.first;
			list <pair<int, int> >neighbours = pr.second;
			cout << vertex << " --> ";
			for (auto nbr : neighbours) {
				int nbr_vertex = nbr.first;
				int nbr_weight = nbr.second;
				cout << "{" << nbr_vertex << ", " << nbr_weight << "}, ";
			}
			cout << endl;
		}
	}

};


int main(int argc, char const *argv[])
{
	graph g;
	g.addEdge(0, 1, 10);
	g.addEdge(0, 3, 20, false);
	g.addEdge(1, 4, 30);
	g.addEdge(1, 5, 40);
	g.addEdge(4, 2, 50, false);
	g.print();

	return 0;
}

