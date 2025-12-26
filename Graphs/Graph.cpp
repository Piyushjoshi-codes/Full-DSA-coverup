#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Graph {
public:
    Graph(int vertices) {
        V = vertices;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    void display() {
        for (const auto& pair : adj) {
            cout << pair.first << " -> ";
            for (const int& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
private:
    int V; // Number of vertices
    map<int, list<int>> adj; // Adjacency list representation
};  
        
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
    return 0;
}