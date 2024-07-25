#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // Remove this line if the graph is directed
}

void BFS(vector<int> adj[], int start, int size) {
    vector<bool> visited(size, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();

        for (auto i : adj[vertex]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


int main() {
    int size = 5;  // Define the correct size of the graph
    vector<int> adj[size];

    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 0);

    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    cout << "\nBFS starting from vertex 2:\n";
    BFS(adj, 2, size);


    return 0;
}
