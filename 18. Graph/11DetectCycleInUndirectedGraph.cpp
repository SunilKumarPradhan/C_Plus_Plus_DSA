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
Iss function ka naam hai isCyclic aur yeh function graph mein cycle detect karta hai using Depth-First Search (DFS) algorithm.

- Function ka logic:
  1. DFSUtil function recursively call karta hai nodes ko aur check karta hai agar koi node dobara visit ho rahi hai.
  2. Agar koi node dobara visit hoti hai aur woh parent node nahi hai, toh cycle exist karti hai.
  3. isCyclic function har node ke liye DFSUtil call karta hai agar woh visited nahi hai.

Process:
- Pehle, visited vector initialize hota hai.
- Har node ke liye DFSUtil call hota hai agar woh visited nahi hai.
- DFSUtil function recursively nodes ko visit karta hai aur cycle check karta hai.

Example:
- Agar yeh graph hai:
  0 - 1 - 5
  |   |   |
  2 - 6 - 7
  |       |
  3 - 4 - 8

then
adjacency list representation:
0: 1 2 3 4
1: 0 5 6
2: 0 7 8
3: 0
4: 0
5: 1 6 7
6: 1 5 8
7: 2 5 8
8: 2 6 7

then
- Cycle detection using DFS:

Three Iterations:
- Iteration 1:
  Stack: [0]
  Output: 0
  visited = [true, false, false, false, false, false, false, false, false]
  Stack after processing 0: [1, 2, 3, 4]
  visited = [true, true, true, true, true, false, false, false, false]

- Iteration 2:
  Stack: [1, 2, 3, 4]
  Output: 0 1
  Stack after processing 1: [2, 3, 4, 5, 6]
  visited = [true, true, true, true, true, true, true, false, false]

- Iteration 3:
  Stack: [2, 3, 4, 5, 6]
  Output: 0 1 2
  Stack after processing 2: [3, 4, 5, 6, 7, 8]
  visited = [true, true, true, true, true, true, true, true, true]

Dry Run:
1. Initial setup and input:
   - size = 21
   - adj = [[1, 2, 3, 4], [0, 5, 6], [0, 7, 8], [0], [0], [1, 6, 7], [1, 5, 8], [2, 5, 8], [2, 6, 7], [3, 10, 11], [3], [3], [4], [5], [6], [7], [8], [9], [10], [11], [12]]
   - visited = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]

2. Step-by-step execution with intermediate values:
   - Call DFSUtil for node 0:
     - visited = [true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
     - Visit node 1:
       - visited = [true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
       - Visit node 5:
         - visited = [true, true, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
         - Visit node 7:
           - visited = [true, true, false, false, false, true, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false]
           - Visit node 8:
             - visited = [true, true, false, false, false, true, false, true, true, false, false, false, false, false, false, false, false, false, false, false, false]
             - Visit node 2 (Cycle detected, as it was already visited and not parent)
             - Return true

3. Final output:
   - Graph contains cycle

Output:
Graph contains cycle
*/


