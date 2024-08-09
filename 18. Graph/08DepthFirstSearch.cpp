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
Iss function ka naam hai DFS aur yeh function depth-first search traversal karta hai ek graph ka.

- Function ka logic:
  1. DFS function har vertex ke liye check karta hai agar woh visited nahi hai to DFSUtil ko call karta hai.
  2. DFSUtil function vertex ko visit karta hai aur uske saare adjacent vertices ko recursively visit karta hai agar woh visited nahi hain.

Process:
- Pehle, DFS function ek visited vector banata hai jo initially false hota hai.
- Har vertex ke liye check karta hai agar woh visited nahi hai to DFSUtil ko call karta hai.
- DFSUtil function vertex ko visit karta hai aur uske saare adjacent vertices ko recursively visit karta hai agar woh visited nahi hain.

Example:
- Agar yeh graph hai:
  0 - 1 - 4
  | \ |   |
  2 - 5 - 6
  |   |
  3   7

then
adjacency list representation:
0: 1 2 3
1: 0 4 5
2: 0 6 7
3: 0
4: 1 6
5: 1 7
6: 2 4
7: 2 5

then 
- DFS starting from vertex 0:

Three Iterations:
- Iteration 1:
  Stack: [0]
  Output: 0
  Stack after processing 0: [1, 2, 3]

- Iteration 2:
  Stack: [1, 2, 3]
  Output: 0 1
  Stack after processing 1: [2, 3, 4, 5]

- Iteration 3:
  Stack: [2, 3, 4, 5]
  Output: 0 1 4
  Stack after processing 4: [2, 3, 5, 6]

Dry Run:
1. Initial setup and input:
   - size = 10
   - adj = [[1, 2, 3], [0, 4, 5], [0, 6, 7], [0], [1, 6], [1, 7], [2, 4], [2, 5], [], []]

2. Step-by-step execution with intermediate values:
   - visited = [false, false, false, false, false, false, false, false, false, false]
   - Call DFSUtil for vertex 0:
     - visited = [true, false, false, false, false, false, false, false, false, false]
     - Output: 0
     - Process adjacent vertices 1, 2, 3
     - Call DFSUtil for vertex 1:
       - visited = [true, true, false, false, false, false, false, false, false, false]
       - Output: 0 1
       - Process adjacent vertices 0, 4, 5
       - Call DFSUtil for vertex 4:
         - visited = [true, true, false, false, true, false, false, false, false, false]
         - Output: 0 1 4
         - Process adjacent vertices 1, 6
         - Call DFSUtil for vertex 6:
           - visited = [true, true, false, false, true, false, true, false, false, false]
           - Output: 0 1 4 6
           - Process adjacent vertices 2, 4
           - Call DFSUtil for vertex 2:
             - visited = [true, true, true, false, true, false, true, false, false, false]
             - Output: 0 1 4 6 2
             - Process adjacent vertices 0, 6, 7
             - Call DFSUtil for vertex 7:
               - visited = [true, true, true, false, true, false, true, true, false, false]
               - Output: 0 1 4 6 2 7
               - Process adjacent vertices 2, 5
               - Call DFSUtil for vertex 5:
                 - visited = [true, true, true, false, true, true, true, true, false, false]
                 - Output: 0 1 4 6 2 7 5
                 - Process adjacent vertices 1, 7
                 - Call DFSUtil for vertex 3:
                   - visited = [true, true, true, true, true, true, true, true, false, false]
                   - Output: 0 1 4 6 2 7 5 3

3. Final output:
   - 0 1 4 6 2 7 5 3

Output:
0 1 4 6 2 7 5 3
*/






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
*/

/*
Iss function ka naam hai DFS aur yeh depth-first search traversal implement karta hai using iterative approach with stack.

- Function ka logic:
  1. Ek vector visited nodes ko track karta hai.
  2. Ek stack traversal order ko maintain karta hai.
  3. Start node ko stack mein push karte hain aur jab tak stack empty na ho, nodes ko pop karke unke adjacent nodes ko stack mein push karte hain agar woh visited nahi hain.

Process:
- Pehle, visited vector initialize hota hai aur start node ko stack mein push karte hain.
- Jab tak stack empty na ho, top node ko pop karke visit karte hain aur uske adjacent nodes ko stack mein push karte hain agar woh visited nahi hain.

Example:
- Agar yeh graph hai:
  0 - 1 - 5
  |   |   |
  2 - 6 - 7
  |       |
  3 - 4 - 8

then
adjacency list representation:
0: 1 2 3
1: 0 4 5
2: 0 6 7
3: 0
4: 1
5: 1 7
6: 2 8
7: 2 5 8
8: 6 7

Three Iterations:
- Iteration 1:
  Stack: [0]
  Output: 0
  visited = [true, false, false, false, false, false, false, false, false]
  Stack after processing 0: [3, 2, 1]
  visited = [true, true, true, true, false, false, false, false, false]

- Iteration 2:
  Stack: [3, 2, 1]
  Output: 0 1
  Stack after processing 1: [3, 2, 5, 4]
  visited = [true, true, true, true, true, true, false, false, false]

- Iteration 3:
  Stack: [3, 2, 5, 4]
  Output: 0 1 4
  Stack after processing 4: [3, 2, 5]
  visited = [true, true, true, true, true, true, false, false, false]

Dry Run:
1. Initial setup and input:
   - size = 10
   - adj = [[1, 2, 3], [0, 4, 5], [0, 6, 7], [0, 8, 9], [1, 6], [1, 7], [2, 4, 8], [2, 5, 9], [3, 6], [3, 7]]
   - visited = [false, false, false, false, false, false, false, false, false, false]

2. Step-by-step execution with intermediate values:
   - Call DFS for node 0:
     - visited = [false, false, false, false, false, false, false, false, false, false]
     - Stack: [0]
     - Pop 0:
       - Output: 0
       - visited = [true, false, false, false, false, false, false, false, false, false]
       - Push nodes: [3, 2, 1]
     - Stack: [3, 2, 1]

   - Pop 1:
     - Output: 0 1
     - visited = [true, true, false, false, false, false, false, false, false, false]
     - Push nodes: [3, 2, 5, 4]
     - Stack: [3, 2, 5, 4]

   - Pop 4:
     - Output: 0 1 4
     - visited = [true, true, false, false, true, false, false, false, false, false]
     - Stack: [3, 2, 5]

   - Pop 5:
     - Output: 0 1 4 5
     - visited = [true, true, false, false, true, true, false, false, false, false]
     - Push nodes: [3, 2, 7]
     - Stack: [3, 2, 7]

   - Continue similar steps for remaining nodes.

3. Final output:
   - 0 1 4 5 7 2 6 8 3 9

Output:
0 1 4 5 7 2 6 8 3 9
*/
