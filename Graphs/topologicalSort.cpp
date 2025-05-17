#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <map>
#include <queue>

using namespace std;

class Graph {
public:
    unordered_map<int,list<int>> adjList;
    
    void addEdge(int u, int v, bool direction) {

        adjList[u].push_back(v);

        if(direction == 0) {
            adjList[v].push_back(u);
        }
        cout << "Printing Adj List:\n";
        printAdjList();
        cout << endl;
    }
    void printAdjList() {
        for(auto i: adjList) {
            cout << i.first << "-> { ";

            for(auto nbr: i.second) {
                cout << nbr << " ";
            }
            cout << " } " << endl;
        }
    }
    //topological sort using DFS
    void topoSortDFS(int src, map<int,bool>& visited, stack<int>& st) {
        visited[src] = true;

        for(auto nbr: adjList[src]) {
            if(!visited[nbr]) {
                topoSortDFS(nbr,visited,st);
            }
        }
        st.push(src);
    }
    //topological sort using BFS
    void topoSortBFS(int n) {
        queue<int> q;
        map<int,int> indegree;

        //initialize kardenge sabki indegree
        for(auto i: adjList) {
            for(auto nbr: i.second) {
                indegree[nbr]++;
            }
        }
        //push all zero indegree wali node in the queue
        for(int node=0; node<n; node++) {
            if(indegree[node] == 0) {
                q.push(node);
            }
        }
        //BFS chalate hain
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            for(auto nbr: adjList[frontNode]) {
                indegree[nbr]--;

                //check for zero
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
};
int main() {
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);

    int n = 5;
    cout << "Printing Topological order using bfs: " << endl;
    g.topoSortBFS(n);

    // map<int,bool> visited;
    // stack<int> st;
    // for(int node =0; node < n; node++) {
    //     if(!visited[node]){
    //         g.topoSortDFS(node, visited, st);
    //     }
    // }
    // cout << "Printing the topo order: " << endl;
    // while(!st.empty()) {
    //     cout << st.top() << ", ";
    //     st.pop();
    // }
}
