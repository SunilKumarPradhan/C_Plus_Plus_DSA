#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void DFS(vector<int> adj[], int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            DFS(adj, i, visited, Stack);
    Stack.push(v);
}

void fillOrder(vector<int> adj[], int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            fillOrder(adj, i, visited, Stack);
    Stack.push(v);
}

void DFSUtil(vector<int> adj[], int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";
    for (int i : adj[v])
        if (!visited[i])
            DFSUtil(adj, i, visited);
}

void findSCCs(vector<int> adj[], int size) {
    stack<int> Stack;
    vector<bool> visited(size, false);

    for (int i = 0; i < size; i++)
        if (!visited[i])
            fillOrder(adj, i, visited, Stack);

    vector<int> transpose[size];
    for (int v = 0; v < size; v++) {
        for (int i : adj[v])
            transpose[i].push_back(v);
    }

    fill(visited.begin(), visited.end(), false);

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            DFSUtil(transpose, v, visited);
            cout << endl;
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

    cout << "\nStrongly Connected Components:\n";
    findSCCs(adj, size);

    return 0;
}


/*
Iss function ka naam hai findSCCs aur yeh function Tarjan's Algorithm use karke graph ke Strongly Connected Components (SCCs) ko identify karta hai.

- Function ka logic:
  1. Ek stack maintain karte hain jo nodes ko fillOrder ke through visit karne ke baad push karta hai.
  2. Graph ka transpose create karte hain taaki edges reverse ho jayein.
  3. Transpose graph pe DFSUtil use karke SCCs ko identify karte hain.

Process:
- Pehle, sab nodes ko stack mein fillOrder function se push karte hain.
- Phir graph ka transpose banate hain jahan har edge ko reverse kar dete hain.
- Stack se nodes ko nikalte hain aur unpe DFSUtil call karke SCCs ko print karte hain.

Example:
- Agar example graph yeh hai:

Adjacency List:
0: 1 2 3 
1: 4 5 
2: 6 7 
3: 8 9 
4: 6 
5: 7 
6: 8 
7: 9 

Dry Run:
1. Initial setup and input:
   - Stack: []
   - Visited: [false, false, false, false, false, false, false, false, false, false]

2. Step-by-step execution with intermediate values:
   - Call fillOrder for node 0:
     - Visit node 0, push to Stack
     - Visit adjacent nodes 1, 2, 3
     - Continue fillOrder for nodes 1, 2, 3 similarly
     - Stack: [4, 6, 1, 5, 7, 2, 8, 9, 3, 0]

   - Create transpose graph:
     - Transpose:
       0: 
       1: 0
       2: 0
       3: 0
       4: 1
       5: 1
       6: 2 4
       7: 2 5
       8: 3 6
       9: 3 7

   - Call DFSUtil for nodes from stack:
     - Pop node 0, call DFSUtil
       - Visit nodes in SCC: 0
     - Pop node 3, call DFSUtil
       - Visit nodes in SCC: 3
     - Pop node 9, call DFSUtil
       - Visit nodes in SCC: 9
     - Pop node 8, call DFSUtil
       - Visit nodes in SCC: 8
     - Pop node 2, call DFSUtil
       - Visit nodes in SCC: 2
     - Pop node 7, call DFSUtil
       - Visit nodes in SCC: 7
     - Pop node 5, call DFSUtil
       - Visit nodes in SCC: 5
     - Pop node 1, call DFSUtil
       - Visit nodes in SCC: 1
     - Pop node 6, call DFSUtil
       - Visit nodes in SCC: 6
     - Pop node 4, call DFSUtil
       - Visit nodes in SCC: 4

3. Final output:
   - Strongly Connected Components:
     0
     1
     2
     3
     4
     5
     6
     7
     8
     9

Output:
Strongly Connected Components:
0 
1 
2 
3 
4 
5 
6 
7 
8 
9
*/
