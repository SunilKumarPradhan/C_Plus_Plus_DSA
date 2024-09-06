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
        int curr = q.front();
        cout << curr << " ";
        q.pop();

        for (auto i : adj[curr]) {
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
Iss function ka naam hai BFS aur yeh function breadth-first search traversal karta hai ek graph ka starting from a given vertex.

- Function ka logic:
  1. Pehle ek visited vector banate hain, jismein saare nodes initially unvisited (false) hote hain.
  2. Ek queue initialize karte hain aur starting node ko visit karte hain aur queue mein push karte hain.
  3. Jab tak queue khali nahi ho jata, tab tak front node ko nikalte hain, usko print karte hain, aur uske adjacent nodes ko check karte hain.
  4. Agar koi adjacent node unvisited hai, to usko visit karte hain aur queue mein push karte hain.

Process:
- Pehle, visited vector aur queue initialize hoti hai.
- Uske baad, starting node visit hota hai aur queue mein push hota hai.
- Har iteration mein, front node nikalta hai aur uske saare adjacent nodes check hote hain.
- Unvisited adjacent nodes ko visit karte hain aur queue mein push karte hain.
- Yeh process tab tak repeat hota hai jab tak queue khali nahi ho jati.

Example:
- Agar yeh graph hai:
  0 - 1
  2 - 3
  | 
  4

then
adjacency list representation:
0: 1
1: 0
2: 3 4
3: 2
4: 2

then 
- BFS starting from vertex 2:

Three Iterations:
- Iteration 1:
  Queue: [2]
  Output: 2
  Queue after processing 2: [3, 4]

- Iteration 2:
  Queue: [3, 4]
  Output: 2 3
  Queue after processing 3: [4]

- Iteration 3:
  Queue: [4]
  Output: 2 3 4
  Queue after processing 4: []

Dry Run:
1. Initial setup and input:
   - size = 5
   - adj = [[1], [0], [3, 4], [2], [2]]
   - start = 2

2. Step-by-step execution with intermediate values:
   - visited = [false, false, true, false, false]
   - Queue: [2]
   - Output: 2
   - Queue after processing 2: [3, 4]
   - visited = [false, false, true, true, true]

   - Queue: [3, 4]
   - Output: 2 3
   - Queue after processing 3: [4]
   - visited = [false, false, true, true, true]

   - Queue: [4]
   - Output: 2 3 4
   - Queue after processing 4: []
   - visited = [false, false, true, true, true]

3. Final output:
   - 2 3 4

Output:
2 3 4
*/

