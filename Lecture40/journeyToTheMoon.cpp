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

	void dfsHelper(int src, unordered_map<int, bool> &visited, int& vertexCount) {
		visited[src] = true;
		vertexCount++;
		cout << src << ", ";
		for (int nbr : mp[src])
		{
			if (!visited[nbr]) {
				dfsHelper(nbr, visited, vertexCount);
			}
		}
	}

	int pairsFromDifferentCountries(int n) {
		unordered_map<int, bool> visited;

		for (auto vertex : mp) {
			visited[vertex.first] = false;
		}
		int countries = 0;
		int totalPossiblePairs = (n * (n - 1)) / 2;
		int pairsFromSameCountry = 0;

		for (auto vertex : mp) {
			int astronauts = 0;
			if (!visited[vertex.first]) {
				// cout << "component -- " << components << endl;
				dfsHelper(vertex.first, visited, astronauts);
				pairsFromSameCountry = (astronauts * (astronauts - 1)) / 2;
				totalPossiblePairs -= pairsFromSameCountry;
				countries++;
			}
		}
		cout << "countries : " << countries << endl;
		return totalPossiblePairs;
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
	int n = 7;
	g.addEdge(0, 1);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);

	g.print();
	cout << g.pairsFromDifferentCountries(n) << endl;
	return 0;
}




