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


/*
Iss function ka naam hai dijkstra aur yeh function Dijkstra's Algorithm use karke shortest path nikalta hai source node se baaki sab nodes ke liye weighted undirected graph mein.

- Function ka logic:
  1. Ek priority queue maintain karte hain jo minimum distance ko track karti hai har node ke liye.
  2. Distance array use karte hain har node tak pahunchne ka minimum distance store karne ke liye.
  3. Source node ko initialize karte hain distance 0 ke saath aur queue mein push karte hain.
  4. Queue se node nikalte hain aur uske adjacent nodes ko visit karte hain agar unka naya distance current distance plus edge weight se kam hai.

Process:
- Pehle, source node ko queue mein push karte hain aur uska distance 0 set karte hain.
- Jab tak priority queue empty nahi ho jati, har node ke adjacent nodes ko visit karte hain aur agar naya distance kam hai to us node ko queue mein push karte hain aur distance values update karte hain.
- Jab sab nodes visit ho jate hain, distance array use karke har node ka shortest distance print karte hain.

Example:
- Agar example graph yeh hai:

Adjacency List:
0: (1, 4) (2, 1) (3, 7) 
1: (0, 4) (4, 3) (5, 1) 
2: (0, 1) (6, 6) (7, 2) 
3: (0, 7) (8, 5) (9, 4) 
4: (1, 3) (6, 2) 
5: (1, 1) (7, 4) 
6: (2, 6) (4, 2) (8, 3) 
7: (2, 2) (5, 4) (9, 1) 
8: (3, 5) (6, 3) 
9: (3, 4) (7, 1) 

Dry Run:
1. Initial setup and input:
   - Priority Queue: [(0, 0)]
   - Distance: [0, INF, INF, INF, INF, INF, INF, INF, INF, INF]
2. Step-by-step execution with intermediate values:
   - Pop (0, 0), visit 0, update Distance: [0, 4, 1, 7, INF, INF, INF, INF, INF, INF]
     - Update: (1, 4), Distance: [0, 4, INF, INF, INF, INF, INF, INF, INF, INF]
     - Update: (2, 1), Distance: [0, 4, 1, INF, INF, INF, INF, INF, INF, INF]
     - Update: (3, 7), Distance: [0, 4, 1, 7, INF, INF, INF, INF, INF, INF]
   - Pop (2, 1), visit 2, update Distance: [0, 4, 1, 7, INF, INF, 7, 3, INF, INF]
     - Update: (6, 7), Distance: [0, 4, 1, 7, INF, INF, 7, INF, INF, INF]
     - Update: (7, 3), Distance: [0, 4, 1, 7, INF, INF, 7, 3, INF, INF]
   - Pop (7, 3), visit 7, update Distance: [0, 4, 1, 7, INF, INF, 7, 3, INF, 4]
     - Update: (9, 4), Distance: [0, 4, 1, 7, INF, INF, 7, 3, INF, 4]
   - Pop (1, 4), visit 1, update Distance: [0, 4, 1, 7, 7, 5, 7, 3, INF, 4]
     - Update: (4, 7), Distance: [0, 4, 1, 7, 7, 5, 7, 3, INF, 4]
     - Update: (5, 5), Distance: [0, 4, 1, 7, 7, 5, 7, 3, INF, 4]
   - Continue this process until all nodes have been processed.

3. Final output:
   - Vertex   Distance from Source
     0        0
     1        4
     2        1
     3        7
     4        7
     5        5
     6        7
     7        3
     8        10
     9        4

Output:
Dijkstra's Shortest Path Algorithm starting from vertex 0:
Vertex   Distance from Source
0        0
1        4
2        1
3        7
4        7
5        5
6        7
7        3
8        10
9        4
*/
