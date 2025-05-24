#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>

using namespace std;

template <typename my>
class Graph{
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

    void floydWarshall(int n) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        //src-> src ka distance 0 hoga
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        //some weight are given in adjacency list from u --> v
        for(auto i: adjList) {
            for(auto nbr: i.second) {
                my u = i.first;
                my v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }
        //main logic of floyd warshall 
        for(int helper = 0; helper < n; helper++) {
            for(int src = 0; src < n; src++) {
                for(int dest=0; dest < n; dest++) {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }
        //distance array is ready to go 
        for(auto i: dist) {
            for(auto j: i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph<int> g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(3, 2, 2, 1);
    g.addEdge(2, 1, 1, 1);

    g.floydWarshall(4);
}