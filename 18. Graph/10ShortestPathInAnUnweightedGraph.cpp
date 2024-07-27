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
Iss function ka naam hai shortestPath aur yeh graph mein source node se sabhi nodes tak ka shortest path calculate karta hai using Breadth-First Search (BFS).

- Function ka logic:
  1. `shortestPath` function ko adjacency list, graph ka size aur source node diya jata hai.
  2. Ek distance array create kiya jata hai jise sabhi nodes ke liye INT_MAX se initialize kiya jata hai (representing infinite distance initially).
  3. Source node ka distance 0 set kiya jata hai aur usse queue mein push kiya jata hai.
  4. Jab tak queue khali nahi hoti, har node ko dequeue kiya jata hai aur uske adjacent nodes ka distance update kiya jata hai agar woh unvisited hai (i.e., distance INT_MAX hai).
  5. Updated distance ke saath unhe queue mein push kiya jata hai.

Process:
- Pehle, `shortestPath` function ek distance array create karta hai aur usse INT_MAX se initialize karta hai.
- Source node ka distance 0 set karta hai aur queue mein push karta hai.
- Queue mein se har node ko nikalta hai aur uske adjacent nodes ka distance update karta hai agar woh unvisited hai.
- Updated distance ke saath unhe queue mein push karta hai.

Example:
- Agar graph ka example hai:

0 -- 1 -- 4
| \  | \  |
|  \ |  \ |
2 -- 6 -- 5
|   | \  /
|   |  7
3 -- 8 -- 9

then

Adjacency List Representation:
0: 1 2 3 
1: 0 4 5 
2: 0 6 7 
3: 0 8 9 
4: 1 6 
5: 1 7 
6: 2 4 8 
7: 2 5 9 
8: 3 6 
9: 3 7 

- `shortestPath` function ko call karte hai jo source node 0 se har node ka shortest path calculate karta hai aur result print karta hai.

Dry Run:
1. Initial setup and input:
    - Distance array: [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
    - Adjacency list: [ [1, 2, 3], [0, 4, 5], [0, 6, 7], [0, 8, 9], [1, 6], [1, 7], [2, 4, 8], [2, 5, 9], [3, 6], [3, 7] ]
    - Source node: 0

2. Step-by-step execution:
    - Start from node 0 -> queue: [0], distance: [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
    - Dequeue 0 -> visit neighbors 1, 2, 3 -> queue: [1, 2, 3], distance: [0, 1, 1, 1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
    - Dequeue 1 -> visit neighbors 4, 5 -> queue: [2, 3, 4, 5], distance: [0, 1, 1, 1, 2, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
    - Dequeue 2 -> visit neighbors 6, 7 -> queue: [3, 4, 5, 6, 7], distance: [0, 1, 1, 1, 2, 2, 2, 2, INT_MAX, INT_MAX]
    - Dequeue 3 -> visit neighbors 8, 9 -> queue: [4, 5, 6, 7, 8, 9], distance: [0, 1, 1, 1, 2, 2, 2, 2, 2, 2]
    - Continue dequeue until queue is empty

3. Final output:
    - Shortest distances from source 0:
      Node 0: 0
      Node 1: 1
      Node 2: 1
      Node 3: 1
      Node 4: 2
      Node 5: 2
      Node 6: 2
      Node 7: 2
      Node 8: 2
      Node 9: 2

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
Node 8: 2
Node 9: 2
*/
