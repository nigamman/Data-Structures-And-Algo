#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;

template <typename temp>
class Graph {
public:
    unordered_map<temp, list<pair<temp, int>>> adjList;

    void addEdge(temp u, temp v, int wt, bool direction) {
        // direction -> 0 = undirected
        // direction -> 1 = directed
        if(direction == 1) {
            adjList[u].push_back(make_pair(v, wt));
        }
        
        else {
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }

        cout << endl << "Printing Weighted Graph: " << endl;
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
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 6, 0);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(2, 4, 3, 1);
}
