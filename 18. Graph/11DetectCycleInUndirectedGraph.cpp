// #include <bits/stdc++.h>
// using namespace std;

// void addEdge(vector<int> adj[], int u, int v) {
//     adj[u].push_back(v);
//     adj[v].push_back(u);  
// }


// bool DFSUtil(int v, vector<int> adj[], vector<bool> &visited, int parent) {
//     visited[v] = true;
//     for (int i : adj[v]) {
//         if (!visited[i]) {
//             if (DFSUtil(i, adj, visited, v))
//                 return true;
//         } else if (i != parent) {
//             return true;
//         }
//     }
//     return false;
// }

// bool isCyclic(vector<int> adj[], int size) {
//     vector<bool> visited(size, false);

//     for (int i = 0; i < size; i++) {
//         if (!visited[i]) {
//             if (DFSUtil(i, adj, visited, -1))
//                 return true;
//         }
//     }
//     return false;
// }

/*
Explanation in Hinglish:

Iss function ka naam hai DFSUtil aur yeh depth-first search (DFS) algorithm use karta hai cycle detect karne ke liye graph mein.

- Function ka logic:
  1. visited[v] = true: Yeh line current node ko visited mark kar deti hai.
  2. for (int i : adj[v]): Yeh loop current node ke sabhi neighbors ko iterate karta hai.
  3. if (!visited[i]): Agar neighbor node visited nahi hai, toh DFSUtil function ko recursively call kiya jata hai.
  4. if (DFSUtil(i, adj, visited, v)): Agar recursive call cycle detect karti hai, toh function true return karta hai.
  5. else if (i != parent): Agar neighbor node visited hai aur yeh parent node nahi hai, toh cycle detected hai aur function true return karta hai.
  6. return false: Agar koi cycle detect nahi hoti, toh function false return karta hai.

Process:
- Pehle, current node ko visited mark karte hain.
- Uske baad, sabhi neighbors ko check karte hain.
- Agar neighbor node visited nahi hai, toh recursively call karte hain.
- Agar neighbor node visited hai aur parent node nahi hai, toh cycle detected hoti hai.
- Agar koi cycle nahi milti, toh function false return karta hai.

Example:
- Agar graph hai:

  0 - 1
  |   |
  2 - 3

- DFSUtil function 0 se start karta hai, aur neighbors 1 aur 2 ko check karta hai.
- 1 aur 2 ko recursively check karta hai, aur cycle detect karta hai (0-1-3-2-0).

Dry Run:
1. Initial setup:
   - Graph: 0 - 1, 0 - 2, 1 - 3, 2 - 3
   - visited array: [false, false, false, false]
   - parent: -1 (initially)
2. Process node 0:
   - visited[0] = true
   - Check neighbors 1 aur 2
3. Process node 1 (neighbor of 0):
   - visited[1] = true
   - Check neighbors 0 aur 3
   - Skip 0 (parent node)
4. Process node 3 (neighbor of 1):
   - visited[3] = true
   - Check neighbors 1 aur 2
   - Skip 1 (parent node)
5. Process node 2 (neighbor of 3):
   - visited[2] = true
   - Check neighbors 0 aur 3
   - Cycle detected with 0, 1, 3, 2, 0
6. Output:
   - true (cycle detected)

Output:
true (agar cycle detected ho)
false (agar cycle na ho)
*/

// bool DFSUtil(int v, vector<int> adj[], vector<bool> &visited, int parent) {
//     visited[v] = true;
//     for (int i : adj[v]) {
//         if (!visited[i]) {
//             if (DFSUtil(i, adj, visited, v))
//                 return true;
//         } else if (i != parent) {
//             return true;
//         }
//     }
//     return false;
// }

/*
Iss function ka naam hai isCyclic aur yeh graph mein cycle detect karta hai.

- Function ka logic:
  1. visited array initialize karta hai with false values.
  2. Sabhi nodes ko iterate karta hai aur agar node visited nahi hai, toh DFSUtil function ko call karta hai.
  3. Agar DFSUtil function true return karta hai, toh cycle detected hai aur isCyclic function true return karta hai.
  4. Agar koi cycle detect nahi hoti, toh isCyclic function false return karta hai.

Process:
- Pehle, visited array initialize karte hain.
- Har node ko check karte hain agar visited nahi hai.
- DFSUtil function ko call karte hain aur result check karte hain.
- Agar cycle detected hoti hai, toh true return karte hain.
- Agar cycle detect nahi hoti, toh false return karte hain.

Example:
- Agar graph hai:

  0 - 1
  |   |
  2 - 3

- isCyclic function 0 se start karta hai, aur DFSUtil function ko call karta hai.
- DFSUtil function cycle detect karta hai (0-1-3-2-0) aur true return karta hai.

Dry Run:
1. Initial setup:
   - Graph: 0 - 1, 0 - 2, 1 - 3, 2 - 3
   - visited array: [false, false, false, false]
2. Process node 0:
   - visited[0] = true
   - Call DFSUtil(0, adj, visited, -1)
3. DFSUtil function detects cycle
4. isCyclic function returns true

Output:
true (agar cycle detected ho)
false (agar cycle na ho)
*/

// bool isCyclic(vector<int> adj[], int size) {
//     vector<bool> visited(size, false);
    
//     for (int i = 0; i < size; i++) {
//         if (!visited[i]) {
//             if (DFSUtil(i, adj, visited, -1))
//                 return true;
//         }
//     }
//     return false;
// }


// int main() {
//     int size = 21;  // Increased size to accommodate more nodes
//     vector<int> adj[size];

//     // Level 0 to Level 1
//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 2);
//     addEdge(adj, 0, 3);
//     addEdge(adj, 0, 4);

//     // Level 1 to Level 2
//     addEdge(adj, 1, 5);
//     addEdge(adj, 1, 6);
//     addEdge(adj, 2, 7);
//     addEdge(adj, 2, 8);
//     addEdge(adj, 3, 9);
//     addEdge(adj, 3, 10);
//     addEdge(adj, 4, 11);
//     addEdge(adj, 4, 12);

//     // Level 2 to Level 3
//     addEdge(adj, 5, 13);
//     addEdge(adj, 6, 14);
//     addEdge(adj, 7, 15);
//     addEdge(adj, 8, 16);
//     addEdge(adj, 9, 17);
//     addEdge(adj, 10, 18);
//     addEdge(adj, 11, 19);
//     addEdge(adj, 12, 20);

//     // Additional edges for complexity
//     addEdge(adj, 5, 7);
//     addEdge(adj, 6, 8);
//     addEdge(adj, 9, 11);
//     addEdge(adj, 10, 12);
//     addEdge(adj, 13, 15);
//     addEdge(adj, 14, 16);
//     addEdge(adj, 17, 19);
//     addEdge(adj, 18, 20);

//     cout << "Adjacency List Representation:" << endl;
//     for (int i = 0; i < size; ++i) {
//         cout << i << ": ";
//         for (auto j : adj[i])
//             cout << j << " ";
//         cout << endl;
//     }
    
//     if (isCyclic(adj, size))
//         cout << "Graph contains cycle" << endl;
//     else
//         cout << "Graph doesn't contain cycle" << endl;


//     return 0;
// }



/*
Iss function ka naam hai isCyclic aur yeh function graph mein cycle detect karta hai using Depth-First Search (DFS) algorithm.

- Function ka logic:
  1. DFSUtil function recursively call karta hai nodes ko aur check karta hai agar koi node dobara visit ho rahi hai.
  2. Agar koi node dobara visit hoti hai aur woh parent node nahi hai, toh cycle exist karti hai.
  3. isCyclic function har node ke liye DFSUtil call karta hai agar woh visited nahi hai.

Process:
- Pehle, visited vector initialize hota hai.
- Har node ke liye DFSUtil call hota hai agar woh visited nahi hai.
- DFSUtil function recursively nodes ko visit karta hai aur cycle check karta hai.

Example:
- Agar yeh graph hai:
  0 - 1 - 5
  |   |   |
  2 - 6 - 7
  |       |
  3 - 4 - 8

then
adjacency list representation:
0: 1 2 3 4
1: 0 5 6
2: 0 7 8
3: 0
4: 0
5: 1 6 7
6: 1 5 8
7: 2 5 8
8: 2 6 7

then
- Cycle detection using DFS:

Three Iterations:
- Iteration 1:
  Stack: [0]
  Output: 0
  visited = [true, false, false, false, false, false, false, false, false]
  Stack after processing 0: [1, 2, 3, 4]
  visited = [true, true, true, true, true, false, false, false, false]

- Iteration 2:
  Stack: [1, 2, 3, 4]
  Output: 0 1
  Stack after processing 1: [2, 3, 4, 5, 6]
  visited = [true, true, true, true, true, true, true, false, false]

- Iteration 3:
  Stack: [2, 3, 4, 5, 6]
  Output: 0 1 2
  Stack after processing 2: [3, 4, 5, 6, 7, 8]
  visited = [true, true, true, true, true, true, true, true, true]

Dry Run:
1. Initial setup and input:
   - size = 21
   - adj = [[1, 2, 3, 4], [0, 5, 6], [0, 7, 8], [0], [0], [1, 6, 7], [1, 5, 8], [2, 5, 8], [2, 6, 7], [3, 10, 11], [3], [3], [4], [5], [6], [7], [8], [9], [10], [11], [12]]
   - visited = [false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]

2. Step-by-step execution with intermediate values:
   - Call DFSUtil for node 0:
     - visited = [true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
     - Visit node 1:
       - visited = [true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
       - Visit node 5:
         - visited = [true, true, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false]
         - Visit node 7:
           - visited = [true, true, false, false, false, true, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false]
           - Visit node 8:
             - visited = [true, true, false, false, false, true, false, true, true, false, false, false, false, false, false, false, false, false, false, false, false]
             - Visit node 2 (Cycle detected, as it was already visited and not parent)
             - Return true

3. Final output:
   - Graph contains cycle

Output:
Graph contains cycle
*/

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  
}

bool isCyclic(vector<int> adj[], int size) {
    vector<bool> visited(size, false);
    vector<int> parent(size, -1); // To keep track of the parent node

    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (auto i : adj[curr]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        parent[i] = curr;
                        q.push(i);
                    } else if (parent[curr] != i) { // If the visited neighbor is not the parent, a cycle is detected
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int size = 10;  
    vector<int> adj[size];

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5},
        {2, 6}, {2, 7}, {3, 8}, {3, 9}, {4, 6},
        {5, 7}, {6, 8}, {7, 9}
    };

    for (auto edge : edges) {
        addEdge(adj, edge.first, edge.second);
    }

    cout << "Adjacency List Representation:" << endl;
    int i = 0;
    for (auto neighbors : adj) {
        cout << i++ << ": ";
        for (auto j : neighbors) cout << j << " ";
        cout << endl;
    }

    cout<<((isCyclic(adj, size)) ? "The graph contains a cycle.": "The graph does not contain a cycle."  )<<endl;
    
    return 0;
}

