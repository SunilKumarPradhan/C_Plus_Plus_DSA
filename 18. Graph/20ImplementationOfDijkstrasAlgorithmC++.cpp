#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));  // Remove this line if the graph is directed
}

void dijkstra(vector<pair<int, int>> adj[], int size, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(size, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < size; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int size = 10;
    vector<pair<int, int>> adj[size];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 0, 3, 7);
    addEdge(adj, 1, 4, 3);
    addEdge(adj, 1, 5, 1);
    addEdge(adj, 2, 6, 6);
    addEdge(adj, 2, 7, 2);
    addEdge(adj, 3, 8, 5);
    addEdge(adj, 3, 9, 4);
    addEdge(adj, 4, 6, 2);
    addEdge(adj, 5, 7, 4);
    addEdge(adj, 6, 8, 3);
    addEdge(adj, 7, 9, 1);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << "(" << j.first << ", " << j.second << ") ";
        cout << endl;
    }

    int src = 0;
    cout << "\nDijkstra's Shortest Path Algorithm starting from vertex " << src << ":\n";
    dijkstra(adj, size, src);

    return 0;
}
