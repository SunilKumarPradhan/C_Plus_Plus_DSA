#include <bits/stdc++.h>
using namespace std;



void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

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
Iss function ka naam hai isCyclicKahn aur yeh graph mein cycle ko detect karta hai using Kahn's Algorithm for Topological Sorting.

- Function ka logic:
  1. Pehle har node ka in-degree calculate kiya jata hai, jo ki incoming edges ka count hota hai.
  2. Phir in-degree 0 wale nodes ko ek queue mein push kiya jata hai.
  3. Queue se nodes ko nikaal kar unke neighbors ke in-degree ko decrease kiya jata hai.
  4. Agar kisi neighbor ka in-degree 0 ho jata hai, toh usse queue mein push kiya jata hai.
  5. Yeh process tab tak repeat hota hai jab tak queue empty nahi ho jati.
  6. Agar processed nodes ka count graph ke nodes ke count ke barabar nahi hai, toh graph mein cycle hai.

Process:
- Pehle, in-degree array create karke har node ka in-degree calculate kiya jata hai.
- Phir in-degree 0 wale nodes ko queue mein push kiya jata hai.
- Queue se nodes ko nikaal kar unke neighbors ke in-degree ko decrease kiya jata hai aur agar in-degree 0 ho jata hai toh queue mein push kiya jata hai.
- Agar processed nodes ka count graph ke nodes ke count ke barabar nahi hai, toh graph mein cycle hai.

Example:
- Agar graph ka example hai:

0 -> 1 -> 4 -> 6
|    |    |  
2 -> 3 -> 5 
     |    |   
     7 -> 8 -> 9

then

Adjacency List Representation:
0: 1 2 3 
1: 4 5 
2: 6 7 
3: 8 
4: 6 
5: 7 
6: 8 
7: 9 

- `isCyclicKahn` function ko call karte hai jo graph mein cycle detect karta hai aur result print karta hai.

Dry Run:
1. Initial setup and input:
    - Size: 10
    - Adjacency list: [ [1, 2, 3], [4, 5], [6, 7], [8], [6], [7], [8], [9], [], [] ]
    - In-degree array: [0, 1, 1, 1, 1, 1, 2, 2, 2, 1]
    - Start node: Nodes with in-degree 0 -> 0

2. Step-by-step execution:
    - Start from node 0 -> in-degree array: [0, 0, 0, 0, 0, 1, 1, 2, 2, 1] -> queue: [1, 2, 3]
    - Process node 1 -> in-degree array: [0, 0, 0, 0, 0, 0, 1, 2, 2, 1] -> queue: [2, 3, 4]
    - Process node 2 -> in-degree array: [0, 0, 0, 0, 0, 0, 0, 2, 2, 1] -> queue: [3, 4, 5, 6]
    - Process node 3 -> in-degree array: [0, 0, 0, 0, 0, 0, 0, 2, 1, 1] -> queue: [4, 5, 6, 8]
    - Process node 4 -> in-degree array: [0, 0, 0, 0, 0, 0, 0, 2, 0, 1] -> queue: [5, 6, 8, 9]
    - Process node 5 -> in-degree array: [0, 0, 0, 0, 0, 0, 0, 1, 0, 1] -> queue: [6, 8, 9]
    - Process node 6 -> in-degree array: [0, 0, 0, 0, 0, 0, 0, 1, 0, 0] -> queue: [8, 9]
    - Process node 8 -> in-degree array: [0, 0, 0, 0, 0, 0, 0, 1, 0, 0] -> queue: [9]
    - Process node 9 -> in-degree array: [0, 0, 0, 0, 0, 0, 0, 1, 0, 0] -> queue: []

3. Final output:
    - Graph doesn't contain cycle

Output:
Graph doesn't contain cycle
*/
