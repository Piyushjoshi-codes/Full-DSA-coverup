#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

// Function to add an undirected edge between vertices u and v
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Remove this line for a directed graph
}

// Function to print the graph
void printGraph(vector<int> adj[], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "\\n Adjacency list of vertex " << v << "\\n head ";
        for (auto x : adj[v]) {
            cout << "-> " << x;
        }
        cout << endl;
    }
}

// Driver code
int main() {
    int V = 5; // Total number of vertices
    // Create an array of vectors to represent the graph
    vector<int> adj[V];

    // Add edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, V);

    return 0;
}
