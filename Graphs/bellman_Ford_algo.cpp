#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>
using namespace std;

template <typename my>
class Graph {
public:
    unordered_map<my, list<pair<my, int>>> adjList;

    void addEdge(my u, my v, int wt, bool direction) {
        adjList[u].push_back(make_pair(v, wt));
        if (direction == 1) {
            adjList[v].push_back(make_pair(u, wt));
        }
        cout << "Printing the graph: " << endl;
        printAdjList();
        cout << endl;
    }

    void printAdjList() {
        for (auto& i : adjList) {
            cout << i.first << " -> { ";
            for (auto& p : i.second) {
                cout << "{" << p.first << ", " << p.second << "} ";
            }
            cout << "}" << endl;
        }
    }

    void bellmanFordAlgo(my src) {
        unordered_map<my, int> dist;

        for (auto& node : adjList) {
            dist[node.first] = INT_MAX;
        }

        dist[src] = 0;

        int n = adjList.size();
        for (int i = 1; i < n; i++) {
            for (auto& it : adjList) {
                my u = it.first;
                for (auto& nbr : it.second) {
                    my v = nbr.first;
                    int wt = nbr.second;
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        bool anyUpdate = false;
        for (auto& it : adjList) {
            my u = it.first;
            for (auto& nbr : it.second) {
                my v = nbr.first;
                int wt = nbr.second;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    anyUpdate = true;
                    break;
                }
            }
            if (anyUpdate) break;
        }

        if (anyUpdate) {
            cout << "Negative cycle present" << endl;
        } else {
            cout << "Shortest distances from source " << src << ":" << endl;
            for (auto& d : dist) {
                cout << d.first << " : " << d.second << endl;
            }
        }
    }
};

int main() {
    Graph<char> g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('B', 'E', 2, 1);
    g.addEdge('E', 'D', -3, 1);
    g.addEdge('D', 'C', 5, 1);
    g.addEdge('A', 'C', 4, 1);
    g.addEdge('B', 'C', 3, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('D', 'B', 1, 1);
    g.printAdjList();
    g.bellmanFordAlgo('B');

    return 0;
}