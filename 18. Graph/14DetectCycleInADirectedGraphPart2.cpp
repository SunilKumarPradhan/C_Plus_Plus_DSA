#include <bits/stdc++.h>
using namespace std;

bool isCyclicKahn(int size, vector<int> adj[]) {
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

    int cnt = 0;
    vector<int> top_order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (int v : adj[u]) {
            if (--in_degree[v] == 0)
                q.push(v);
        }

        cnt++;
    }

    return (cnt != size);
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

    if (isCyclicKahn(size, adj))
        cout << "Graph contains cycle" << endl;
    else
        cout << "Graph doesn't contain cycle" << endl;


    
    return 0;
}

/*
Iss function ka naam hai isCyclicKahn aur yeh function check karta hai agar given graph cyclic hai ya nahi using Kahn's Algorithm.

- Function ka logic:
  1. Har node ka in-degree calculate karte hain, jo ki us node pe aane wale edges ka count hota hai.
  2. Phir sabhi nodes jinka in-degree 0 hai, unko ek queue mein daal dete hain.
  3. Queue se nodes nikal kar unko topological order mein daalte hain aur unke adjacent nodes ke in-degree ko reduce karte hain.
  4. Agar kisi adjacent node ka in-degree 0 ho jata hai, to usko queue mein daal dete hain.
  5. Graph cyclic tab hota hai jab humare topological sort mein saari nodes na aayein (cnt != size).

Process:
- Pehle, har node ka in-degree calculate karte hain.
- Uske baad, in-degree 0 wale nodes ko queue mein daalte hain.
- Phir queue se nodes nikal kar unke adjacent nodes ke in-degree ko reduce karte hain aur agar in-degree 0 ho jaye to queue mein daalte hain.
- Yeh process tab tak repeat karte hain jab tak queue empty na ho jaye.
- Agar cnt, size ke barabar nahi hai, to graph cyclic hai.

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
   - In-degree: [0, 1, 1, 1, 1, 1, 2, 2, 2, 2]
   - Queue: [0]
2. Step-by-step execution with intermediate values:
   - Pop 0, push 1, 2, 3 to queue, in-degree: [0, 0, 0, 0, 1, 1, 2, 2, 2, 2], cnt: 1
   - Pop 1, push 4, 5 to queue, in-degree: [0, 0, 0, 0, 0, 0, 2, 2, 2, 2], cnt: 2
   - Pop 2, push 6, 7 to queue, in-degree: [0, 0, 0, 0, 0, 0, 1, 1, 2, 2], cnt: 3
   - Pop 3, push 8, 9 to queue, in-degree: [0, 0, 0, 0, 0, 0, 1, 1, 1, 1], cnt: 4
   - Pop 4, push 6 to queue, in-degree: [0, 0, 0, 0, 0, 0, 0, 1, 1, 1], cnt: 5
   - Pop 5, push 7 to queue, in-degree: [0, 0, 0, 0, 0, 0, 0, 0, 1, 1], cnt: 6
   - Pop 6, push 8 to queue, in-degree: [0, 0, 0, 0, 0, 0, 0, 0, 0, 1], cnt: 7
   - Pop 7, push 9 to queue, in-degree: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], cnt: 8
   - Pop 8, cnt: 9
   - Pop 9, cnt: 10
3. Final output:
   - cnt = size, so graph doesn't contain cycle

Output:
Graph doesn't contain cycle
*/

