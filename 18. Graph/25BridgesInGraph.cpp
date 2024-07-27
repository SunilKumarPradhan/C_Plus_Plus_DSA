/*
Bridges in Graphs

- Definition:
  A bridge (or a cut-edge) in a graph is an edge that, when removed, increases the number of connected components of the graph. In other words, it is an edge whose removal disconnects the graph.

- Importance:
  Bridges are crucial in network design and reliability. Identifying bridges helps in understanding critical connections in networks where failure of a single edge can disrupt connectivity.

- Finding Bridges:
  To find bridges in a graph, we can use Depth-First Search (DFS) based algorithms. The key idea is to keep track of the discovery and low values of vertices.

- Key Terminologies:
  1. **Discovery Time (disc)**: The time when a vertex is first visited during the DFS traversal.
  2. **Lowest Time (low)**: The lowest discovery time reachable from a vertex, including its descendants and back edges.

- Algorithm Outline:
  1. Perform DFS traversal of the graph.
  2. Maintain two arrays, `disc[]` and `low[]`, to store the discovery and lowest times of vertices.
  3. For each vertex, check its adjacent vertices:
     - If an adjacent vertex is not visited, recursively perform DFS on it and update the `low` value of the current vertex.
     - If the lowest value reachable from the adjacent vertex is greater than the discovery time of the current vertex, then the edge connecting them is a bridge.
  4. If an adjacent vertex is already visited and is not the parent of the current vertex, update the `low` value of the current vertex to the minimum of its own `low` value and the discovery time of the adjacent vertex.

- Example:
  In a graph with edges:
    1. 0 -- 1
    2. 1 -- 2
    3. 2 -- 0
    4. 1 -- 3

  The edge (1, 3) is a bridge because removing it would disconnect vertex 3 from the rest of the graph.

- Complexity:
  The time complexity of finding bridges using DFS is O(V + E), where V is the number of vertices and E is the number of edges. This is efficient for sparse and dense graphs alike.

Overall, finding bridges helps in identifying critical edges whose failure would impact the connectivity of the graph.
*/
