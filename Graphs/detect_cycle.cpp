#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        if (direction == 1) {
            adjList[u].push_back(v);
        } else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        cout << "\nPrinting AdjList:\n";
        printAdjList();
        cout << endl;
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << " -> { ";
            for (auto neighbour : i.second) {
                cout << neighbour << " ";
            }
            cout << "}" << endl;
        }
    }

    bool detectCycleUsingDFS(T node, unordered_map<T, bool> &visited, unordered_map<T, bool> &dfsTrack) {
        visited[node] = true;
        dfsTrack[node] = true;

        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                if (detectCycleUsingDFS(nbr, visited, dfsTrack)) {
                    return true;
                }
            } else if (dfsTrack[nbr]) {
                return true;
            }
        }
        // Backtracking
        dfsTrack[node] = false; 
        return false;
    }

    bool isCyclic() {
        unordered_map<T, bool> visited;
        unordered_map<T, bool> dfsTrack;

        for (auto nodePair : adjList) {
            T node = nodePair.first;
            if (!visited[node]) {
                if (detectCycleUsingDFS(node, visited, dfsTrack)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('a', 'c', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('c', 'd', 0);
    g.addEdge('c', 'e', 0);
    g.addEdge('e', 'f', 0);

    if (g.isCyclic()) {
        cout << "Graph contains a cycle.\n";
    } else {
        cout << "Graph does not contain a cycle.\n";
    }

    return 0;
}
