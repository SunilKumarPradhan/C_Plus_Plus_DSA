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


/*
Iss function ka naam hai bellmanFord aur yeh function Bellman-Ford algorithm use karke graph ke shortest paths find karta hai. Yeh algorithm negative weight cycles ko bhi detect kar sakta hai.

- Function ka logic:
  1. Pehle sabhi distances ko infinity (INT_MAX) set karte hain aur source node ka distance 0 set karte hain.
  2. V-1 baar sabhi edges ko relax karte hain (yani unka distance update karte hain agar naya distance kam hai).
  3. Ek aur pass mein agar distance update ho jaye toh negative weight cycle detect hota hai.

Process:
- Pehle, distances initialize karte hain: source node ka distance 0 aur baaki sab nodes ka INT_MAX.
- Phir, V-1 passes mein har edge ko relax karte hain.
- Last mein, check karte hain agar koi distance update ho toh graph mein negative weight cycle hai.

Example:
- Agar example graph yeh hai:

Adjacency List:
(0, 1, 1)
(0, 2, 4)
(0, 3, 5)
(1, 4, 6)
(1, 5, 7)
(2, 6, 8)
(2, 7, 9)
(3, 8, 10)
(3, 9, 11)
(4, 6, 12)
(5, 7, 13)
(6, 8, 14)
(7, 9, 15)

Dry Run:
1. Initial setup and input:
   - Distances: [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
   - Source: 0

2. Step-by-step execution with intermediate values:
   - Pass 1:
     - Relax edge (0, 1, 1): dist[1] = 1
     - Relax edge (0, 2, 4): dist[2] = 4
     - Relax edge (0, 3, 5): dist[3] = 5
     - Relax edge (1, 4, 6): dist[4] = 7 (1 + 6)
     - Relax edge (1, 5, 7): dist[5] = 8 (1 + 7)
     - Relax edge (2, 6, 8): dist[6] = 12 (4 + 8)
     - Relax edge (2, 7, 9): dist[7] = 13 (4 + 9)
     - Relax edge (3, 8, 10): dist[8] = 15 (5 + 10)
     - Relax edge (3, 9, 11): dist[9] = 16 (5 + 11)
     - Relax edge (4, 6, 12): no change (7 + 12 > 12)
     - Relax edge (5, 7, 13): no change (8 + 13 > 13)
     - Relax edge (6, 8, 14): no change (12 + 14 > 15)
     - Relax edge (7, 9, 15): no change (13 + 15 > 16)

   - Repeat similar steps for Passes 2 to V-1, distances remain the same as no further updates occur.

3. Final output:
   - Vertex   Distance from Source
   - 0        0
   - 1        1
   - 2        4
   - 3        5
   - 4        7
   - 5        8
   - 6        12
   - 7        13
   - 8        15
   - 9        16

Output:
Vertex Distance from Source
0               0
1               1
2               4
3               5
4               7
5               8
6               12
7               13
8               15
9               16
*/
