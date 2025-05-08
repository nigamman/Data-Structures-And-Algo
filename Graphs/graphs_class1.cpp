#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>
#include <queue>
using namespace std;

template <typename t>
class Graph {
    public:
        unordered_map<t,list<t>> adjList;

        void addEdge(t u, t v, bool direction) {
            //direction -> 0 -> undirected
            //direction -> 1 -> directed
            if(direction == 1) {
                adjList[u].push_back(v);
            }
            else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            cout << endl << "Printing AdjList: " << endl;
            printAdjList();
            cout << endl;
        }
        void printAdjList() {
            for(auto i: adjList) {
                cout << i.first << "-> {";
                for(auto neighbour: i.second) {
                    cout << neighbour << ", ";
                }
                cout << "}" << endl;
            }
        }
        void bfsTraversal(t src) {
            //adjList already dataList m hain visited
            unordered_map<t, bool> vis;
            //queue
            queue<t> q;

            //initial state 
            q.push(src);
            vis[src] = true;

            cout << "\nBFS Traversal: ";
            while(!q.empty()) {
                t frontNode = q.front();
                cout << frontNode << " ";
                q.pop();

                //go to neighbour
                for (auto neighbour : adjList[frontNode]) {
                    if (!vis[neighbour]) {
                        q.push(neighbour);
                        vis[neighbour] = true;
                    }
                }
            }
            cout << endl;
        } 
};

int main() {
    Graph<char> g;
    g.addEdge('a','b',0);
    g.addEdge('a','c',0);
    g.addEdge('b','c',0);
    g.addEdge('c','d',0);
    g.addEdge('c','e',0);
    g.addEdge('e','f',0);

    g.bfsTraversal('a');
}
