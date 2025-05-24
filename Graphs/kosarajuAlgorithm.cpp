#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, int wt = 1, bool direction = 0) {
        adjList[u].push_back(v);
        if (direction == 1) { // undirected
            adjList[v].push_back(u);
        }
    }

    void dfs1(int node, unordered_map<int, bool>& vis, stack<int>& st) {
        vis[node] = true;
        for (int nbr : adjList[node]) {
            if (!vis[nbr]) {
                dfs1(nbr, vis, st);
            }
        }
        st.push(node); // topological sort postorder
    }

    void dfs2(int node, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adjNew) {
        vis[node] = true;
        for (int nbr : adjNew[node]) {
            if (!vis[nbr]) {
                dfs2(nbr, vis, adjNew);
            }
        }
    }

    int kosarajuAlgo(int n) {
        stack<int> ordering;
        unordered_map<int, bool> vis;

        // Step 1: Do Topological Sort
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs1(i, vis, ordering);
            }
        }

        // Step 2: Reverse the edges
        unordered_map<int, list<int>> adjNew;
        for (auto it : adjList) {
            int u = it.first;
            for (int v : it.second) {
                adjNew[v].push_back(u);
            }
        }

        // Step 3: Process the reversed graph
        unordered_map<int, bool> visited2;
        int count = 0;

        while (!ordering.empty()) {
            int topNode = ordering.top();
            ordering.pop();
            if (!visited2[topNode]) {
                dfs2(topNode, visited2, adjNew);
                count++;
            }
        }

        return count;
    }

    void printAdjList() {
        for (auto& i : adjList) {
            cout << i.first << " -> { ";
            for (auto& p : i.second) {
                cout << p << " ";
            }
            cout << "}" << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);
    g.addEdge(6, 7);

    g.printAdjList();
    int ans = g.kosarajuAlgo(8);
    cout << "SCC Count: " << ans << endl;

    return 0;
}
