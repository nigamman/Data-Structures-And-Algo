#include <iostream>
#include <unordered_map>
#include <list>
#include <limits.h>
#include <stack>
#include <vector>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction) {
        adjList[u].push_back({v, weight});
        if (!direction) {
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << " -> { ";
            for (auto nbr : i.second) {
                cout << "(" << nbr.first << "," << nbr.second << ") ";
            }
            cout << "}" << endl;
        }
    }

    void topologicalSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& st) {
        visited[src] = true;

        for (auto nbrPair : adjList[src]) {
            int nbrNode = nbrPair.first;
            if (!visited[nbrNode]) {
                topologicalSortDfs(nbrNode, visited, st);
            }
        }
        st.push(src);
    }

    void shortestPath(int n, stack<int>& st) {
        vector<int> dist(n, INT_MAX);

        if (!st.empty()) {
            int src = st.top();
            dist[src] = 0;
        }

        while (!st.empty()) {
            int src = st.top();
            st.pop();

            if (dist[src] == INT_MAX) continue;

            for (auto nbrPair : adjList[src]) {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if (dist[src] + nbrDist < dist[nbrNode]) {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        for (int i = 0; i < dist.size(); ++i) {
            cout << "Node " << i << " -> Distance: ";
            if (dist[i] == INT_MAX) cout << "INF" << endl;
            else cout << dist[i] << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 1, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(1, 3, 1, 1);
    g.addEdge(2, 4, 1, 1);

    g.printAdjList();

    stack<int> topoOrder;
    unordered_map<int, bool> visited;

    for (auto node : g.adjList) {
        if (!visited[node.first]) {
            g.topologicalSortDfs(node.first, visited, topoOrder);
        }
    }

    int n = 5;
    g.shortestPath(n, topoOrder);
}
