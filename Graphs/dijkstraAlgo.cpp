#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <vector>
#include <climits>
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

    void dijAlgo(int n, int src, int dest) {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // Initial state
        st.insert({0, src});
        dist[src] = 0;

        while (!st.empty()) {
            auto top = *(st.begin());
            int topDist = top.first;
            int topNode = top.second;
            st.erase(st.begin());

            for (auto nbrPair : adjList[topNode]) {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;

                if (topDist + nbrDist < dist[nbrNode]) {
                    // If entry exists, remove it
                    auto found = st.find({dist[nbrNode], nbrNode});
                    if (found != st.end()) {
                        st.erase(found);
                    }
                    // Update distance and insert new pair
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        cout << "Shortest Distance from " << src << " to " << dest << " is: " << dist[dest] << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    int n = 6;
    int src = 6;
    int dest = 4;

    g.dijAlgo(n, src, dest);
}
