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

/*
Iss function ka naam hai kruskal aur yeh function Kruskal's algorithm use karke graph ka Minimum Spanning Tree (MST) find karta hai.

- Function ka logic:
  1. Saare edges ko weight ke ascending order mein sort karte hain.
  2. Ek disjoint set data structure ka use karke har node ko apna parent set karte hain.
  3. Sorted edges ko ek-ek karke check karte hain aur agar wo edge cycle nahi banata toh use MST mein include karte hain.

Process:
- Pehle, saare edges ko weight ke basis pe sort karte hain.
- Ek disjoint set banate hain jo har node ko apna parent set karta hai.
- Har sorted edge ke liye, agar wo edge cycle nahi banata (disjoint sets ka use karke), toh us edge ko MST mein add karte hain.
- Agar cycle banta hai, toh us edge ko ignore karte hain.

Example:
- Agar example graph yeh hai:

Graph edges:
0 -- 1 : 4
0 -- 2 : 3
0 -- 3 : 5
1 -- 4 : 2
1 -- 5 : 1
2 -- 6 : 3
2 -- 7 : 6
3 -- 8 : 4
3 -- 9 : 2
4 -- 6 : 3
5 -- 7 : 4
6 -- 8 : 2
7 -- 9 : 5

Dry Run:
1. Initial setup and input:
   - Graph edges as given above.
   - Number of vertices V = 10

2. Step-by-step execution with intermediate values:
   - Sorted edges by weight:
     {1, 5, 1}, {1, 4, 2}, {3, 9, 2}, {6, 8, 2}, {0, 2, 3}, {2, 6, 3}, {4, 6, 3},
     {0, 1, 4}, {3, 8, 4}, {5, 7, 4}, {0, 3, 5}, {7, 9, 5}, {2, 7, 6}

   - Initial disjoint sets: 
     0: {0}, 1: {1}, 2: {2}, 3: {3}, 4: {4}, 5: {5}, 6: {6}, 7: {7}, 8: {8}, 9: {9}

   - Processing edges:
     - Edge {1, 5, 1}: Add to MST, unite sets {1, 5} => MST: {1, 5, 1}
     - Edge {1, 4, 2}: Add to MST, unite sets {1, 4, 5} => MST: {1, 5, 1}, {1, 4, 2}
     - Edge {3, 9, 2}: Add to MST, unite sets {3, 9} => MST: {1, 5, 1}, {1, 4, 2}, {3, 9, 2}
     - Edge {6, 8, 2}: Add to MST, unite sets {6, 8} => MST: {1, 5, 1}, {1, 4, 2}, {3, 9, 2}, {6, 8, 2}
     - Edge {0, 2, 3}: Add to MST, unite sets {0, 2} => MST: {1, 5, 1}, {1, 4, 2}, {3, 9, 2}, {6, 8, 2}, {0, 2, 3}
     - Edge {2, 6, 3}: Add to MST, unite sets {0, 2, 6, 8} => MST: {1, 5, 1}, {1, 4, 2}, {3, 9, 2}, {6, 8, 2}, {0, 2, 3}, {2, 6, 3}
     - Edge {4, 6, 3}: Cycle detected, ignore
     - Edge {0, 1, 4}: Add to MST, unite sets {0, 1, 2, 4, 5, 6, 8} => MST: {1, 5, 1}, {1, 4, 2}, {3, 9, 2}, {6, 8, 2}, {0, 2, 3}, {2, 6, 3}, {0, 1, 4}
     - Edge {3, 8, 4}: Add to MST, unite sets {0, 1, 2, 3, 4, 5, 6, 8, 9} => MST: {1, 5, 1}, {1, 4, 2}, {3, 9, 2}, {6, 8, 2}, {0, 2, 3}, {2, 6, 3}, {0, 1, 4}, {3, 8, 4}

   - Continue for remaining edges, detecting cycles:
     - Edge {5, 7, 4}: Add to MST, unite sets {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} => MST: {1, 5, 1}, {1, 4, 2}, {3, 9, 2}, {6, 8, 2}, {0, 2, 3}, {2, 6, 3}, {0, 1, 4}, {3, 8, 4}, {5, 7, 4}
     - Edge {0, 3, 5}: Cycle detected, ignore
     - Edge {7, 9, 5}: Cycle detected, ignore
     - Edge {2, 7, 6}: Cycle detected, ignore

3. Final output:
   - MST edges: 
     {1, 5, 1}
     {1, 4, 2}
     {3, 9, 2}
     {6, 8, 2}
     {0, 2, 3}
     {2, 6, 3}
     {0, 1, 4}
     {3, 8, 4}
     {5, 7, 4}

Output:
Minimum Spanning Tree:
1 -- 5 : 1
1 -- 4 : 2
3 -- 9 : 2
6 -- 8 : 2
0 -- 2 : 3
2 -- 6 : 3
0 -- 1 : 4
3 -- 8 : 4
5 -- 7 : 4
*/
