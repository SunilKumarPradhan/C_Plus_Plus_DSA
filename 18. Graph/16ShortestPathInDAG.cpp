#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // Remove this line if the graph is directed
}

bool BFS(vector<int> adj[], int src, int dest, int size, vector<int> &path) {
    vector<bool> visited(size, false);
    vector<int> parent(size, -1);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (auto i : adj[vertex]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = vertex;
                q.push(i);

                if (i == dest) {
                    int crawl = dest;
                    path.push_back(crawl);
                    while (parent[crawl] != -1) {
                        path.push_back(parent[crawl]);
                        crawl = parent[crawl];
                    }
                    reverse(path.begin(), path.end());
                    return true;
                }
            }
        }
    }

    return false;
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

    int src = 2, dest = 4;
    vector<int> path;

    if (BFS(adj, src, dest, size, path)) {
        cout << "\nShortest path from " << src << " to " << dest << " is: ";
        for (int i : path)
            cout << i << " ";
        cout << endl;
    } else {
        cout << "\nNo path exists from " << src << " to " << dest << endl;
    }

    return 0;
}
