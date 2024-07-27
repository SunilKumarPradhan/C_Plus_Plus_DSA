#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}


bool DFSUtil(int v, vector<int> adj[], vector<bool> &visited, int parent) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            if (DFSUtil(i, adj, visited, v))
                return true;
        } else if (i != parent) {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int size) {
    vector<bool> visited(size, false);
    for (int u = 0; u < size; u++) {
        if (!visited[u]) {
            if (DFSUtil(u, adj, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int size = 21;  // Increased size to accommodate more nodes
    vector<int> adj[size];

    // Level 0 to Level 1
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 4);

    // Level 1 to Level 2
    addEdge(adj, 1, 5);
    addEdge(adj, 1, 6);
    addEdge(adj, 2, 7);
    addEdge(adj, 2, 8);
    addEdge(adj, 3, 9);
    addEdge(adj, 3, 10);
    addEdge(adj, 4, 11);
    addEdge(adj, 4, 12);

    // Level 2 to Level 3
    addEdge(adj, 5, 13);
    addEdge(adj, 6, 14);
    addEdge(adj, 7, 15);
    addEdge(adj, 8, 16);
    addEdge(adj, 9, 17);
    addEdge(adj, 10, 18);
    addEdge(adj, 11, 19);
    addEdge(adj, 12, 20);

    // Additional edges for complexity
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 9, 11);
    addEdge(adj, 10, 12);
    addEdge(adj, 13, 15);
    addEdge(adj, 14, 16);
    addEdge(adj, 17, 19);
    addEdge(adj, 18, 20);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }
    
    if (isCyclic(adj, size))
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;


    return 0;
}



/*
Iss function ka naam hai isCyclic aur yeh graph mein cycle ko detect karta hai using Depth-First Search (DFS).

- Function ka logic:
  1. `isCyclic` function ko adjacency list aur graph ka size diya jata hai.
  2. Ek visited array create kiya jata hai jise sabhi nodes ke liye false se initialize kiya jata hai.
  3. Har node ke liye, agar woh visited nahi hai, toh `DFSUtil` function call kiya jata hai.
  4. `DFSUtil` function har node ko visit karta hai aur check karta hai ki koi back edge exist karti hai ya nahi.
  5. Agar back edge milti hai (i.e., already visited node jo parent nahi hai), toh cycle present hai.

Process:
- Pehle, `isCyclic` function ek visited array create karta hai aur usse false se initialize karta hai.
- Har node ke liye, agar woh visited nahi hai, toh `DFSUtil` function call karta hai.
- `DFSUtil` function har node ko visit karta hai aur check karta hai ki koi back edge exist karti hai ya nahi.
- Agar back edge milti hai, toh cycle present hai aur true return karta hai.

Example:
- Agar graph ka example hai:

0 -- 1 -- 5 -- 7
|    |    |    |
2 -- 6 -- 14-- 16
|    |    |    |
3 -- 9 -- 11-- 19
|    |    |    |
4 --10 -- 12-- 20

then

Adjacency List Representation:
0: 1 2 3 4 
1: 0 5 6 
2: 0 7 8 
3: 0 9 10 
4: 0 11 12 
5: 1 7 13 
6: 1 14 8 
7: 2 15 16 
8: 2 6 
9: 3 17 
10: 3 18 
11: 4 19 
12: 4 20 
13: 5 15 
14: 6 16 
15: 7 13 
16: 7 14 
17: 9 19 
18: 10 20 
19: 11 17 
20: 12 18 

- `isCyclic` function ko call karte hai jo graph mein cycle detect karta hai aur result print karta hai.

Dry Run:
1. Initial setup and input:
    - Visited array: [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
    - Adjacency list: [ [1, 2, 3, 4], [0, 5, 6], [0, 7, 8], [0, 9, 10], [0, 11, 12], [1, 7, 13], [1, 14, 8], [2, 15, 16], [2, 6], [3, 17], [3, 18], [4, 19], [4, 20], [5, 15], [6, 16], [7, 13], [7, 14], [9, 19], [10, 20], [11, 17], [12, 18] ]
    - Start node: 0

2. Step-by-step execution:
    - Start from node 0 -> visited: [true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
    - Visit neighbor 1 -> DFSUtil(1, parent=0) -> visited: [true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
    - Visit neighbor 5 -> DFSUtil(5, parent=1) -> visited: [true, true, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
    - Visit neighbor 7 -> DFSUtil(7, parent=5) -> visited: [true, true, false, false, false, true, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false]
    - Visit neighbor 2 -> DFSUtil(2, parent=7) -> visited: [true, true, true, false, false, true, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false]
    - Visit neighbor 0 -> already visited and not parent -> cycle detected -> return true

3. Final output:
    - Graph contains cycle

Output:
Graph contains cycle
*/

