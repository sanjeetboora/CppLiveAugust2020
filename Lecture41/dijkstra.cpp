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

	void dijkstra(int src) {
		set<pair<int, int> >pathSet;//set<pair<weight of path till node_x, node_x> >pathSet;
		unordered_map<int, int> distance;

		for (auto x : mp) {
			distance[x.first] = INT_MAX;
		}
		distance[src] = 0;
		pathSet.insert(make_pair(distance[src], src));

		while (!pathSet.empty()) {
			auto minDistanceNode = *(pathSet.begin());
			int node = minDistanceNode.second;
			int nodeDistance = minDistanceNode.first;
			pathSet.erase(pathSet.begin());

			for (auto nbr : mp[node]) {
				if ((nbr.second + nodeDistance) < distance[nbr.first]) { //better result
					auto findInSet = pathSet.find(make_pair(distance[nbr.first], nbr.first));
					//if node exists in pathset
					if (findInSet != pathSet.end()) {
						pathSet.erase(findInSet); //delete nbr from set
					}
					distance[nbr.first] = nbr.second + nodeDistance;
					pathSet.insert(make_pair(distance[nbr.first], nbr.first));
				}
			}
		}
		for (auto x : distance) {
			cout << x.first << " " << x.second << endl;
		}

	}

};


int main(int argc, char const *argv[])
{
	graph g;
	g.addEdge(0, 1, 1, false);
	g.addEdge(0, 2, 4, false);
	g.addEdge(1, 3, 3, false);
	g.addEdge(1, 2, 1, false);
	g.addEdge(1, 4, 2, false);
	g.addEdge(2, 4, 0, false);
	g.addEdge(3, 4, 3, false);
	g.addEdge(5, 3, 2, false);
	g.addEdge(4, 5, 1, false);
	g.print();
	g.dijkstra(0);

	return 0;
}

