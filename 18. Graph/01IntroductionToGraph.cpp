/*


Directed and Undirected Graphs in C++

Graphs:
- A graph is a data structure consisting of a set of vertices (nodes) and edges (connections between nodes).

1. Directed Graph (Digraph):
- In a directed graph, edges have a direction, going from one vertex to another.
- Represented as G = (V, E) where V is a set of vertices and E is a set of directed edges.
- Example: If there's a directed edge from vertex A to vertex B, it's represented as (A -> B).

Formulas:
- In-degree of a vertex v: Number of edges directed into v.
- Out-degree of a vertex v: Number of edges directed out of v.
- Sum of in-degrees = Sum of out-degrees = Number of edges (|E|).

Properties:
- Asymmetric: If (u -> v) exists, (v -> u) may or may not exist.
- Can contain cycles (a path where the starting and ending vertex is the same).




2. Undirected Graph:
- In an undirected graph, edges do not have a direction.
- Represented as G = (V, E) where V is a set of vertices and E is a set of undirected edges.
- Example: If there's an undirected edge between vertex A and vertex B, it's represented as (A - B).

Formulas:
- Degree of a vertex v: Number of edges connected to v.
- Sum of degrees of all vertices = 2 * Number of edges (2|E|).

Properties:
- Symmetric: If (u - v) exists, (v - u) also exists.
- Can contain cycles and multiple components.

*/



/*


Differences between Trees and Graphs:

1. Trees:
- A tree is a special type of graph with no cycles and is connected.
- A tree with n vertices has exactly (n-1) edges.
- There is exactly one path between any two vertices.
- Example: Binary Tree, AVL Tree.

Properties:
- Connected and acyclic.
- Rooted tree: Has a designated root node and directed edges.

2. Graphs:
- Can be cyclic or acyclic, connected or disconnected.
- No fixed number of edges; can have any number of edges.
- Multiple paths can exist between two vertices.

Formulas and Properties:
- For a connected graph, there exists at least one path between any two vertices.
- In a tree, the number of edges is always (number of vertices - 1).
- A tree is a minimally connected graph.

Difference Summary:
- Trees are a subset of graphs.
- Trees are connected and acyclic, graphs can have cycles and be disconnected.
- In trees, the number of edges is one less than the number of vertices, whereas in graphs, there is no such constraint.

*/
