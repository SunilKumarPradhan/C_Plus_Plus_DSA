#include <bits/stdc++.h>
using namespace std;

void shortestPath(vector<int> adj[], int size, int src) {
    vector<int> dist(size, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node]) {
            if (dist[neighbor] == INT_MAX) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < size; ++i) {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
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


    cout << "Adjacency List Representation:"<<endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    int src = 0; // Starting node for shortest path calculation
    shortestPath(adj, size, src);

    
    return 0;
}



/*
Iss function ka naam hai shortestPath aur yeh function ek graph mein given source node se sabhi nodes tak ka shortest distance find karta hai using Breadth-First Search (BFS) algorithm.

- Function ka logic:
  1. Ek dist vector banate hain jismein har node ka distance initially INT_MAX hota hai (matlab infinite).
  2. Ek queue initialize karte hain aur source node ko distance 0 set karke queue mein push karte hain.
  3. Jab tak queue khali nahi ho jata, tab tak front node ko nikalte hain aur uske saare adjacent nodes ka distance update karte hain agar woh INT_MAX hai.
  4. Adjacent nodes ko distance update karke queue mein push karte hain.

Process:
- Pehle, dist vector aur queue initialize hoti hai.
- Source node ka distance 0 set karke queue mein push hota hai.
- Har iteration mein, front node nikalta hai aur uske saare adjacent nodes ka distance update hota hai agar woh INT_MAX hai.
- Distance update karke adjacent nodes ko queue mein push karte hain.
- Yeh process tab tak repeat hota hai jab tak queue khali nahi ho jati.

Example:
- Agar yeh graph hai:
  0 - 1 - 4
  | \ |   |
  2 - 5 - 6
  |   |
  3   7

then
adjacency list representation:
0: 1 2 3
1: 0 4 5
2: 0 6 7
3: 0
4: 1 6
5: 1 7
6: 2 4
7: 2 5

then 
- Shortest Path from vertex 0:

Three Iterations:
- Iteration 1:
  Queue: [0]
  Output: 0
  dist = [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
  Queue after processing 0: [1, 2, 3]
  dist = [0, 1, 1, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

- Iteration 2:
  Queue: [1, 2, 3]
  Output: 0 1
  Queue after processing 1: [2, 3, 4, 5]
  dist = [0, 1, 1, 1, 2, 2, INT_MAX, INT_MAX]

- Iteration 3:
  Queue: [2, 3, 4, 5]
  Output: 0 1 2
  Queue after processing 2: [3, 4, 5, 6, 7]
  dist = [0, 1, 1, 1, 2, 2, 2, 2]

Dry Run:
1. Initial setup and input:
   - size = 10
   - adj = [[1, 2, 3], [0, 4, 5], [0, 6, 7], [0], [1, 6], [1, 7], [2, 4], [2, 5], [], []]
   - src = 0

2. Step-by-step execution with intermediate values:
   - dist = [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
   - Queue: [0]
   - Process node 0:
     - dist = [0, 1, 1, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
     - Queue: [1, 2, 3]
   - Process node 1:
     - dist = [0, 1, 1, 1, 2, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
     - Queue: [2, 3, 4, 5]
   - Process node 2:
     - dist = [0, 1, 1, 1, 2, 2, 2, 2, INT_MAX, INT_MAX]
     - Queue: [3, 4, 5, 6, 7]
   - Process node 3:
     - dist = [0, 1, 1, 1, 2, 2, 2, 2, 2, 2]
     - Queue: [4, 5, 6, 7, 8, 9]

3. Final output:
   - Node 0: 0
   - Node 1: 1
   - Node 2: 1
   - Node 3: 1
   - Node 4: 2
   - Node 5: 2
   - Node 6: 2
   - Node 7: 2
   - Node 8: 3
   - Node 9: 3

Output:
Shortest distances from source 0:
Node 0: 0
Node 1: 1
Node 2: 1
Node 3: 1
Node 4: 2
Node 5: 2
Node 6: 2
Node 7: 2
Node 8: 3
Node 9: 3
*/


