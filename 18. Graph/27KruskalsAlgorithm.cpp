#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2])
                parent[s1] = s2;
            else if (rank[s1] > rank[s2])
                parent[s2] = s1;
            else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};

vector<Edge> kruskal(vector<Edge>& edges, int V) {
    vector<Edge> result;
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);

    for (Edge e : edges) {
        int u = e.u;
        int v = e.v;

        int s1 = ds.find(u);
        int s2 = ds.find(v);

        if (s1 != s2) {
            result.push_back(e);
            ds.unite(s1, s2);
        }
    }

    return result;
}

int main() {
    int V = 10;
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 3}, {0, 3, 5},
        {1, 4, 2}, {1, 5, 1},
        {2, 6, 3}, {2, 7, 6},
        {3, 8, 4}, {3, 9, 2},
        {4, 6, 3}, {5, 7, 4},
        {6, 8, 2}, {7, 9, 5}
    };

    cout << "Graph edges:" << endl;
    for (const auto& e : edges) {
        cout << e.u << " -- " << e.v << " : " << e.weight << endl;
    }

    vector<Edge> mst = kruskal(edges, V);

    cout << "\nMinimum Spanning Tree:" << endl;
    for (const auto& e : mst) {
        cout << e.u << " -- " << e.v << " : " << e.weight << endl;
    }

    return 0;
}