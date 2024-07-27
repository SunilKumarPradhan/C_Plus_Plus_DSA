#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // Remove this line if the graph is directed
}

bool BFS(vector<int> adj[], int src, int dest, int size, vector<int> &path) {
    vector<bool> visited(size, false);
    vector<int> parent(size, -1);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (auto i : adj[vertex]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = vertex;
                q.push(i);

                if (i == dest) {
                    int crawl = dest;
                    path.push_back(crawl);
                    while (parent[crawl] != -1) {
                        path.push_back(parent[crawl]);
                        crawl = parent[crawl];
                    }
                    reverse(path.begin(), path.end());
                    return true;
                }
            }
        }
    }

    return false;
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

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    int src = 2, dest = 4;
    vector<int> path;

    if (BFS(adj, src, dest, size, path)) {
        cout << "\nShortest path from " << src << " to " << dest << " is: ";
        for (int i : path)
            cout << i << " ";
        cout << endl;
    } else {
        cout << "\nNo path exists from " << src << " to " << dest << endl;
    }

    return 0;
}

/*
Iss function ka naam hai BFS aur yeh function breadth-first search use karke shortest path nikalta hai do nodes ke beech graph mein.

- Function ka logic:
  1. Har node ke liye ek visited array aur ek parent array maintain karte hain.
  2. BFS traversal mein queue ka use karte hain nodes ko visit karne ke liye.
  3. Jab destination node mil jata hai, tab parent array use karke path reconstruct karte hain.

Process:
- Pehle, ek visited array aur parent array banate hain aur source node ko queue mein push karte hain.
- BFS traversal mein, har node ke adjacent nodes ko visit karte hain agar wo pehle visit nahi hue.
- Jab destination node mil jata hai, tab parent array se path reconstruct karte hain aur reverse karke return karte hain.

Example:
- Agar example graph yeh hai:

0 -> 1, 0 -> 2, 0 -> 3, 1 -> 4, 1 -> 5, 2 -> 6, 2 -> 7, 3 -> 8, 3 -> 9, 4 -> 6, 5 -> 7, 6 -> 8, 7 -> 9

Adjacency List:
0: 1 2 3 
1: 4 5 
2: 6 7 
3: 8 9 
4: 6 
5: 7 
6: 8 
7: 9 
8: 
9: 

Dry Run:
1. Initial setup and input:
   - Visited: [false, false, false, false, false, false, false, false, false, false]
   - Parent: [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]
   - Queue: [2]
2. Step-by-step execution with intermediate values:
   - Visit 2, Queue: []
     - Mark 2 as visited, Visited: [false, false, true, false, false, false, false, false, false, false]
     - Add 6 to queue, Parent: [-1, -1, -1, -1, -1, -1, 2, -1, -1, -1], Queue: [6]
     - Add 7 to queue, Parent: [-1, -1, -1, -1, -1, -1, 2, 2, -1, -1], Queue: [6, 7]
   - Visit 6, Queue: [7]
     - Mark 6 as visited, Visited: [false, false, true, false, false, false, true, false, false, false]
     - Add 8 to queue, Parent: [-1, -1, -1, -1, -1, -1, 2, 2, 6, -1], Queue: [7, 8]
   - Visit 7, Queue: [8]
     - Mark 7 as visited, Visited: [false, false, true, false, false, false, true, true, false, false]
     - Add 9 to queue, Parent: [-1, -1, -1, -1, -1, -1, 2, 2, 6, 7], Queue: [8, 9]
   - Visit 8, Queue: [9]
     - Mark 8 as visited, Visited: [false, false, true, false, false, false, true, true, true, false]
   - Visit 9, Queue: []
     - Mark 9 as visited, Visited: [false, false, true, false, false, false, true, true, true, true]
   - Visit 4, Queue: []
     - Mark 4 as visited, Visited: [false, false, true, false, true, false, true, true, true, true]
     - Path: 4 -> 1 -> 2

3. Final output:
   - Shortest path from 2 to 4: 2 1 4

Output:
Shortest path from 2 to 4 is: 2 1 4
*/




