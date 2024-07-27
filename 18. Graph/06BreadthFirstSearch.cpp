#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // Remove this line if the graph is directed
}

void BFS(vector<int> adj[], int start, int size) {
    vector<bool> visited(size, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();

        for (auto i : adj[vertex]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


int main() {
    int size = 5;  
    vector<int> adj[size];

    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 0);

    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    cout << "\nBFS starting from vertex 2:\n";
    BFS(adj, 2, size);


    return 0;
}



/*
Iss function ka naam hai BFS aur yeh graph ko Breadth First Search (BFS) algorithm se traverse karta hai.

- Function ka logic:
  1. `BFS` function ko adjacency list, start vertex, aur graph ke size diya jata hai.
  2. `BFS` function ek visited array aur ek queue create karta hai.
  3. Start vertex ko visited mark karta hai aur queue mein push karta hai.
  4. Jab tak queue khali nahi hoti, har vertex ko dequeue karta hai aur uske adjacent vertices ko queue mein dalta hai agar woh visited nahi hai.

Process:
- Pehle, `BFS` function ek visited array create karta hai aur usse false se initialize karta hai.
- Start vertex ko visited mark karta hai aur queue mein push karta hai.
- Queue mein se har vertex ko nikalta hai aur uske adjacent vertices ko check karta hai agar woh visited nahi hai toh unhe queue mein dalta hai aur visited mark karta hai.

Example:
- Agar graph ka example hai:

0 -- 1
     |
2 -- 3
|
4

then

Adjacency List Representation:
0: 1 
1: 0 
2: 3 4 
3: 2 
4: 2 

- `BFS` function ko call karte hai jo har vertex ko visit karta hai aur result print karta hai.

Dry Run:
1. Initial setup and input:
    - Visited array: [false, false, false, false, false]
    - Adjacency list: [ [1], [0], [3, 4], [2], [2] ]
    - Start vertex: 2

2. Step-by-step execution:
    - `BFS` starts from vertex 2:
        - Visit 2 -> queue: [2], visited: [false, false, true, false, false]
        - Dequeue 2 -> visit 3 -> queue: [3], visited: [false, false, true, true, false]
        - Enqueue 4 -> queue: [3, 4], visited: [false, false, true, true, true]
        - Dequeue 3 -> no new vertices -> queue: [4]
        - Dequeue 4 -> no new vertices -> queue: []

3. Final output:
    - BFS traversal starting from vertex 2: 2 3 4

Output:
BFS traversal starting from vertex 2: 2 3 4
*/
