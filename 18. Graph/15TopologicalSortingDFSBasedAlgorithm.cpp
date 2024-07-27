#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

    void topologicalSortDFSUtil(int v, vector<int> adj[], vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i])
            topologicalSortDFSUtil(i, adj, visited, Stack);
    }

    Stack.push(v);
}

vector<int> topologicalSortDFS(int size, vector<int> adj[]) {
    stack<int> Stack;
    vector<bool> visited(size, false);

    for (int i = 0; i < size; i++) {
        if (!visited[i])
            topologicalSortDFSUtil(i, adj, visited, Stack);
    }

    vector<int> top_order;
    while (!Stack.empty()) {
        top_order.push_back(Stack.top());
        Stack.pop();
    }

    return top_order;
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

    vector<int> result = topologicalSortDFS(size, adj);

    for (int v : result)
        cout << v << " ";
    cout << endl;

    return 0;
}

/*
Iss function ka naam hai topologicalSortDFS aur yeh function topological sorting karta hai graph ka using Depth-First Search (DFS).

- Function ka logic:
  1. Har node ko visit karne ke liye DFS ka use karte hain.
  2. Jab ek node ka saare adjacent nodes visit ho jate hain, tab us node ko stack mein push kar dete hain.
  3. End mein stack ko pop karke topological order nikalte hain.

Process:
- Pehle, ek visited array aur ek stack banate hain.
- Har node ke liye, agar wo visited nahi hai to DFS call karte hain.
- DFS call mein, node ko visit karke uske saare adjacent nodes ko visit karte hain.
- Jab saare adjacent nodes visit ho jate hain to current node ko stack mein push karte hain.
- Stack ko pop karke topological order nikalte hain.

Example:
- Agar example graph yeh hai:

0 -> 1, 0 -> 2, 0 -> 3, 1 -> 4, 1 -> 5, 2 -> 6, 2 -> 7, 3 -> 8, 3 -> 9, 4 -> 6, 5 -> 7, 6 -> 8, 7 -> 9

then

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
   - Stack: []
2. Step-by-step execution with intermediate values:
   - Call DFS for node 0: 
     - Visit 0, Stack: []
     - Call DFS for node 1: 
       - Visit 1, Stack: []
       - Call DFS for node 4: 
         - Visit 4, Stack: []
         - Call DFS for node 6: 
           - Visit 6, Stack: []
           - Call DFS for node 8: 
             - Visit 8, Stack: []
             - Push 8 to Stack, Stack: [8]
           - Push 6 to Stack, Stack: [8, 6]
         - Push 4 to Stack, Stack: [8, 6, 4]
       - Call DFS for node 5: 
         - Visit 5, Stack: [8, 6, 4]
         - Call DFS for node 7: 
           - Visit 7, Stack: [8, 6, 4]
           - Call DFS for node 9: 
             - Visit 9, Stack: [8, 6, 4]
             - Push 9 to Stack, Stack: [8, 6, 4, 9]
           - Push 7 to Stack, Stack: [8, 6, 4, 9, 7]
         - Push 5 to Stack, Stack: [8, 6, 4, 9, 7, 5]
       - Push 1 to Stack, Stack: [8, 6, 4, 9, 7, 5, 1]
     - Call DFS for node 2: 
       - Visit 2, Stack: [8, 6, 4, 9, 7, 5, 1]
       - Call DFS for node 6 (already visited)
       - Call DFS for node 7 (already visited)
       - Push 2 to Stack, Stack: [8, 6, 4, 9, 7, 5, 1, 2]
     - Call DFS for node 3: 
       - Visit 3, Stack: [8, 6, 4, 9, 7, 5, 1, 2]
       - Call DFS for node 8 (already visited)
       - Call DFS for node 9 (already visited)
       - Push 3 to Stack, Stack: [8, 6, 4, 9, 7, 5, 1, 2, 3]
     - Push 0 to Stack, Stack: [8, 6, 4, 9, 7, 5, 1, 2, 3, 0]
3. Final output:
   - Topological Order: 0 3 2 1 5 7 9 4 6 8

Output:
Topological Order: 0 3 2 1 5 7 9 4 6 8
*/


