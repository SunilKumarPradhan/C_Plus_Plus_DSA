#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}


bool DFSUtil(int v, vector<int> adj[], vector<bool> &visited, int parent) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            if (DFSUtil(i, adj, visited, v))
                return true;
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int size) {
    vector<bool> visited(size, false);
    for (int u = 0; u < size; u++) {
        if (!visited[u]) {
            if (DFSUtil(u, adj, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int size = 21;  // Increased size to accommodate more nodes
    vector<int> adj[size];

    // Level 0 to Level 1
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 4);

    // Level 1 to Level 2
    addEdge(adj, 1, 5);
    addEdge(adj, 1, 6);
    addEdge(adj, 2, 7);
    addEdge(adj, 2, 8);
    addEdge(adj, 3, 9);
    addEdge(adj, 3, 10);
    addEdge(adj, 4, 11);
    addEdge(adj, 4, 12);

    // Level 2 to Level 3
    addEdge(adj, 5, 13);
    addEdge(adj, 6, 14);
    addEdge(adj, 7, 15);
    addEdge(adj, 8, 16);
    addEdge(adj, 9, 17);
    addEdge(adj, 10, 18);
    addEdge(adj, 11, 19);
    addEdge(adj, 12, 20);

    // Additional edges for complexity
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 9, 11);
    addEdge(adj, 10, 12);
    addEdge(adj, 13, 15);
    addEdge(adj, 14, 16);
    addEdge(adj, 17, 19);
    addEdge(adj, 18, 20);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }
    
    if (isCyclic(adj, size))
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;


    return 0;
}