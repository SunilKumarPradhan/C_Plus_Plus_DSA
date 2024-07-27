#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));  
}

void primMST(vector<pair<int, int>> adj[], int size) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(size, INT_MAX);
    vector<int> parent(size, -1);
    vector<bool> inMST(size, false);

    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < size; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        }
    }
}

int main() {
    int size = 10;  
    vector<pair<int, int>> adj[size];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 0, 3, 2);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 1, 5, 1);
    addEdge(adj, 2, 6, 6);
    addEdge(adj, 2, 7, 7);
    addEdge(adj, 3, 8, 8);
    addEdge(adj, 3, 9, 9);
    addEdge(adj, 4, 6, 4);
    addEdge(adj, 5, 7, 2);
    addEdge(adj, 6, 8, 3);
    addEdge(adj, 7, 9, 1);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << "(" << j.first << ", " << j.second << ") ";
        cout << endl;
    }

    cout << "\nMinimum Spanning Tree using Prim's Algorithm:\n";
    primMST(adj, size);

    return 0;
}
