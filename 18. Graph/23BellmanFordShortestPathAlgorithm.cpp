#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<tuple<int, int, int>> &edges, int u, int v, int w) {
    edges.push_back(make_tuple(u, v, w));
}

void bellmanFord(vector<tuple<int, int, int>> &edges, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < V; ++i) {
        for (auto edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int size = 10;
    vector<tuple<int, int, int>> edges;

    addEdge(edges, 0, 1, 1);
    addEdge(edges, 0, 2, 4);
    addEdge(edges, 0, 3, 5);
    addEdge(edges, 1, 4, 6);
    addEdge(edges, 1, 5, 7);
    addEdge(edges, 2, 6, 8);
    addEdge(edges, 2, 7, 9);
    addEdge(edges, 3, 8, 10);
    addEdge(edges, 3, 9, 11);
    addEdge(edges, 4, 6, 12);
    addEdge(edges, 5, 7, 13);
    addEdge(edges, 6, 8, 14);
    addEdge(edges, 7, 9, 15);

    cout << "Adjacency List Representation:" << endl;
    for (auto edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        cout << "(" << u << ", " << v << ", " << w << ")" << endl;
    }

    int src = 0;
    bellmanFord(edges, size, src);

    return 0;
}
