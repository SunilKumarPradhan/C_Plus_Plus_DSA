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


/*
Iss function ka naam hai primMST aur yeh function Prim's Algorithm use karke minimum spanning tree (MST) nikalta hai weighted undirected graph ke liye.

- Function ka logic:
  1. Har node ke liye ek priority queue maintain karte hain jo minimum weight edge ko track karti hai.
  2. Key array use karte hain minimum edge weight store karne ke liye jo MST ka part ban sakta hai.
  3. Parent array use karte hain MST ko track karne ke liye.
  4. InMST array use karte hain jo track karta hai ki kaunse nodes MST ka part ban chuke hain.

Process:
- Pehle, source node ko queue mein push karte hain aur uska key value 0 set karte hain.
- Jab tak priority queue empty nahi ho jati, har node ke adjacent nodes ko visit karte hain aur agar weight kam hai aur node MST mein nahi hai to us node ko queue mein push karte hain aur parent aur key values update karte hain.
- Jab sab nodes MST ka part ban jate hain, parent array use karke MST ko print karte hain.

Example:
- Agar example graph yeh hai:

Adjacency List:
0: (1, 4) (2, 3) (3, 2) 
1: (0, 4) (4, 5) (5, 1) 
2: (0, 3) (6, 6) (7, 7) 
3: (0, 2) (8, 8) (9, 9) 
4: (1, 5) (6, 4) 
5: (1, 1) (7, 2) 
6: (2, 6) (4, 4) (8, 3) 
7: (2, 7) (5, 2) (9, 1) 
8: (3, 8) (6, 3) 
9: (3, 9) (7, 1) 

Dry Run:
1. Initial setup and input:
   - Priority Queue: [(0, 0)]
   - Key: [0, INF, INF, INF, INF, INF, INF, INF, INF, INF]
   - Parent: [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]
   - InMST: [false, false, false, false, false, false, false, false, false, false]
2. Step-by-step execution with intermediate values:
   - Pop (0, 0), visit 0, update InMST: [true, false, false, false, false, false, false, false, false, false]
     - Update: (1, 4), Key: [0, 4, INF, INF, INF, INF, INF, INF, INF, INF], Parent: [-1, 0, -1, -1, -1, -1, -1, -1, -1, -1]
     - Update: (2, 3), Key: [0, 4, 3, INF, INF, INF, INF, INF, INF, INF], Parent: [-1, 0, 0, -1, -1, -1, -1, -1, -1, -1]
     - Update: (3, 2), Key: [0, 4, 3, 2, INF, INF, INF, INF, INF, INF], Parent: [-1, 0, 0, 0, -1, -1, -1, -1, -1, -1]
   - Pop (3, 2), visit 3, update InMST: [true, false, false, true, false, false, false, false, false, false]
     - Update: (8, 8), Key: [0, 4, 3, 2, INF, INF, INF, INF, 8, INF], Parent: [-1, 0, 0, 0, -1, -1, -1, -1, 3, -1]
     - Update: (9, 9), Key: [0, 4, 3, 2, INF, INF, INF, INF, 8, 9], Parent: [-1, 0, 0, 0, -1, -1, -1, -1, 3, 3]
   - Pop (2, 3), visit 2, update InMST: [true, false, true, true, false, false, false, false, false, false]
     - Update: (6, 6), Key: [0, 4, 3, 2, INF, INF, 6, INF, 8, 9], Parent: [-1, 0, 0, 0, -1, -1, 2, -1, 3, 3]
     - Update: (7, 7), Key: [0, 4, 3, 2, INF, INF, 6, 7, 8, 9], Parent: [-1, 0, 0, 0, -1, -1, 2, 2, 3, 3]
   - Pop (1, 4), visit 1, update InMST: [true, true, true, true, false, false, false, false, false, false]
     - Update: (5, 1), Key: [0, 4, 3, 2, INF, 1, 6, 7, 8, 9], Parent: [-1, 0, 0, 0, -1, 1, 2, 2, 3, 3]
   - Continue this process until all nodes are in MST.

3. Final output:
   - Edge  Weight
     0 - 1  4
     0 - 2  3
     0 - 3  2
     1 - 5  1
     5 - 7  2
     2 - 6  6
     6 - 8  3
     3 - 9  9

Output:
Minimum Spanning Tree using Prim's Algorithm:
Edge    Weight
0 - 1   4
0 - 2   3
0 - 3   2
1 - 5   1
5 - 7   2
2 - 6   6
6 - 8   3
3 - 9   9
*/
