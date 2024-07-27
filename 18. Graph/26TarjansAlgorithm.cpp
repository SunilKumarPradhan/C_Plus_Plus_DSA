#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void tarjanDFS(int u, vector<int>& disc, vector<int>& low, stack<int>& stk, vector<bool>& inStack, vector<int> adj[], vector<vector<int>>& SCCs) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    stk.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v, disc, low, stk, inStack, adj, SCCs);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        vector<int> component;
        int w;
        do {
            w = stk.top();
            stk.pop();
            inStack[w] = false;
            component.push_back(w);
        } while (w != u);
        SCCs.push_back(component);
    }
}

vector<vector<int>> tarjan(vector<int> adj[], int V) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> stk;
    vector<vector<int>> SCCs;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            tarjanDFS(i, disc, low, stk, inStack, adj, SCCs);
        }
    }

    return SCCs;
}

int main() {
    int size = 10;
    vector<int> adj[size];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    addEdge(adj, 6, 5);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 6);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        for (auto j : adj[i])
            cout << j << " ";
        cout << endl;
    }

    vector<vector<int>> SCCs = tarjan(adj, size);

    cout << "\nStrongly Connected Components:" << endl;
    for (const auto& component : SCCs) {
        for (int v : component) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
Iss function ka naam hai tarjan aur yeh function Tarjan's algorithm use karke graph ke Strongly Connected Components (SCCs) find karta hai.

- Function ka logic:
  1. DFS traversal karte hain, har node ko discovery time aur lowest discovery time assign karte hain.
  2. Agar ek node ka lowest discovery time apne discovery time ke barabar ho toh yeh ek SCC ka head node hota hai.
  3. Stack ka use karke SCCs ko detect karte hain.

Process:
- Pehle, har node ka discovery time aur low value initialize karte hain (-1 se).
- DFS traversal mein nodes ko visit karte hain aur stack mein daalte hain jab tak ek SCC ka head detect na ho.
- Agar ek SCC detect ho jaye, toh us SCC ke sabhi nodes ko stack se nikaal kar ek SCC component mein daalte hain.

Example:
- Agar example graph yeh hai:

Adjacency List:
0: 1
1: 2 3
2: 0
3: 4
4: 5
5: 3
6: 5 7
7: 8
8: 9
9: 6

Dry Run:
1. Initial setup and input:
   - Adjacency list representation as given above.
   - Source: Start from node 0

2. Step-by-step execution with intermediate values:
   - Starting from node 0:
     - Node 0 -> Disc = 1, Low = 1
     - Node 1 -> Disc = 2, Low = 2
     - Node 2 -> Disc = 3, Low = 3
     - Back to Node 0 -> Update Low[2] = min(Low[2], Disc[0]) => Low[2] = 1
     - Back to Node 1 -> Update Low[1] = min(Low[1], Low[2]) => Low[1] = 1
     - Back to Node 0 -> Update Low[0] = min(Low[0], Low[1]) => Low[0] = 1
     - Detected SCC: {0, 2, 1}

   - Continue for remaining nodes:
     - Node 3 -> Disc = 4, Low = 4
     - Node 4 -> Disc = 5, Low = 5
     - Node 5 -> Disc = 6, Low = 6
     - Back to Node 3 -> Update Low[3] = min(Low[3], Low[5]) => Low[3] = 4
     - Detected SCC: {3, 5, 4}

   - Continue for remaining nodes:
     - Node 6 -> Disc = 7, Low = 7
     - Node 7 -> Disc = 8, Low = 8
     - Node 8 -> Disc = 9, Low = 9
     - Node 9 -> Disc = 10, Low = 10
     - Back to Node 6 -> Update Low[9] = min(Low[9], Low[6]) => Low[9] = 7
     - Detected SCC: {6, 9, 8, 7}

3. Final output:
   - SCCs detected: 
     {5, 4, 3}
     {2, 1, 0}
     {9, 8, 7, 6}

Output:
Strongly Connected Components:
5 4 3
2 1 0
9 8 7 6
*/

