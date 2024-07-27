#include <bits/stdc++.h>
using namespace std;



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



    
    return 0;
}

/*
Iss function ka naam hai findArticulationPoints aur yeh graph ke saare articulation points find karta hai.

- Function ka logic:
  1. DFS traversal se graph ke har vertex ka discovery time aur lowest discovery time calculate karta hai.
  2. Agar kisi vertex ka low value uske parent ke discovery time se bada ya equal ho, to woh articulation point hai.

Process:
- Pehle, har vertex ka discovery time aur low time initialize kiya jata hai.
- Uske baad, DFS traversal se har vertex aur uske adjacent vertices ko explore kiya jata hai.
- DFS traversal complete hone ke baad articulation points ko print kiya jata hai.

Example:
- Agar graph adjacency list ke roop mein diya gaya hai aur edge list aise hai:
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

then

Graph edges:
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

Dry Run:
1. Initial setup aur input:
  disc = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]
  low = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]
  parentVertex = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]
  articulationPoint = [false, false, false, false, false, false, false, false, false, false]

2. DFS traversal aur intermediate values:
  Starting from vertex 0:
  - disc[0] = low[0] = 1
  - disc[1] = low[1] = 2
  - disc[2] = low[2] = 3
  - disc[4] = low[4] = 4
  - disc[6] = low[6] = 5
  - disc[8] = low[8] = 6
  - disc[3] = low[3] = 7
  - disc[9] = low[9] = 8
  - disc[7] = low[7] = 9
  - disc[5] = low[5] = 10

3. Final output:
  Articulation points: 0 1 2 3 6

Output:
Articulation Points:
0 1 2 3 6
*/






/*
Articulation Points in Graphs

- Definition:
  An articulation point (or cut vertex) in a graph is a vertex that, when removed, increases the number of connected components of the graph. In other words, it is a vertex whose removal disconnects the graph.

- Importance:
  Articulation points are critical for network reliability and robustness. Identifying articulation points helps in understanding which vertices are crucial for maintaining the connectivity of the network.

- Finding Articulation Points:
  To find articulation points in a graph, we use Depth-First Search (DFS) based algorithms. The key idea is to track discovery and low values of vertices and determine the conditions under which a vertex is an articulation point.

- Key Terminologies:
  1. **Discovery Time (disc)**: The time when a vertex is first visited during the DFS traversal.
  2. **Lowest Time (low)**: The lowest discovery time reachable from a vertex, including its descendants and back edges.

- Algorithm Outline:
  1. Perform DFS traversal of the graph.
  2. Maintain arrays, `disc[]` and `low[]`, to store the discovery and lowest times of vertices.
  3. Use a `parent[]` array to keep track of the parent vertices during DFS.
  4. For each vertex:
     - If it is the root of the DFS tree, check if it has more than one child. If yes, it is an articulation point.
     - For non-root vertices, check if there is a child such that no vertex in its subtree has a back edge to one of the ancestors of the current vertex. If this condition is met, the current vertex is an articulation point.
  5. Update the `low` value of a vertex if an adjacent vertex is already visited and is not the parent of the current vertex.

- Example:
  In a graph with vertices and edges:
    1. 0 -- 1
    2. 1 -- 2
    3. 2 -- 0
    4. 1 -- 3
    5. 3 -- 4

  The vertex 1 is an articulation point because removing it would disconnect the graph into two separate components.

- Complexity:
  The time complexity of finding articulation points using DFS is O(V + E), where V is the number of vertices and E is the number of edges. This makes the algorithm efficient for both sparse and dense graphs.

Overall, finding articulation points helps in identifying crucial vertices whose removal would impact the connectivity of the graph.
*/
