#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

void DFSUtil(int v, vector<int> adj[], vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
}

void DFS(vector<int> adj[], int V) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
}

int main() {
    int size = 10;  
    vector<int> adj[size];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 2, 7);
    addEdge(adj, 3, 8);
    addEdge(adj, 3, 9);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 7, 9);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    cout << "\nDepth First Search starting from vertex 0:" << endl;
    DFS(adj, size);

    return 0;
}
