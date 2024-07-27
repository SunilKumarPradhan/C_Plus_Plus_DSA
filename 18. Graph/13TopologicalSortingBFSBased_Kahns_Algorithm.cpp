#include <bits/stdc++.h>
using namespace std;



void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

vector<int> topologicalSortBFS(int size, vector<int> adj[]) {
    vector<int> in_degree(size, 0);

    for (int u = 0; u < size; u++) {
        for (int v : adj[u]) {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < size; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (int v : adj[u]) {
            if (--in_degree[v] == 0)
                q.push(v);
        }
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

     vector<int> result = topologicalSortBFS(size, adj);

    for (int v : result)
        cout << v << " ";
    cout << endl;

    return 0;
}


/*
Iss function ka naam hai topologicalSortBFS aur yeh graph ka topological sorting karta hai using Kahn's Algorithm.

- Function ka logic:
  1. Har node ka in-degree calculate karte hain, jo ki us node pe aane wale edges ka count hota hai.
  2. Phir sabhi nodes jinka in-degree 0 hai, unko ek queue mein daal dete hain.
  3. Queue se nodes nikal kar unko topological order mein daalte hain aur unke adjacent nodes ke in-degree ko reduce karte hain.
  4. Agar kisi adjacent node ka in-degree 0 ho jata hai, to usko queue mein daal dete hain.

Process:
- Pehle, har node ka in-degree calculate karte hain.
- Uske baad, in-degree 0 wale nodes ko queue mein daalte hain.
- Phir queue se nodes nikal kar unke adjacent nodes ke in-degree ko reduce karte hain aur agar in-degree 0 ho jaye to queue mein daalte hain.
- Yeh process tab tak repeat karte hain jab tak queue empty na ho jaye.

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

then 

- Topological sort result: 0 1 2 3 4 5 6 7 8 9

Dry Run:
1. Initial setup and input:
   - In-degree: [0, 1, 1, 1, 1, 1, 2, 2, 2, 2]
   - Queue: [0]
2. Step-by-step execution with intermediate values:
   - Pop 0, push 1, 2, 3 to queue, topological order: [0], in-degree: [0, 0, 0, 0, 1, 1, 2, 2, 2, 2]
   - Pop 1, push 4, 5 to queue, topological order: [0, 1], in-degree: [0, 0, 0, 0, 0, 0, 2, 2, 2, 2]
   - Pop 2, push 6, 7 to queue, topological order: [0, 1, 2], in-degree: [0, 0, 0, 0, 0, 0, 1, 1, 2, 2]
   - Pop 3, push 8, 9 to queue, topological order: [0, 1, 2, 3], in-degree: [0, 0, 0, 0, 0, 0, 1, 1, 1, 1]
   - Pop 4, push 6 to queue, topological order: [0, 1, 2, 3, 4], in-degree: [0, 0, 0, 0, 0, 0, 0, 1, 1, 1]
   - Pop 5, push 7 to queue, topological order: [0, 1, 2, 3, 4, 5], in-degree: [0, 0, 0, 0, 0, 0, 0, 0, 1, 1]
   - Pop 6, push 8 to queue, topological order: [0, 1, 2, 3, 4, 5, 6], in-degree: [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
   - Pop 7, push 9 to queue, topological order: [0, 1, 2, 3, 4, 5, 6, 7], in-degree: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
   - Pop 8, topological order: [0, 1, 2, 3, 4, 5, 6, 7, 8]
   - Pop 9, topological order: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
3. Final output:
   - Topological order: 0 1 2 3 4 5 6 7 8 9

Output:
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
*/

