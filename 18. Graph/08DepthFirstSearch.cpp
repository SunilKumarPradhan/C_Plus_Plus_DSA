#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

void DFSUtil(int v, vector<int> adj[], vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
}

void DFS(vector<int> adj[], int V) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
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

    cout << "\nDepth First Search starting from vertex 0:" << endl;
    DFS(adj, size);

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

void DFS(vector<int> adj[], int V, int start = 0) {
    vector<bool> visited(V, false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;

            for (int i = adj[v].size() - 1; i >= 0; i--) {
                if (!visited[adj[v][i]]) {
                    s.push(adj[v][i]);
                }
            }
        }
    }
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

    cout << "\nDepth First Search starting from vertex 0:" << endl;
    DFS(adj, size);

    return 0;
}

Advantages of the iterative approach:

- Stack safety: It avoids potential stack overflow errors that can occur with deep recursion 
    in very large graphs. This is particularly important for large or unbalanced graphs.

- Performance: It's often faster due to less function call overhead. 
    Each recursive call in the original version adds a new frame to the call stack, which can be costly.

- Memory efficiency: It uses a fixed amount of additional memory 
    (the stack and visited array), regardless of the depth of the graph.

- Flexibility: It's easier to modify if you need to do something more complex during the traversal, 
    like keeping track of path information or implementing a non-recursive backtracking algorithm.

- Easier debugging: Iterative algorithms are often easier to debug as you can more easily inspect the 
    state at each step.

However, the recursive approach (the one in your prompt) has some advantages too:

 - Simplicity: It's often more intuitive and easier to understand at a glance, especially 
    for those new to graph algorithms.
 
 - Closer to mathematical definition: The recursive approach more closely mirrors the 
    mathematical definition of DFS, which is inherently recursive.
 
 - Easier to implement: For simple cases, the recursive approach requires less code and is quicker to write.

*/




/*
Iss function ka naam hai DFS aur yeh graph ko Depth First Search (DFS) algorithm se traverse karta hai.

- Function ka logic:
  1. `DFS` function ko adjacency list aur vertices count diya jata hai.
  2. `DFS` function sabhi vertices ke liye check karta hai aur agar vertex visited nahi hai toh `DFSUtil` ko call karta hai.
  3. `DFSUtil` function current vertex ko visit karta hai aur recursively sabhi adjacent vertices ko visit karta hai jo visited nahi hai.

Process:
- Pehle, `DFS` function ek visited array create karta hai aur usse false se initialize karta hai.
- Uske baad, har vertex ke liye check karta hai agar woh visited nahi hai toh `DFSUtil` call karta hai.
- `DFSUtil` function current vertex ko visit karta hai aur uske sabhi adjacent vertices ko recursively visit karta hai.

Example:
- Agar graph ka example hai:

0 -- 1
| \  |
|  \ |
2   3
|   | \
6 -- 8 9
| / | / 
4 -- 7
    |
    5

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

- `DFS` function ko call karte hai jo har vertex ko visit karta hai aur result print karta hai.

Dry Run:
1. Initial setup and input:
    - Visited array: [false, false, false, false, false, false, false, false, false, false]
    - Adjacency list: [ [1, 2, 3], [0, 4, 5], [0, 6, 7], [0, 8, 9], [1, 6], [1, 7], [2, 4, 8], [2, 5, 9], [3, 6], [3, 7] ]

2. Step-by-step execution:
    - `DFS` starts from vertex 0:
        - `DFSUtil(0)` -> visit 0 -> [true, false, false, false, false, false, false, false, false, false]
            - visit 1 -> `DFSUtil(1)` -> [true, true, false, false, false, false, false, false, false, false]
                - visit 4 -> `DFSUtil(4)` -> [true, true, false, false, true, false, false, false, false, false]
                    - visit 6 -> `DFSUtil(6)` -> [true, true, false, false, true, false, true, false, false, false]
                        - visit 8 -> `DFSUtil(8)` -> [true, true, false, false, true, false, true, false, true, false]
                        - return to 6
                    - return to 4
                - visit 5 -> `DFSUtil(5)` -> [true, true, false, false, true, true, true, false, true, false]
                    - visit 7 -> `DFSUtil(7)` -> [true, true, false, false, true, true, true, true, true, false]
                        - visit 9 -> `DFSUtil(9)` -> [true, true, false, false, true, true, true, true, true, true]
                        - return to 7
                    - return to 5
                - return to 1
            - return to 0
            - visit 2 -> `DFSUtil(2)` -> [true, true, true, false, true, true, true, true, true, true]
                - visit 6 already visited
                - visit 7 already visited
            - return to 2
            - visit 3 -> `DFSUtil(3)` -> [true, true, true, true, true, true, true, true, true, true]
                - visit 8 already visited
                - visit 9 already visited
            - return to 3

3. Final output:
    - DFS traversal starting from vertex 0: 0 1 4 6 8 5 7 9 2 3

Output:
DFS traversal starting from vertex 0: 0 1 4 6 8 5 7 9 2 3
*/
